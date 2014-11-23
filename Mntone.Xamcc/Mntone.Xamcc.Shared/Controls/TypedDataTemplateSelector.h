#pragma once

namespace Mntone { namespace Xamcc { namespace Controls {

	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class TypedDataTemplateSelector sealed
		: ::Windows::UI::Xaml::Controls::DataTemplateSelector
	{
	public:
		TypedDataTemplateSelector();

	protected:
		virtual ::Windows::UI::Xaml::DataTemplate^ SelectTemplateCore( ::Platform::Object^ item, ::Windows::UI::Xaml::DependencyObject^ container ) override sealed;

	private:
		::Windows::UI::Xaml::DataTemplate^ FindTemplate( ::Platform::Object^ item, ::Platform::String^ targetKey, ::Windows::UI::Xaml::DependencyObject^ container );
		::Windows::UI::Xaml::DataTemplate^ FindTemplate( ::Windows::UI::Xaml::ResourceDictionary^ resourceDictionary, ::Platform::String^ key );

		::Windows::UI::Xaml::DataTemplate^ FindCachingTemplate( ::Platform::String^ key );

	public:
		property ::Platform::String^ DefaultTemplateKey
		{
			::Platform::String^ get() { return DefaultTemplateKey_; }
			void set( ::Platform::String^ value ) { DefaultTemplateKey_ = value; }
		}
		property bool IsCacheEnabled
		{
			bool get() { return IsCacheEnabled_; }
			void set( bool value );
		}

	private:
		::Platform::String^ DefaultTemplateKey_;
		bool IsCacheEnabled_;

		::std::unordered_map<::Platform::String^, ::Windows::UI::Xaml::DataTemplate^> templateMap_;
	};

} } }