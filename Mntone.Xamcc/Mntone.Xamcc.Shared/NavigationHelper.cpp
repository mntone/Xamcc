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

	GoHomeCommandInternal = ref new Commands::RelayCommand( [this]( Object^ ) { GoHome(); }, [this]( Object^ ) { return CanGoHome(); } );
	GoBackCommandInternal = ref new Commands::RelayCommand( [this]( Object^ ) { GoBack(); }, [this]( Object^ ) { return CanGoBack(); } );
	GoForwardCommandInternal = ref new Commands::RelayCommand( [this]( Object^ ) { GoForward(); }, [this]( Object^ ) { return CanGoForward(); } );
}

void NavigationHelper::Release( Page^ page )
{
	page->Loaded -= loadedEventToken_;
	page->Unloaded -= unloadedEventToken_;
#if WINAPI_FAMILY != WINAPI_FAMILY_PHONE_APP
	page->SizeChanged -= sizeChangedEventToken_;
#endif

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
	auto page = safe_cast<Page^>( sender );
	const auto& bounds = Window::Current->Bounds;
	if( page->ActualHeight == bounds.Height && page->ActualWidth == bounds.Width )
	{
		AddHookToWindow();
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

	auto page = safe_cast<Page^>( sender );
	Release( page );
}

#if WINAPI_FAMILY != WINAPI_FAMILY_PHONE_APP
void NavigationHelper::OnSizeChanged( Object^ sender, SizeChangedEventArgs^ e )
{
	const auto& currentBounds = Window::Current->Bounds;
	if( e->NewSize.Height == currentBounds.Height && e->NewSize.Width == currentBounds.Width )
	{
		if( !navigationShortcutsRegistered_ )
		{
			AddHookToWindow();
		}
	}
	else
	{
		if( navigationShortcutsRegistered_ )
		{
			RemoveHookToWindow();
		}
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
		auto menuKey = ( coreWindow->GetKeyState( VirtualKey::Menu ) & downState ) == downState;
		auto controlKey = ( coreWindow->GetKeyState( VirtualKey::Control ) & downState ) == downState;
		auto shiftKey = ( coreWindow->GetKeyState( VirtualKey::Shift ) & downState ) == downState;
		auto noModifiers = !menuKey && !controlKey && !shiftKey;
		auto onlyAlt = menuKey && !controlKey && !shiftKey;

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

Input::ICommand^ NavigationHelper::GoHomeCommand::get() { return safe_cast<Input::ICommand^>( GetValue( GoHomeCommandProperty_ ) ); }
Commands::RelayCommand^ NavigationHelper::GoHomeCommandInternal::get() { return safe_cast<Commands::RelayCommand^>( GetValue( GoHomeCommandProperty_ ) ); }
void NavigationHelper::GoHomeCommandInternal::set( Commands::RelayCommand^ value) { SetValue( GoHomeCommandProperty_, value ); }
DependencyProperty^ NavigationHelper::GoHomeCommandProperty_
	= DependencyProperty::Register( "GoHomeCommand", Commands::RelayCommand::typeid, NavigationHelper::typeid, nullptr );

Input::ICommand^ NavigationHelper::GoBackCommand::get() { return safe_cast<Input::ICommand^>( GetValue( GoBackCommandProperty_ ) ); }
Commands::RelayCommand^ NavigationHelper::GoBackCommandInternal::get() { return safe_cast<Commands::RelayCommand^>( GetValue( GoBackCommandProperty_ ) ); }
void NavigationHelper::GoBackCommandInternal::set( Commands::RelayCommand^ value ) { SetValue( GoBackCommandProperty_, value ); }
DependencyProperty^ NavigationHelper::GoBackCommandProperty_
	= DependencyProperty::Register( "GoBackCommand", Commands::RelayCommand::typeid, NavigationHelper::typeid, nullptr );

Input::ICommand^ NavigationHelper::GoForwardCommand::get() { return safe_cast<Input::ICommand^>( GetValue( GoForwardCommandProperty_ ) ); }
Commands::RelayCommand^ NavigationHelper::GoForwardCommandInternal::get() { return safe_cast<Commands::RelayCommand^>( GetValue( GoForwardCommandProperty_ ) ); }
void NavigationHelper::GoForwardCommandInternal::set( Commands::RelayCommand^ value ) { SetValue( GoForwardCommandProperty_, value ); }
DependencyProperty^ NavigationHelper::GoForwardCommandProperty_
	= DependencyProperty::Register( "GoForwardCommand", Commands::RelayCommand::typeid, NavigationHelper::typeid, nullptr );