#pragma once

namespace Mntone { namespace Xamcc { namespace Interactions {

	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class WindowTitleBehavior sealed
		: public ::Windows::UI::Xaml::DependencyObject
		, public ::Microsoft::Xaml::Interactivity::IBehavior
	{
	public:
		WindowTitleBehavior();

		virtual void Attach( ::Windows::UI::Xaml::DependencyObject^ associatedObject ) sealed;
		virtual void Detach() sealed;

	private:
		void Release();
		void OnUnloaded( ::Platform::Object^ sender, ::Windows::UI::Xaml::RoutedEventArgs^ e );

		void Update();
		void Update( ::Platform::String^ value );

		static void OnIsEnabledChanged( ::Windows::UI::Xaml::DependencyObject^ d, ::Windows::UI::Xaml::DependencyPropertyChangedEventArgs^ e );
		static void OnTitleChanged( ::Windows::UI::Xaml::DependencyObject^ d, ::Windows::UI::Xaml::DependencyPropertyChangedEventArgs^ e );

	public:
		event Windows::UI::Xaml::DependencyPropertyChangedEventHandler^ IsEnabledChanged;

	public:
		virtual property ::Windows::UI::Xaml::DependencyObject^ AssociatedObject
		{
			virtual ::Windows::UI::Xaml::DependencyObject^ get();
		}

		property bool IsEnabled
		{
			bool get();
			void set( bool value );
		}
		property ::Platform::String^ Title
		{
			::Platform::String^ get();
			void set( ::Platform::String^ value );
		}

		static property ::Windows::UI::Xaml::DependencyProperty^ IsEnabledProperty
		{
			::Windows::UI::Xaml::DependencyProperty^ get() { return IsEnabledProperty_; }
		}
		static property ::Windows::UI::Xaml::DependencyProperty^ TitleProperty
		{
			::Windows::UI::Xaml::DependencyProperty^ get() { return TitleProperty_; }
		}

	private:
		::Windows::UI::Xaml::Controls::Page^ AssociatedObject_;
		::Windows::Foundation::EventRegistrationToken unloadedEventToken_;

		static ::Windows::UI::Xaml::DependencyProperty
			^ IsEnabledProperty_,
			^ TitleProperty_;
	};

} } }