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

	private:
		Mntone::Xamcc::DispatcherHelper^ dispatcherHelper_;
		Mntone::Xamcc::DataProcessor processor_;

		static Windows::UI::Xaml::DependencyProperty
			^ ButtonMessageProperty_,
			^ IsButtonEnabledProperty_,
			^ ButtonCommandProperty_,
			^ ButtonAlwaysCanExecuteCommandProperty_,
			^ ViewModelCollectionProperty_;
	};

} } } }