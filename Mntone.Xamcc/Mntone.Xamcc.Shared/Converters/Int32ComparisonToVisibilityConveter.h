#pragma once
#include <functional>
#include "ComparisonType.h"

namespace Mntone { namespace Xamcc { namespace Converters {

	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class Int32ComparisonToVisibilityConveter sealed
		: public ::Windows::UI::Xaml::Data::IValueConverter
	{
	public:
		Int32ComparisonToVisibilityConveter();

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
		property Converters::ComparisonType ComparisonType
		{
			Converters::ComparisonType get() { return ComparisonType_; }
			void set( Converters::ComparisonType value );
		}

	private:
		Converters::ComparisonType ComparisonType_;

		::std::function<bool( int32, int32 )> comparisonFunction_;
	};

} } }