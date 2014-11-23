#include "pch.h"
#include "NumberComparisonToVisibilityConveter.h"
#include "number_cast.h"

using namespace Platform;
using namespace std;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Interop;
using namespace Mntone::Xamcc::Converters;

namespace MXC = ::Mntone::Xamcc::Converters;

NumberComparisonToVisibilityConveter::NumberComparisonToVisibilityConveter()
{
	NumberType_ = MXC::NumberType::Int32;
	ComparisonType_ = MXC::ComparisonType::EqualTo;
	UpdateFunction();
}

Object^ NumberComparisonToVisibilityConveter::Convert( Object^ value, TypeName /*targetType*/, Object^ parameter, String^ /*language*/ )
{
	return comparisonFunction_( value, dynamic_cast<String^>( parameter ) );
}

Object^ NumberComparisonToVisibilityConveter::ConvertBack( Object^ /*value*/, TypeName /*targetType*/, Object^ /*parameter*/, String^ /*language*/ )
{
	throw ref new FailureException();
}

void NumberComparisonToVisibilityConveter::NumberType::set( MXC::NumberType value )
{
	if( NumberType_ == value )
	{
		return;
	}
	NumberType_ = value;

	UpdateFunction();
}

void NumberComparisonToVisibilityConveter::ComparisonType::set( MXC::ComparisonType value )
{
	if( ComparisonType_ == value )
	{
		return;
	}
	ComparisonType_ = value;

	UpdateFunction();
}

namespace {
	template<typename N>
	function<Object ^ ( Object^, String^ )> GetComparisonFunction( MXC::ComparisonType type )
	{
		function<bool( N, N )> comparisonInnerFunc;
		switch( type )
		{
		case MXC::ComparisonType::NotEqualTo:
			comparisonInnerFunc = not_equal_to<N>();
			break;

		case MXC::ComparisonType::LessThan:
			comparisonInnerFunc = less<N>();
			break;

		case MXC::ComparisonType::LessThanOrEqualTo:
			comparisonInnerFunc = less_equal<N>();
			break;

		case MXC::ComparisonType::GreaterThan:
			comparisonInnerFunc = greater<N>();
			break;

		case MXC::ComparisonType::GreaterThanOrEqualTo:
			comparisonInnerFunc = greater_equal<N>();
			break;

		case MXC::ComparisonType::EqualTo:
		default:
			comparisonInnerFunc = equal_to<N>();
			break;
		};

		return [comparisonInnerFunc]( Object^ value, String^ parameter )
		{
			auto numberValue = dynamic_cast<IBox<N>^>( value );
			N numberParameter = parameter ? number_cast<N>( parameter ) : 0;
			return numberValue
				? ( comparisonInnerFunc( numberValue->Value, numberParameter ) ? Visibility::Visible : Visibility::Collapsed )
				: DependencyProperty::UnsetValue;
		};
	}
}

void NumberComparisonToVisibilityConveter::UpdateFunction()
{
	switch( NumberType_ )
	{
	case MXC::NumberType::Int16:
		comparisonFunction_ = GetComparisonFunction<int16>( ComparisonType_ );
		break;

	case MXC::NumberType::UInt16:
		comparisonFunction_ = GetComparisonFunction<uint16>( ComparisonType_ );
		break;

	case MXC::NumberType::UInt32:
		comparisonFunction_ = GetComparisonFunction<uint32>( ComparisonType_ );
		break;

	case MXC::NumberType::Int64:
		comparisonFunction_ = GetComparisonFunction<int64>( ComparisonType_ );
		break;

	case MXC::NumberType::UInt64:
		comparisonFunction_ = GetComparisonFunction<uint64>( ComparisonType_ );
		break;

	case MXC::NumberType::Single:
		comparisonFunction_ = GetComparisonFunction<float32>( ComparisonType_ );
		break;

	case MXC::NumberType::Double:
		comparisonFunction_ = GetComparisonFunction<float64>( ComparisonType_ );
		break;

	case MXC::NumberType::Int32:
	default:
		comparisonFunction_ = GetComparisonFunction<int32>( ComparisonType_ );
		break;
	}
}