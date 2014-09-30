#pragma once
#include "Core\DataProcessor.h"

namespace Mntone { namespace Xamcc { namespace DemoApp { namespace ViewModels {

	[Windows::UI::Xaml::Data::Bindable]
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class MainPageViewModel
		: public Windows::UI::Xaml::DependencyObject
	{
	internal:
		MainPageViewModel( Windows::UI::Core::CoreDispatcher^ dispatcher );

	private:
		static void OnIsButtonEnabledPropertyChanged( Windows::UI::Xaml::DependencyObject^ d, Windows::UI::Xaml::DependencyPropertyChangedEventArgs^ e );

	internal:
		property Platform::String^ ButtonMessage
		{
			Platform::String^ get();
			void set( Platform::String^ value );
		}
		property bool IsButtonEnabled
		{
			bool get();
			void set( bool value );
		}
		property Mntone::Xamcc::Commands::RelayCommand^ ButtonCommand
		{
			Mntone::Xamcc::Commands::RelayCommand^ get();
			void set( Mntone::Xamcc::Commands::RelayCommand^ value );
		}
		property Mntone::Xamcc::Commands::RelayCommand^ ButtonAlwaysCanExecuteCommand
		{
			Mntone::Xamcc::Commands::RelayCommand^ get();
			void set( Mntone::Xamcc::Commands::RelayCommand^ value );
		}

		property Platform::Collections::Vector<Platform::String^>^ ViewModelCollection
		{
			Platform::Collections::Vector<Platform::String^>^ get();
			void set( Platform::Collections::Vector<Platform::String^>^ value );
		}
		property Platform::Collections::Deque<Platform::String^>^ ViewModelCollection2
		{
			Platform::Collections::Deque<Platform::String^>^ get();
			void set( Platform::Collections::Deque<Platform::String^>^ value );
		}

#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
		property bool IsIndicatorEnabled
		{
			bool get();
			void set( bool value );
		}
		property bool IsIndicatorIndeterminate
		{
			bool get();
			void set( bool value );
		}
		property ::Platform::String^ IndicatorMessage
		{
			::Platform::String^ get();
			void set( ::Platform::String^ value );
		}
		property float32 IndicatorMinValue
		{
			float32 get();
			void set( float32 value );
		}
		property float32 IndicatorMaxValue
		{
			float32 get();
			void set( float32 value );
		}
		property float32 IndicatorCurrentValue
		{
			float32 get();
			void set( float32 value );
		}
#endif

	private:
		Mntone::Xamcc::DispatcherHelper^ dispatcherHelper_;
		Mntone::Xamcc::DataProcessor processor_;

		static Windows::UI::Xaml::DependencyProperty
			^ ButtonMessageProperty_,
			^ IsButtonEnabledProperty_,
			^ ButtonCommandProperty_,
			^ ButtonAlwaysCanExecuteCommandProperty_,
			^ ViewModelCollectionProperty_,
			^ ViewModelCollection2Property_;

#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
		static Windows::UI::Xaml::DependencyProperty
			^ IsIndicatorEnabledProperty_,
			^ IsIndicatorIndeterminateProperty_,
			^ IndicatorMessageProperty_,
			^ IndicatorMinValueProperty_,
			^ IndicatorMaxValueProperty_,
			^ IndicatorCurrentValueProperty_;
#endif
	};

} } } }