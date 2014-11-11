#include "pch.h"
#include "ProgressIndicatorBehavior.h"
#include "..\..\packages\CppCxHelper.0.9.4\build\native\include\PropertyPreprocessor.h"
#include "..\..\Mntone.Xamcc\Mntone.Xamcc.Shared\include\DependencyObjectPreprocessor.h"

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::UI::ViewManagement;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Mntone::Xamcc::Interactions;

ProgressIndicatorBehavior::ProgressIndicatorBehavior()
{ }

void ProgressIndicatorBehavior::Attach( DependencyObject^ associatedObject )
{
	auto page = dynamic_cast<Page^>( associatedObject );
	if( page == nullptr )
	{
		throw ref new InvalidArgumentException( "AssociatedObject is not derived from Windows::UI::Xaml::Controls::Page." );
	}

	AssociatedObject_ = page;

	if( IsEnabled )
	{
		auto progressIndicator = StatusBar::GetForCurrentView()->ProgressIndicator;
		if( !IsIndeterminate )
		{
			progressIndicator->ProgressValue = ref new Box<float64>( ( Value - Minimum ) / ( Maximum - Minimum ) );
		}
		auto t = Text;
		progressIndicator->Text = Text;
		progressIndicator->ShowAsync();
	}
}

void ProgressIndicatorBehavior::Detach()
{
	AssociatedObject_ = nullptr;
}

IAsyncAction^ ProgressIndicatorBehavior::ShowAsync()
{
	auto progressIndicator = StatusBar::GetForCurrentView()->ProgressIndicator;
	return progressIndicator->ShowAsync();
}

IAsyncAction^ ProgressIndicatorBehavior::HideAsync()
{
	auto progressIndicator = StatusBar::GetForCurrentView()->ProgressIndicator;
	return progressIndicator->HideAsync();
}

void ProgressIndicatorBehavior::UpdateText( String^ value )
{
	auto progressIndicator = StatusBar::GetForCurrentView()->ProgressIndicator;
	progressIndicator->Text = value;
}

void ProgressIndicatorBehavior::UpdateProgress()
{
	UpdateProgress( Value );
}

void ProgressIndicatorBehavior::UpdateProgress( float64 value )
{
	auto progressIndicator = StatusBar::GetForCurrentView()->ProgressIndicator;
	if( !IsIndeterminate )
	{
		progressIndicator->ProgressValue = ref new Box<float64>( ( value - Minimum ) / ( Maximum - Minimum ) );
	}
	else
	{
		progressIndicator->ProgressValue = nullptr;
	}
}

void ProgressIndicatorBehavior::OnIsEnabledChanged( DependencyObject^ d, DependencyPropertyChangedEventArgs^ e )
{
	auto that = safe_cast<ProgressIndicatorBehavior^>( d );
	auto oldValue = safe_cast<IBox<bool>^>( e->OldValue );
	auto newValue = safe_cast<IBox<bool>^>( e->NewValue );
	if( oldValue && newValue )
	{
		if( oldValue->Value && !newValue->Value )
		{
			that->HideAsync();
		}
		else if( !oldValue->Value && newValue->Value )
		{
			that->ShowAsync();
		}
	}
	that->IsEnabledChanged( d, e );
}

void ProgressIndicatorBehavior::OnIsIndeterminateChanged( DependencyObject^ d, DependencyPropertyChangedEventArgs^ e )
{
	auto that = safe_cast<ProgressIndicatorBehavior^>( d );
	auto oldValue = safe_cast<IBox<bool>^>( e->OldValue );
	auto newValue = safe_cast<IBox<bool>^>( e->NewValue );
	if( oldValue && newValue && oldValue->Value != newValue->Value )
	{
		that->UpdateProgress();
	}
}

void ProgressIndicatorBehavior::OnTextChanged( DependencyObject^ d, DependencyPropertyChangedEventArgs^ e )
{
	auto that = safe_cast<ProgressIndicatorBehavior^>( d );
	auto oldValue = dynamic_cast<String^>( e->OldValue );
	auto newValue = dynamic_cast<String^>( e->NewValue );
	if( oldValue != newValue )
	{
		that->UpdateText( newValue );
	}
}

void ProgressIndicatorBehavior::OnMinimumChanged( DependencyObject^ d, DependencyPropertyChangedEventArgs^ e )
{
	auto that = safe_cast<ProgressIndicatorBehavior^>( d );
	auto oldValue = dynamic_cast<IBox<float64>^>( e->OldValue );
	auto newValue = dynamic_cast<IBox<float64>^>( e->NewValue );
	if( oldValue && newValue && oldValue->Value != newValue->Value )
	{
		that->UpdateProgress();
	}
}

void ProgressIndicatorBehavior::OnMaximumChanged( DependencyObject^ d, DependencyPropertyChangedEventArgs^ e )
{
	auto that = safe_cast<ProgressIndicatorBehavior^>( d );
	auto oldValue = dynamic_cast<IBox<float64>^>( e->OldValue );
	auto newValue = dynamic_cast<IBox<float64>^>( e->NewValue );
	if( oldValue && newValue && oldValue->Value != newValue->Value )
	{
		that->UpdateProgress();
	}
}

void ProgressIndicatorBehavior::OnValueChanged( DependencyObject^ d, DependencyPropertyChangedEventArgs^ e )
{
	auto that = safe_cast<ProgressIndicatorBehavior^>( d );
	auto oldValue = dynamic_cast<IBox<float64>^>( e->OldValue );
	auto newValue = dynamic_cast<IBox<float64>^>( e->NewValue );
	if( oldValue && newValue && oldValue->Value != newValue->Value )
	{
		that->UpdateProgress( newValue->Value );
	}
}


DependencyObject^ ProgressIndicatorBehavior::AssociatedObject::get()
{
	return AssociatedObject_.Resolve<Page>();
}

IMPL_DP_VALUE_GETSET( ProgressIndicatorBehavior, bool, IsEnabled,
	PropertyMetadata::Create( false, ref new PropertyChangedCallback( &ProgressIndicatorBehavior::OnIsEnabledChanged ) ) )
IMPL_DP_VALUE_GETSET( ProgressIndicatorBehavior, bool, IsIndeterminate,
	PropertyMetadata::Create( true, ref new PropertyChangedCallback( &ProgressIndicatorBehavior::OnIsIndeterminateChanged ) ) )
IMPL_DP_GETSET( ProgressIndicatorBehavior, String, Text,
	PropertyMetadata::Create( "", ref new PropertyChangedCallback( &ProgressIndicatorBehavior::OnTextChanged ) ) )
IMPL_DP_VALUE_GETSET( ProgressIndicatorBehavior, double, Minimum,
	PropertyMetadata::Create( 0., ref new PropertyChangedCallback( &ProgressIndicatorBehavior::OnMinimumChanged ) ) )
IMPL_DP_VALUE_GETSET( ProgressIndicatorBehavior, double, Maximum,
	PropertyMetadata::Create( 1., ref new PropertyChangedCallback( &ProgressIndicatorBehavior::OnMaximumChanged ) ) )
IMPL_DP_VALUE_GETSET( ProgressIndicatorBehavior, double, Value,
	PropertyMetadata::Create( 0., ref new PropertyChangedCallback( &ProgressIndicatorBehavior::OnValueChanged ) ) )