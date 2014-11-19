#pragma once

namespace Mntone { namespace Xamcc { namespace Converters {

	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class BooleanToNegativeBooleanConverter sealed
		: public ::Windows::UI::Xaml::Data::IValueConverter
	{
	public:
		BooleanToNegativeBooleanConverter();

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
	};

} } }