#pragma once
#include "KeyTriggerFiredOn.h"

namespace Mntone { namespace Xamcc { namespace Interactions {

	[Windows::Foundation::Metadata::WebHostHidden]
	[Windows::UI::Xaml::Markup::ContentProperty( Name = "Actions" )]
	public ref class KeyTriggerBehavior sealed
		: public ::Windows::UI::Xaml::DependencyObject
		, public ::Microsoft::Xaml::Interactivity::IBehavior
	{
	public:
		KeyTriggerBehavior();

		virtual void Attach( ::Windows::UI::Xaml::DependencyObject^ associatedObject ) sealed;
		virtual void Detach() sealed;

	private:
		void Invoke();
		void Update( ::Windows::UI::Xaml::Controls::Page^ page, ::Windows::Foundation::Size size );
		void Release();

		void AddHookToWindow();
		void RemoveHookToWindow();

		void OnLoaded( ::Platform::Object^ sender, ::Windows::UI::Xaml::RoutedEventArgs^ e );
		void OnUnloaded( ::Platform::Object^ sender, ::Windows::UI::Xaml::RoutedEventArgs^ e );
		void OnSizeChanged( ::Platform::Object ^sender, ::Windows::UI::Xaml::SizeChangedEventArgs^ e );
		void OnAcceleratorKeyActivated( Windows::UI::Core::CoreDispatcher^ sender, Windows::UI::Core::AcceleratorKeyEventArgs^ e );

	public:
		virtual property ::Windows::UI::Xaml::DependencyObject^ AssociatedObject
		{
			virtual ::Windows::UI::Xaml::DependencyObject^ get();
		}

		property ::Microsoft::Xaml::Interactivity::ActionCollection^ Actions
		{
			::Microsoft::Xaml::Interactivity::ActionCollection^ get();
		private:
			void set( ::Microsoft::Xaml::Interactivity::ActionCollection^ value );
		}
		property KeyTriggerFiredOn FiredOn
		{
			KeyTriggerFiredOn get();
			void set( KeyTriggerFiredOn value );
		}
		property ::Windows::System::VirtualKeyModifiers KeyModifiers
		{
			::Windows::System::VirtualKeyModifiers get();
			void set( ::Windows::System::VirtualKeyModifiers value );
		}
		property ::Windows::System::VirtualKey Key
		{
			::Windows::System::VirtualKey get();
			void set( ::Windows::System::VirtualKey value );
		}

		static property ::Windows::UI::Xaml::DependencyProperty^ ActionsProperty
		{
			::Windows::UI::Xaml::DependencyProperty^ get() { return ActionsProperty_; }
		}
		static property ::Windows::UI::Xaml::DependencyProperty^ FiredOnProperty
		{
			::Windows::UI::Xaml::DependencyProperty^ get() { return FiredOnProperty_; }
		}
		static property ::Windows::UI::Xaml::DependencyProperty^ KeyModifiersProperty
		{
			::Windows::UI::Xaml::DependencyProperty^ get() { return KeyModifiersProperty_; }
		}
		static property ::Windows::UI::Xaml::DependencyProperty^ KeyProperty
		{
			::Windows::UI::Xaml::DependencyProperty^ get() { return KeyProperty_; }
		}

	private:
		bool keyEventTriggerRegistered_;
		::Platform::WeakReference AssociatedObject_;
		::Windows::Foundation::EventRegistrationToken loadedEventToken_, unloadedEventToken_, sizeChangedEventToken_, acceleratorKeyEventToken_;

		static ::Windows::UI::Xaml::DependencyProperty
			^ FiredOnProperty_,
			^ KeyProperty_,
			^ KeyModifiersProperty_,
			^ ActionsProperty_;
	};

} } }