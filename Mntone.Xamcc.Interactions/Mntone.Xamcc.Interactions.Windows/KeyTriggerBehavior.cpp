#include "pch.h"
#include "KeyTriggerBehavior.h"
#include "..\..\packages\CppCxHelper.0.9.4\build\native\include\PropertyPreprocessor.h"
#include "..\..\Mntone.Xamcc\Mntone.Xamcc.Shared\include\DependencyObjectPreprocessor.h"

using namespace Microsoft::Xaml::Interactivity;
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::System;
using namespace Windows::UI::Core;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Input;
using namespace Mntone::Xamcc::Interactions;

KeyTriggerBehavior::KeyTriggerBehavior()
	: keyEventTriggerRegistered_( false )
	, AssociatedObject_( nullptr )
{
	Actions = ref new ::Microsoft::Xaml::Interactivity::ActionCollection();
}

void KeyTriggerBehavior::Attach( DependencyObject^ associatedObject )
{
	auto page = dynamic_cast<Page^>( associatedObject );
	if( page == nullptr )
	{
		throw ref new InvalidArgumentException( "AssociatedObject is not derived from Windows::UI::Xaml::Controls::Page." );
	}

	AssociatedObject_ = page;
	sizeChangedEventToken_ = page->SizeChanged += ref new SizeChangedEventHandler( this, &KeyTriggerBehavior::OnSizeChanged );

	auto rect = Window::Current->Bounds;
	Update( page, Size{ rect.Width, rect.Height } );
}

void KeyTriggerBehavior::Detach()
{
	if( keyEventTriggerRegistered_ )
	{
		RemoveHookToWindow();
	}

	auto page = AssociatedObject_.Resolve<Page>();
	if( page )
	{
		page->SizeChanged -= sizeChangedEventToken_;
		AssociatedObject_ = nullptr;
	}
}

void KeyTriggerBehavior::Invoke()
{
	auto page = AssociatedObject_.Resolve<Page>();
	if( page )
	{
		for( DependencyObject^ actionDependencyObject : Actions )
		{
			auto action = dynamic_cast<IAction^>( actionDependencyObject );
			if( action )
			{
				action->Execute( page, nullptr );
			}
		}
	}
}

void KeyTriggerBehavior::Update( Page^ page, Size size )
{
	if( keyEventTriggerRegistered_ )
	{
		if( page->ActualHeight != size.Height || page->ActualWidth != size.Width )
		{
			RemoveHookToWindow();
		}
	}
	else
	{
		if( page->ActualHeight == size.Height && page->ActualWidth == size.Width )
		{
			AddHookToWindow();
		}
	}
}

void KeyTriggerBehavior::AddHookToWindow()
{
	auto coreWindow = Window::Current->CoreWindow;
	acceleratorKeyEventToken_ = coreWindow->Dispatcher->AcceleratorKeyActivated
		+= ref new TypedEventHandler<CoreDispatcher^, AcceleratorKeyEventArgs^>( this, &KeyTriggerBehavior::OnAcceleratorKeyActivated );

	keyEventTriggerRegistered_ = true;
}

void KeyTriggerBehavior::RemoveHookToWindow()
{
	auto coreWindow = Window::Current->CoreWindow;
	coreWindow->Dispatcher->AcceleratorKeyActivated -= acceleratorKeyEventToken_;

	keyEventTriggerRegistered_ = false;
}

void KeyTriggerBehavior::OnSizeChanged( Object^ sender, SizeChangedEventArgs^ e )
{
	auto page = safe_cast<Page^>( sender );
	Update( page, e->NewSize );
}

void KeyTriggerBehavior::OnAcceleratorKeyActivated( CoreDispatcher^ sender, AcceleratorKeyEventArgs^ e )
{
	if( FiredOn == KeyTriggerFiredOn::KeyDown && ( e->EventType == CoreAcceleratorKeyEventType::SystemKeyDown || e->EventType == CoreAcceleratorKeyEventType::KeyDown )
		|| ( e->EventType == CoreAcceleratorKeyEventType::SystemKeyUp || e->EventType == CoreAcceleratorKeyEventType::KeyUp ) )
	{
		auto virtualKey = e->VirtualKey;
		if( virtualKey == Key )
		{
			auto coreWindow = Window::Current->CoreWindow;
			auto downState = CoreVirtualKeyStates::Down;
			auto controlKey = ( coreWindow->GetKeyState( VirtualKey::Control ) & downState ) == downState;
			auto menuKey = ( coreWindow->GetKeyState( VirtualKey::Menu ) & downState ) == downState;
			auto shiftKey = ( coreWindow->GetKeyState( VirtualKey::Shift ) & downState ) == downState;
			auto leftWindowsKey = ( coreWindow->GetKeyState( VirtualKey::LeftWindows ) & downState ) == downState;
			auto rightWindowsKey = ( coreWindow->GetKeyState( VirtualKey::RightWindows ) & downState ) == downState;
			auto windowsKey = leftWindowsKey || rightWindowsKey;

			auto keyModifiers = KeyModifiers;
			if( ( keyModifiers & VirtualKeyModifiers::Control ) == VirtualKeyModifiers::Control && !controlKey || controlKey )
			{
				return;
			}
			if( ( keyModifiers & VirtualKeyModifiers::Menu ) == VirtualKeyModifiers::Menu && !menuKey || menuKey )
			{
				return;
			}
			if( ( keyModifiers & VirtualKeyModifiers::Shift ) == VirtualKeyModifiers::Shift && !shiftKey || shiftKey )
			{
				return;
			}
			if( ( keyModifiers & VirtualKeyModifiers::Windows ) == VirtualKeyModifiers::Windows && !windowsKey || windowsKey )
			{
				return;
			}
			Invoke();
			e->Handled = true;
		}
	}
}


DependencyObject^ KeyTriggerBehavior::AssociatedObject::get()
{
	return AssociatedObject_.Resolve<Page>();
}

IMPL_DP_GETSET( KeyTriggerBehavior, ::Microsoft::Xaml::Interactivity::ActionCollection, Actions, nullptr )
IMPL_DP_VALUE_GETSET( KeyTriggerBehavior, KeyTriggerFiredOn, FiredOn, PropertyMetadata::Create( KeyTriggerFiredOn::KeyDown ) )
IMPL_DP_VALUE_GETSET( KeyTriggerBehavior, VirtualKeyModifiers, KeyModifiers, PropertyMetadata::Create( VirtualKeyModifiers::None ) )
IMPL_DP_VALUE_GETSET( KeyTriggerBehavior, VirtualKey, Key, PropertyMetadata::Create( VirtualKey::None ) )