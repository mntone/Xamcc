#include "pch.h"
#include "WindowTitleBehavior.h"
#include "..\..\packages\CppCxHelper.0.9.4\build\native\include\PropertyPreprocessor.h"
#include "..\..\Mntone.Xamcc\Mntone.Xamcc.Shared\include\DependencyObjectPreprocessor.h"

using namespace Platform;
using namespace Windows::UI::ViewManagement;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Mntone::Xamcc::Interactions;

WindowTitleBehavior::WindowTitleBehavior()
{ }

void WindowTitleBehavior::Attach( DependencyObject^ associatedObject )
{
	auto page = dynamic_cast<Page^>( associatedObject );
	if( page == nullptr )
	{
		throw ref new InvalidArgumentException( "AssociatedObject is not derived from Windows::UI::Xaml::Controls::Page." );
	}

	AssociatedObject_ = page;
	unloadedEventToken_ = page->Unloaded += ref new RoutedEventHandler( this, &WindowTitleBehavior::OnUnloaded );

	Update();
}

void WindowTitleBehavior::Detach()
{
	Release();
}

void WindowTitleBehavior::Release()
{
	auto page = AssociatedObject_.Resolve<Page>();
	if( page )
	{
		page->Unloaded -= unloadedEventToken_;
		AssociatedObject_ = nullptr;

		if( IsEnabled )
		{
			IsEnabled = false;
		}
	}
}

void WindowTitleBehavior::OnUnloaded( Object^ sender, RoutedEventArgs^ e )
{
	Release();
}

void WindowTitleBehavior::Update()
{
	Update( Title );
}

void WindowTitleBehavior::Update( String^ value )
{
	ApplicationView::GetForCurrentView()->Title = IsEnabled ? value : "";
}

void WindowTitleBehavior::OnIsEnabledChanged( DependencyObject^ d, DependencyPropertyChangedEventArgs^ e )
{
	auto that = safe_cast<WindowTitleBehavior^>( d );
	auto oldValue = safe_cast<IBox<bool>^>( e->OldValue );
	auto newValue = safe_cast<IBox<bool>^>( e->NewValue );
	if( oldValue && newValue )
	{
		if( oldValue->Value && !newValue->Value )
		{
			that->Update();
		}
		else if( !oldValue->Value && newValue->Value )
		{
			that->Update();
		}
	}
	that->IsEnabledChanged( d, e );
}

void WindowTitleBehavior::OnTitleChanged( DependencyObject^ d, DependencyPropertyChangedEventArgs^ e )
{
	auto that = safe_cast<WindowTitleBehavior^>( d );
	auto oldValue = dynamic_cast<String^>( e->OldValue );
	auto newValue = dynamic_cast<String^>( e->NewValue );
	if( oldValue != newValue )
	{
		that->Update( newValue );
	}
}


DependencyObject^ WindowTitleBehavior::AssociatedObject::get()
{
	return AssociatedObject_.Resolve<Page>();
}

IMPL_DP_VALUE_GETSET( WindowTitleBehavior, bool, IsEnabled,
	PropertyMetadata::Create( false, ref new PropertyChangedCallback( &WindowTitleBehavior::OnIsEnabledChanged ) ) )
IMPL_DP_GETSET( WindowTitleBehavior, String, Title,
	PropertyMetadata::Create( "", ref new PropertyChangedCallback( &WindowTitleBehavior::OnTitleChanged ) ) )