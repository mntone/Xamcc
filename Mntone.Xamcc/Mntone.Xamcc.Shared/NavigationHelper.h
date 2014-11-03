#pragma once
#include "include/Commands/RelayCommand.h"

namespace Mntone { namespace Xamcc {

	[Windows::UI::Xaml::Data::Bindable]
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class NavigationHelper sealed
		: public Windows::UI::Xaml::DependencyObject
	{
	public:
		[Windows::Foundation::Metadata::Overload( "CreateInstance" )]
		NavigationHelper( Windows::UI::Xaml::Controls::Page^ page );

		bool CanGoHome();
		bool GoHome();

		bool CanGoBack();
		bool GoBack();

		bool CanGoForward();
		bool GoForward();

	private:
		void Release( Windows::UI::Xaml::Controls::Page^ page );

#if WINAPI_FAMILY != WINAPI_FAMILY_PHONE_APP
		void AddHookToWindow();
		void RemoveHookToWindow();
#endif

		void OnLoaded( Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e );
		void OnUnloaded( Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e );
		void OnSizeChanged( Platform::Object ^sender, Windows::UI::Xaml::SizeChangedEventArgs^ e );

#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP

		void OnHardwareButtonBackPressed( Platform::Object^ sender, Windows::Phone::UI::Input::BackPressedEventArgs^ e );
#else
		void OnAcceleratorKeyActivated( Windows::UI::Core::CoreDispatcher^ sender, Windows::UI::Core::AcceleratorKeyEventArgs^ e );
		void OnPointerPressed( Windows::UI::Core::CoreWindow^ sender, Windows::UI::Core::PointerEventArgs^ e );
#endif

	public:
		property ::Windows::UI::Xaml::Input::ICommand^ GoHomeCommand
		{
			::Windows::UI::Xaml::Input::ICommand^ get();
		}
		property ::Windows::UI::Xaml::Input::ICommand^ GoBackCommand
		{
			::Windows::UI::Xaml::Input::ICommand^ get();
		}
		property ::Windows::UI::Xaml::Input::ICommand^ GoForwardCommand
		{
			::Windows::UI::Xaml::Input::ICommand^ get();
		}

	internal:
		property Mntone::Xamcc::Commands::RelayCommand^ GoHomeCommandInternal
		{
			Mntone::Xamcc::Commands::RelayCommand^ get();
			void set( Mntone::Xamcc::Commands::RelayCommand^ value );
		}
		property Mntone::Xamcc::Commands::RelayCommand^ GoBackCommandInternal
		{
			Mntone::Xamcc::Commands::RelayCommand^ get();
			void set( Mntone::Xamcc::Commands::RelayCommand^ value );
		}
		property Mntone::Xamcc::Commands::RelayCommand^ GoForwardCommandInternal
		{
			Mntone::Xamcc::Commands::RelayCommand^ get();
			void set( Mntone::Xamcc::Commands::RelayCommand^ value );
		}

	private:
		Platform::WeakReference page_;

		Windows::Foundation::EventRegistrationToken loadedEventToken_, unloadedEventToken_;
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
		Windows::Foundation::EventRegistrationToken backPressedEventToken_;
#else
		Windows::Foundation::EventRegistrationToken sizeChangedEventToken_;

		bool navigationShortcutsRegistered_;
		Windows::Foundation::EventRegistrationToken acceleratorKeyEventToken_, pointerPressedEventToken_;
#endif

		static Windows::UI::Xaml::DependencyProperty
			^ GoHomeCommandProperty_,
			^ GoBackCommandProperty_,
			^ GoForwardCommandProperty_;
	};

} }