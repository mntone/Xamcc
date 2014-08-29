#pragma once

namespace Mntone { namespace Xamcc {

	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class PageSizeStateHelper sealed
	{
	public:
		[Windows::Foundation::Metadata::Overload( "CreateInstance" )]
		PageSizeStateHelper( Windows::UI::Xaml::Controls::Page^ page );

		[Windows::Foundation::Metadata::Overload( "CreateInstanceWithWidthThreshold" )]
		PageSizeStateHelper( Windows::UI::Xaml::Controls::Page^ page, float32 widthThreshold );

		[Windows::Foundation::Metadata::Overload( "CreateInstanceWithBothWidthThresholds" )]
		PageSizeStateHelper(
			Windows::UI::Xaml::Controls::Page^ page,
			float32 widthThresholdBetweenCompactAndMiddle,
			float32 widthThresholdBetweenMiddleAndFull );
		
	private:
		void OnUnloaded( Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e );
		void OnSizeChanged( Platform::Object^ sender, Windows::UI::Xaml::SizeChangedEventArgs^ e );

	public:
		property Platform::String^ PageSizeVisualStateGroupName
		{
			Platform::String^ get();
			void set( Platform::String^ value );
		}

		property Platform::String^ PageSizeCompactVisualStateName
		{
			Platform::String^ get();
			void set( Platform::String^ value );
		}
		property Platform::String^ PageSizeMiddleVisualStateName
		{
			Platform::String^ get();
			void set( Platform::String^ value );
		}
		property Platform::String^ PageSizeFullVisualStateName
		{
			Platform::String^ get();
			void set( Platform::String^ value );
		}

		property float32 WidthThresholdBetweenCompactAndMiddle
		{
			float32 get();
			void set( float32 value );
		}
		property float32 WidthThresholdBetweenMiddleAndFull
		{
			float32 get();
			void set( float32 value );
		}

	private:
		Windows::Foundation::EventRegistrationToken unloadedEventToken_, sizeChangedEventToken_;

		float32 WidthThresholdBetweenCompactAndMiddle_, WidthThresholdBetweenMiddleAndFull_;
		Platform::String
			^ PageSizeVisualStateGroupName_,
			^ PageSizeCompactVisualStateName_,
			^ PageSizeMiddleVisualStateName_,
			^ PageSizeFullVisualStateName_;
	};

} }