#pragma once
#include <functional>
#include "ComparisonType.h"

namespace Mntone { namespace Xamcc { namespace Converters {

	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class Int32ComparisonToBooleanConveter sealed
		: public ::Windows::UI::Xaml::Data::IValueConverter
	{
	public:
		Int32ComparisonToBooleanConveter();

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
		property int32 DefaultValue
		{
			int32 get() { return DefaultValue_; }
			void set( int32 value ) { DefaultValue_ = value; }
		}
		property Converters::ComparisonType ComparisonType
		{
			Converters::ComparisonType get() { return ComparisonType_; }
			void set( Converters::ComparisonType value );
		}

	private:
		int32 DefaultValue_;
		Converters::ComparisonType ComparisonType_;

		::std::function<bool( int32, int32 )> comparisonFunction_;
	};

} } }