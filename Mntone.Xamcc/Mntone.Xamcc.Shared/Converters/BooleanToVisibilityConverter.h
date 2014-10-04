#pragma once

namespace Mntone { namespace Xamcc { namespace Converters {

	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class BooleanToVisibilityConverter sealed
		: public ::Windows::UI::Xaml::Data::IValueConverter
	{
	public:
		BooleanToVisibilityConverter();

		virtual ::Platform::Object^ Convert(
			::Platform::Object^ value,
			::Windows::UI::Xaml::Interop::TypeName targetType,
			::Platform::Object^ parameter,
			::Platform::String^ language );

		virtual ::Platform::Object^ ConvertBack(
			::Platform::Object^ value,
			::Windows::UI::Xaml::Interop::TypeName targetType,
			::Platform::Object^ parameter,
			::Platform::String^ language );

	public:
		property bool IsInversed
		{
			bool get() { return IsInversed_; }
			void set( bool value ) { IsInversed_ = value; }
		}
		property bool DefaultValue
		{
			bool get() { return DefaultValue_; }
			void set( bool value ) { DefaultValue_ = value; }
		}

	private:
		bool IsInversed_, DefaultValue_;
	};

} } }