#include "pch.h"
#include "NavigationHelper.h"
#include "include\DependencyObjectPreprocessor.h"

using namespace Platform;
using namespace Platform::Collections;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Core;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Input;
using namespace Mntone::Xamcc;

#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
using namespace Windows::Phone::UI::Input;
#endif

NavigationHelper::NavigationHelper( Page^ page )
	: page_( page )
#if WINAPI_FAMILY != WINAPI_FAMILY_PHONE_APP
	, navigationShortcutsRegistered_( false )
#endif
{
	loadedEventToken_ = page->Loaded += ref new RoutedEventHandler( this, &NavigationHelper::OnLoaded );
	unloadedEventToken_ = page->Unloaded += ref new RoutedEventHandler( this, &NavigationHelper::OnUnloaded );
#if WINAPI_FAMILY != WINAPI_FAMILY_PHONE_APP
	sizeChangedEventToken_ = page->SizeChanged += ref new SizeChangedEventHandler( this, &NavigationHelper::OnSizeChanged );
#endif

	GoHomeCommand = ref new Commands::RelayCommand( [this]( Object^ ) { GoHome(); }, [this]( Object^ ) { return CanGoHome(); } );
	GoBackCommand = ref new Commands::RelayCommand( [this]( Object^ ) { GoBack(); }, [this]( Object^ ) { return CanGoBack(); } );
	GoForwardCommand = ref new Commands::RelayCommand( [this]( Object^ ) { GoForward(); }, [this]( Object^ ) { return CanGoForward(); } );
}

void NavigationHelper::Release()
{
	auto page = page_.Resolve<Page>();
	if( page != nullptr )
	{
		page->Loaded -= loadedEventToken_;
		page->Unloaded -= unloadedEventToken_;
#if WINAPI_FAMILY != WINAPI_FAMILY_PHONE_APP
		page->SizeChanged -= sizeChangedEventToken_;
#endif
	}

	page_ = nullptr;
}

#if WINAPI_FAMILY != WINAPI_FAMILY_PHONE_APP
void NavigationHelper::AddHookToWindow()
{
	auto coreWindow = Window::Current->CoreWindow;
	acceleratorKeyEventToken_ = coreWindow->Dispatcher->AcceleratorKeyActivated
		+= ref new TypedEventHandler<CoreDispatcher^, AcceleratorKeyEventArgs^>( this, &NavigationHelper::OnAcceleratorKeyActivated );
	pointerPressedEventToken_ = coreWindow->PointerPressed
		+= ref new TypedEventHandler<CoreWindow^, PointerEventArgs^>( this, &NavigationHelper::OnPointerPressed );

	navigationShortcutsRegistered_ = true;
}

void NavigationHelper::RemoveHookToWindow()
{
	auto coreWindow = Window::Current->CoreWindow;
	coreWindow->Dispatcher->AcceleratorKeyActivated -= acceleratorKeyEventToken_;
	coreWindow->PointerPressed -= pointerPressedEventToken_;

	navigationShortcutsRegistered_ = false;
}
#endif

void NavigationHelper::OnLoaded( Object^ sender, RoutedEventArgs^ e )
{
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
	backPressedEventToken_ = HardwareButtons::BackPressed
		+= ref new EventHandler<BackPressedEventArgs^>( this, &NavigationHelper::OnHardwareButtonBackPressed );
#else
	auto page = page_.Resolve<Page>();
	if( page != nullptr )
	{
		const auto& currentBounds = Window::Current->Bounds;
		if( page->ActualHeight == currentBounds.Height && page->ActualWidth == currentBounds.Width )
		{
			AddHookToWindow();
		}
	}
#endif
}

void NavigationHelper::OnUnloaded( Object^ sender, RoutedEventArgs^ e )
{
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
	HardwareButtons::BackPressed -= backPressedEventToken_;
#else
	if( navigationShortcutsRegistered_ )
	{
		RemoveHookToWindow();
	}
#endif

	Release();
}

#if WINAPI_FAMILY != WINAPI_FAMILY_PHONE_APP
void NavigationHelper::OnSizeChanged( Object^ sender, SizeChangedEventArgs^ e )
{
	auto page = page_.Resolve<Page>();
	if( page != nullptr )
	{
		const auto& currentBounds = Window::Current->Bounds;
		if( page->ActualHeight == currentBounds.Height && page->ActualWidth == currentBounds.Width && !navigationShortcutsRegistered_ )
		{
			AddHookToWindow();
		}
	}
	else if( navigationShortcutsRegistered_ )
	{
		RemoveHookToWindow();
	}
}
#endif

