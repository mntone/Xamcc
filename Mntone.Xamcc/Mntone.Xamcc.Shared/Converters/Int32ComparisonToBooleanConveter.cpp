#include "pch.h"
#include "Int32ComparisonToBooleanConveter.h"

using namespace Platform;
using namespace Windows::UI::Xaml::Interop;
using namespace Mntone::Xamcc::Converters;

namespace MXC = ::Mntone::Xamcc::Converters;

Int32ComparisonToBooleanConveter::Int32ComparisonToBooleanConveter()
{
	ComparisonType_ = MXC::ComparisonType::EqualTo;
	comparisonFunction_ = []( int32 value, int32 parameter ) { return value == parameter; };
}

Object^ Int32ComparisonToBooleanConveter::Convert( Object^ value, TypeName /*targetType*/, Object^ parameter, String^ /*language*/ )
{
	auto intValue = dynamic_cast<IBox<int32>^>( value );
	auto stringParameter = dynamic_cast<String^>( parameter );
	return comparisonFunction_( intValue ? intValue->Value : DefaultValue_, stringParameter ? _wtoi( stringParameter->Data() ) : 0 );
}

Object^ Int32ComparisonToBooleanConveter::ConvertBack( Object^ /*value*/, TypeName /*targetType*/, Object^ /*parameter*/, String^ /*language*/ )
{
	throw ref new NotImplementedException();
}

void Int32ComparisonToBooleanConveter::ComparisonType::set( MXC::ComparisonType value )
{
	if( ComparisonType_ == value )
	{
		return;
	}
	ComparisonType_ = value;

	switch( value )
	{
	case MXC::ComparisonType::EqualTo:
		comparisonFunction_ = []( int32 value, int32 parameter ) { return value == parameter; };
		break;

	case MXC::ComparisonType::NotEqualTo:
		comparisonFunction_ = []( int32 value, int32 parameter ) { return value != parameter; };
		break;

	case MXC::ComparisonType::LessThan:
		comparisonFunction_ = []( int32 value, int32 parameter ) { return value > parameter; };
		break;

	case MXC::ComparisonType::LessThanOrEqualTo:
		comparisonFunction_ = []( int32 value, int32 parameter ) { return value >= parameter; };
		break;

	case MXC::ComparisonType::GreaterThan:
		comparisonFunction_ = []( int32 value, int32 parameter ) { return value < parameter; };
		break;

	case MXC::ComparisonType::GreaterThanOrEqualTo:
		comparisonFunction_ = []( int32 value, int32 parameter ) { return value <= parameter; };
		break;

	default:
		throw ref new InvalidArgumentException();
	}
}