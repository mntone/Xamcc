#pragma once
#include <functional>
#include "NumberType.h"
#include "ComparisonType.h"

namespace Mntone { namespace Xamcc { namespace Converters {

	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class NumberComparisonToBooleanConveter sealed
		: public ::Windows::UI::Xaml::Data::IValueConverter
	{
	public:
		NumberComparisonToBooleanConveter();

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
		property Converters::NumberType NumberType
		{
			Converters::NumberType get() { return NumberType_; }
			void set( Converters::NumberType value );
		}
		property Converters::ComparisonType ComparisonType
		{
			Converters::ComparisonType get() { return ComparisonType_; }
			void set( Converters::ComparisonType value );
		}

	private:
		void UpdateFunction();

	private:
		Converters::NumberType NumberType_;
		Converters::ComparisonType ComparisonType_;

		::std::function<::Platform::Object^ ( ::Platform::Object^, ::Platform::String^ )> comparisonFunction_;
	};

} } }