#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
void NavigationHelper::OnHardwareButtonBackPressed( Object^ sender, BackPressedEventArgs^ e )
{
	e->Handled = GoBack();
}
#else
void NavigationHelper::OnAcceleratorKeyActivated( CoreDispatcher^ /*sender*/, AcceleratorKeyEventArgs^ e )
{
	using namespace Windows::System;

	auto virtualKey = e->VirtualKey;
	if( ( e->EventType == CoreAcceleratorKeyEventType::SystemKeyDown || e->EventType == CoreAcceleratorKeyEventType::KeyDown )
		&& ( virtualKey == VirtualKey::Left || virtualKey == VirtualKey::Right
		|| virtualKey == VirtualKey::GoBack || virtualKey == VirtualKey::GoForward || virtualKey == VirtualKey::GoHome ) )
	{
		auto coreWindow = Window::Current->CoreWindow;
		auto downState = CoreVirtualKeyStates::Down;
		bool menuKey = ( coreWindow->GetKeyState( VirtualKey::Menu ) & downState ) == downState;
		bool controlKey = ( coreWindow->GetKeyState( VirtualKey::Control ) & downState ) == downState;
		bool shiftKey = ( coreWindow->GetKeyState( VirtualKey::Shift ) & downState ) == downState;
		bool noModifiers = !menuKey && !controlKey && !shiftKey;
		bool onlyAlt = menuKey && !controlKey && !shiftKey;

		if( virtualKey == VirtualKey::GoBack && noModifiers || virtualKey == VirtualKey::Left && onlyAlt )
		{
			e->Handled = GoBack();
		}
		else if( virtualKey == VirtualKey::GoForward && noModifiers || virtualKey == VirtualKey::Right && onlyAlt )
		{
			e->Handled = GoForward();
		}
		else if( virtualKey == VirtualKey::GoHome && noModifiers )
		{
			e->Handled = GoHome();
		}
	}
}

void NavigationHelper::OnPointerPressed( CoreWindow^ sender, PointerEventArgs^ e )
{
	auto properties = e->CurrentPoint->Properties;
	bool backPressed = properties->IsXButton1Pressed;
	bool forwardPressed = properties->IsXButton2Pressed;
	if( backPressed ^ forwardPressed )
	{
		if( backPressed )
		{
			e->Handled = GoBack();
		}
		else
		{
			e->Handled = GoForward();
		}
	}
}
#endif


#pragma region Navigation support

bool NavigationHelper::CanGoHome()
{
	auto page = page_.Resolve<Page>();
	if( page != nullptr )
	{
		auto frame = page->Frame;
		return frame != nullptr && frame->CanGoBack;
	}
	return false;
}

bool NavigationHelper::GoHome()
{
	auto page = page_.Resolve<Page>();
	if( page != nullptr )
	{
		auto frame = page->Frame;
		if( frame != nullptr )
		{
			auto depth = frame->BackStackDepth;
			if( depth-- != 0 )
			{
				do
				{
					frame->GoBack();
				} while( depth-- != 0 );
				return true;
			}
		}
	}
	return false;
}

bool NavigationHelper::CanGoBack()
{
	auto page = page_.Resolve<Page>();
	if( page != nullptr )
	{
		auto frame = page->Frame;
		return frame != nullptr && frame->CanGoBack;
	}
	return false;
}

bool NavigationHelper::GoBack()
{
	auto page = page_.Resolve<Page>();
	if( page != nullptr )
	{
		auto frame = page->Frame;
		if( frame != nullptr && frame->CanGoBack )
		{
			frame->GoBack();
			return true;
		}
	}
	return false;
}

bool NavigationHelper::CanGoForward()
{
	auto page = page_.Resolve<Page>();
	if( page != nullptr )
	{
		auto frame = page->Frame;
		return frame != nullptr && frame->CanGoForward;
	}
	return false;
}

bool NavigationHelper::GoForward()
{
	auto page = page_.Resolve<Page>();
	if( page != nullptr )
	{
		auto frame = page->Frame;
		if( frame != nullptr && frame->CanGoForward )
		{
			frame->GoForward();
			return true;
		}
	}
	return false;
}

#pragma endregion


IMPL_DP_GETSET( NavigationHelper, Commands::RelayCommand, GoHomeCommand, nullptr )
IMPL_DP_GETSET( NavigationHelper, Commands::RelayCommand, GoBackCommand, nullptr )
IMPL_DP_GETSET( NavigationHelper, Commands::RelayCommand, GoForwardCommand, nullptr )