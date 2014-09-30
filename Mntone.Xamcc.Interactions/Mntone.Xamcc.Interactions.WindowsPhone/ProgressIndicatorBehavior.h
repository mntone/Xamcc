#pragma once

namespace Mntone { namespace Xamcc { namespace Interactions {

	public ref class ProgressIndicatorBehavior sealed
		: public ::Windows::UI::Xaml::DependencyObject
		, public ::Microsoft::Xaml::Interactivity::IBehavior
	{
	public:
		ProgressIndicatorBehavior();

		virtual void Attach( ::Windows::UI::Xaml::DependencyObject^ associatedObject ) sealed;
		virtual void Detach() sealed;

		::Windows::Foundation::IAsyncAction^ ShowAsync();
		::Windows::Foundation::IAsyncAction^ HideAsync();

	private:
		void Release();
		void OnUnloaded( ::Platform::Object^ sender, ::Windows::UI::Xaml::RoutedEventArgs^ e );

		void UpdateText( ::Platform::String^ value );

		void UpdateProgress();
		void UpdateProgress( float64 value );

		static void OnIsEnabledChanged( ::Windows::UI::Xaml::DependencyObject^ d, ::Windows::UI::Xaml::DependencyPropertyChangedEventArgs^ e );
		static void OnIsIndeterminateChanged( ::Windows::UI::Xaml::DependencyObject^ d, ::Windows::UI::Xaml::DependencyPropertyChangedEventArgs^ e );
		static void OnTextChanged( ::Windows::UI::Xaml::DependencyObject^ d, ::Windows::UI::Xaml::DependencyPropertyChangedEventArgs^ e );
		static void OnMinimumChanged( ::Windows::UI::Xaml::DependencyObject^ d, ::Windows::UI::Xaml::DependencyPropertyChangedEventArgs^ e );
		static void OnMaximumChanged( ::Windows::UI::Xaml::DependencyObject^ d, ::Windows::UI::Xaml::DependencyPropertyChangedEventArgs^ e );
		static void OnValueChanged( ::Windows::UI::Xaml::DependencyObject^ d, ::Windows::UI::Xaml::DependencyPropertyChangedEventArgs^ e );

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
		property bool IsIndeterminate
		{
			bool get();
			void set( bool value );
		}
		property ::Platform::String^ Text
		{
			::Platform::String^ get();
			void set( ::Platform::String^ value );
		}
		property float64 Minimum
		{
			float64 get();
			void set( float64 value );
		}
		property float64 Maximum
		{
			float64 get();
			void set( float64 value );
		}
		property float64 Value
		{
			float64 get();
			void set( float64 value );
		}

		static property ::Windows::UI::Xaml::DependencyProperty^ TextProperty
		{
			::Windows::UI::Xaml::DependencyProperty^ get() { return TextProperty_; }
		}
		static property ::Windows::UI::Xaml::DependencyProperty^ IsEnabledProperty
		{
			::Windows::UI::Xaml::DependencyProperty^ get() { return IsEnabledProperty_; }
		}
		static property ::Windows::UI::Xaml::DependencyProperty^  IsIndeterminateProperty
		{
			::Windows::UI::Xaml::DependencyProperty^ get() { return  IsIndeterminateProperty_; }
		}
		static property ::Windows::UI::Xaml::DependencyProperty^ MinimumProperty
		{
			::Windows::UI::Xaml::DependencyProperty^ get() { return MinimumProperty_; }
		}
		static property ::Windows::UI::Xaml::DependencyProperty^ MaximumProperty
		{
			::Windows::UI::Xaml::DependencyProperty^ get() { return MaximumProperty_; }
		}
		static property ::Windows::UI::Xaml::DependencyProperty^ ValueProperty
		{
			::Windows::UI::Xaml::DependencyProperty^ get() { return ValueProperty_; }
		}

	private:
		::Windows::UI::Xaml::Controls::Page^ AssociatedObject_;
		::Windows::Foundation::EventRegistrationToken unloadedEventToken_;

		static ::Windows::UI::Xaml::DependencyProperty
			^ TextProperty_,
			^ IsEnabledProperty_,
			^ IsIndeterminateProperty_,
			^ MinimumProperty_,
			^ MaximumProperty_,
			^ ValueProperty_;
};

} } }