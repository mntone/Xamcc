#include "pch.h"
#include "NumberComparisonToVisibilityConveter.h"

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


void NumberComparisonToVisibilityConveter::UpdateFunction()
{
	switch( NumberType_ )
	{
	case MXC::NumberType::Int16:
	{
		function<bool( int16, int16 )> comparisonInnerFunc;
		switch( ComparisonType_ )
		{
		case MXC::ComparisonType::NotEqualTo:
			comparisonInnerFunc = []( int16 value, int16 parameter ) { return value != parameter; };
			break;

		case MXC::ComparisonType::LessThan:
			comparisonInnerFunc = []( int16 value, int16 parameter ) { return value < parameter; };
			break;

		case MXC::ComparisonType::LessThanOrEqualTo:
			comparisonInnerFunc = []( int16 value, int16 parameter ) { return value <= parameter; };
			break;

		case MXC::ComparisonType::GreaterThan:
			comparisonInnerFunc = []( int16 value, int16 parameter ) { return value > parameter; };
			break;

		case MXC::ComparisonType::GreaterThanOrEqualTo:
			comparisonInnerFunc = []( int16 value, int16 parameter ) { return value >= parameter; };
			break;

		case MXC::ComparisonType::EqualTo:
		default:
			comparisonInnerFunc = []( int16 value, int16 parameter ) { return value == parameter; };
			break;
		}
		comparisonFunction_ = [comparisonInnerFunc]( Object^ value, String^ parameter )
		{
			auto numberValue = dynamic_cast<IBox<int16>^>( value );
			int16 numberParameter = parameter ? static_cast<int16>( _wtoi( parameter->Data() ) ) : 0;
			return numberValue
				? ( comparisonInnerFunc( numberValue->Value, numberParameter ) ? Visibility::Visible : Visibility::Collapsed )
				: DependencyProperty::UnsetValue;
		};
		break;
	}

	case MXC::NumberType::UInt16:
	{
		function<bool( uint16, uint16 )> comparisonInnerFunc;
		switch( ComparisonType_ )
		{
		case MXC::ComparisonType::NotEqualTo:
			comparisonInnerFunc = []( uint16 value, uint16 parameter ) { return value != parameter; };
			break;

		case MXC::ComparisonType::LessThan:
			comparisonInnerFunc = []( uint16 value, uint16 parameter ) { return value < parameter; };
			break;

		case MXC::ComparisonType::LessThanOrEqualTo:
			comparisonInnerFunc = []( uint16 value, uint16 parameter ) { return value <= parameter; };
			break;

		case MXC::ComparisonType::GreaterThan:
			comparisonInnerFunc = []( uint16 value, uint16 parameter ) { return value > parameter; };
			break;

		case MXC::ComparisonType::GreaterThanOrEqualTo:
			comparisonInnerFunc = []( uint16 value, uint16 parameter ) { return value >= parameter; };
			break;

		case MXC::ComparisonType::EqualTo:
		default:
			comparisonInnerFunc = []( uint16 value, uint16 parameter ) { return value == parameter; };
			break;
		}
		comparisonFunction_ = [comparisonInnerFunc]( Object^ value, String^ parameter )
		{
			auto numberValue = dynamic_cast<IBox<uint16>^>( value );
			uint16 numberParameter = parameter ? static_cast<uint16>( wcstoul( parameter->Data(), nullptr, 10 ) ) : 0u;
			return numberValue
				? ( comparisonInnerFunc( numberValue->Value, numberParameter ) ? Visibility::Visible : Visibility::Collapsed )
				: DependencyProperty::UnsetValue;
		};
		break;
	}

	case MXC::NumberType::UInt32:
	{
		function<bool( uint32, uint32 )> comparisonInnerFunc;
		switch( ComparisonType_ )
		{
		case MXC::ComparisonType::NotEqualTo:
			comparisonInnerFunc = []( uint32 value, uint32 parameter ) { return value != parameter; };
			break;

		case MXC::ComparisonType::LessThan:
			comparisonInnerFunc = []( uint32 value, uint32 parameter ) { return value < parameter; };
			break;

		case MXC::ComparisonType::LessThanOrEqualTo:
			comparisonInnerFunc = []( uint32 value, uint32 parameter ) { return value <= parameter; };
			break;

		case MXC::ComparisonType::GreaterThan:
			comparisonInnerFunc = []( uint32 value, uint32 parameter ) { return value > parameter; };
			break;

		case MXC::ComparisonType::GreaterThanOrEqualTo:
			comparisonInnerFunc = []( uint32 value, uint32 parameter ) { return value >= parameter; };
			break;

		case MXC::ComparisonType::EqualTo:
		default:
			comparisonInnerFunc = []( uint32 value, uint32 parameter ) { return value == parameter; };
			break;
		}
		comparisonFunction_ = [comparisonInnerFunc]( Object^ value, String^ parameter )
		{
			auto numberValue = dynamic_cast<IBox<uint32>^>( value );
			uint32 numberParameter = parameter ? wcstoul( parameter->Data(), nullptr, 10 ) : 0ul;
			return numberValue
				? ( comparisonInnerFunc( numberValue->Value, numberParameter ) ? Visibility::Visible : Visibility::Collapsed )
				: DependencyProperty::UnsetValue;
		};
		break;
	}

	case MXC::NumberType::Int64:
	{
		function<bool( int64, int64 )> comparisonInnerFunc;
		switch( ComparisonType_ )
		{
		case MXC::ComparisonType::NotEqualTo:
			comparisonInnerFunc = []( int64 value, int64 parameter ) { return value != parameter; };
			break;

		case MXC::ComparisonType::LessThan:
			comparisonInnerFunc = []( int64 value, int64 parameter ) { return value < parameter; };
			break;

		case MXC::ComparisonType::LessThanOrEqualTo:
			comparisonInnerFunc = []( int64 value, int64 parameter ) { return value <= parameter; };
			break;

		case MXC::ComparisonType::GreaterThan:
			comparisonInnerFunc = []( int64 value, int64 parameter ) { return value > parameter; };
			break;

		case MXC::ComparisonType::GreaterThanOrEqualTo:
			comparisonInnerFunc = []( int64 value, int64 parameter ) { return value >= parameter; };
			break;

		case MXC::ComparisonType::EqualTo:
		default:
			comparisonInnerFunc = []( int64 value, int64 parameter ) { return value == parameter; };
			break;
		}
		comparisonFunction_ = [comparisonInnerFunc]( Object^ value, String^ parameter )
		{
			auto numberValue = dynamic_cast<IBox<int64>^>( value );
			int64 numberParameter = parameter ? _wtoi64( parameter->Data() ) : 0ll;
			return numberValue
				? ( comparisonInnerFunc( numberValue->Value, numberParameter ) ? Visibility::Visible : Visibility::Collapsed )
				: DependencyProperty::UnsetValue;
		};
		break;
	}

	case MXC::NumberType::UInt64:
	{
		function<bool( uint64, uint64 )> comparisonInnerFunc;
		switch( ComparisonType_ )
		{
		case MXC::ComparisonType::NotEqualTo:
			comparisonInnerFunc = []( uint64 value, uint64 parameter ) { return value != parameter; };
			break;

		case MXC::ComparisonType::LessThan:
			comparisonInnerFunc = []( uint64 value, uint64 parameter ) { return value < parameter; };
			break;

		case MXC::ComparisonType::LessThanOrEqualTo:
			comparisonInnerFunc = []( uint64 value, uint64 parameter ) { return value <= parameter; };
			break;

		case MXC::ComparisonType::GreaterThan:
			comparisonInnerFunc = []( uint64 value, uint64 parameter ) { return value > parameter; };
			break;

		case MXC::ComparisonType::GreaterThanOrEqualTo:
			comparisonInnerFunc = []( uint64 value, uint64 parameter ) { return value >= parameter; };
			break;

		case MXC::ComparisonType::EqualTo:
		default:
			comparisonInnerFunc = []( uint64 value, uint64 parameter ) { return value == parameter; };
			break;
		}
		comparisonFunction_ = [comparisonInnerFunc]( Object^ value, String^ parameter )
		{
			auto numberValue = dynamic_cast<IBox<uint64>^>( value );
			uint64 numberParameter = parameter ? wcstoull( parameter->Data(), nullptr, 10 ) : 0ull;
			return numberValue
				? ( comparisonInnerFunc( numberValue->Value, numberParameter ) ? Visibility::Visible : Visibility::Collapsed )
				: DependencyProperty::UnsetValue;
		};
		break;
	}

	case MXC::NumberType::Single:
	{
		function<bool( float32, float32 )> comparisonInnerFunc;
		switch( ComparisonType_ )
		{
		case MXC::ComparisonType::NotEqualTo:
			comparisonInnerFunc = []( float32 value, float32 parameter ) { return value != parameter; };
			break;

		case MXC::ComparisonType::LessThan:
			comparisonInnerFunc = []( float32 value, float32 parameter ) { return value < parameter; };
			break;

		case MXC::ComparisonType::LessThanOrEqualTo:
			comparisonInnerFunc = []( float32 value, float32 parameter ) { return value <= parameter; };
			break;

		case MXC::ComparisonType::GreaterThan:
			comparisonInnerFunc = []( float32 value, float32 parameter ) { return value > parameter; };
			break;

		case MXC::ComparisonType::GreaterThanOrEqualTo:
			comparisonInnerFunc = []( float32 value, float32 parameter ) { return value >= parameter; };
			break;

		case MXC::ComparisonType::EqualTo:
		default:
			comparisonInnerFunc = []( float32 value, float32 parameter ) { return value == parameter; };
			break;
		}
		comparisonFunction_ = [comparisonInnerFunc]( Object^ value, String^ parameter )
		{
			auto numberValue = dynamic_cast<IBox<float32>^>( value );
			float32 numberParameter = parameter ? static_cast<float32>( _wtof( parameter->Data() ) ) : 0.f;
			return numberValue
				? ( comparisonInnerFunc( numberValue->Value, numberParameter ) ? Visibility::Visible : Visibility::Collapsed )
				: DependencyProperty::UnsetValue;
		};
		break;
	}

	case MXC::NumberType::Double:
	{
		function<bool( float64, float64 )> comparisonInnerFunc;
		switch( ComparisonType_ )
		{
		case MXC::ComparisonType::NotEqualTo:
			comparisonInnerFunc = []( float64 value, float64 parameter ) { return value != parameter; };
			break;

		case MXC::ComparisonType::LessThan:
			comparisonInnerFunc = []( float64 value, float64 parameter ) { return value < parameter; };
			break;

		case MXC::ComparisonType::LessThanOrEqualTo:
			comparisonInnerFunc = []( float64 value, float64 parameter ) { return value <= parameter; };
			break;

		case MXC::ComparisonType::GreaterThan:
			comparisonInnerFunc = []( float64 value, float64 parameter ) { return value > parameter; };
			break;

		case MXC::ComparisonType::GreaterThanOrEqualTo:
			comparisonInnerFunc = []( float64 value, float64 parameter ) { return value >= parameter; };
			break;

		case MXC::ComparisonType::EqualTo:
		default:
			comparisonInnerFunc = []( float64 value, float64 parameter ) { return value == parameter; };
			break;
		}
		comparisonFunction_ = [comparisonInnerFunc]( Object^ value, String^ parameter )
		{
			auto numberValue = dynamic_cast<IBox<float64>^>( value );
			float64 numberParameter = parameter ? _wtof( parameter->Data() ) : 0.0;
			return numberValue
				? ( comparisonInnerFunc( numberValue->Value, numberParameter ) ? Visibility::Visible : Visibility::Collapsed )
				: DependencyProperty::UnsetValue;
		};
		break;
	}

	case MXC::NumberType::Int32:
	default:
	{
		function<bool( int32, int32 )> comparisonInnerFunc;
		switch( ComparisonType_ )
		{
		case MXC::ComparisonType::NotEqualTo:
			comparisonInnerFunc = []( int32 value, int32 parameter ) { return value != parameter; };
			break;

		case MXC::ComparisonType::LessThan:
			comparisonInnerFunc = []( int32 value, int32 parameter ) { return value < parameter; };
			break;

		case MXC::ComparisonType::LessThanOrEqualTo:
			comparisonInnerFunc = []( int32 value, int32 parameter ) { return value <= parameter; };
			break;

		case MXC::ComparisonType::GreaterThan:
			comparisonInnerFunc = []( int32 value, int32 parameter ) { return value > parameter; };
			break;

		case MXC::ComparisonType::GreaterThanOrEqualTo:
			comparisonInnerFunc = []( int32 value, int32 parameter ) { return value >= parameter; };
			break;

		case MXC::ComparisonType::EqualTo:
		default:
			comparisonInnerFunc = []( int32 value, int32 parameter ) { return value == parameter; };
			break;
		}
		comparisonFunction_ = [comparisonInnerFunc]( Object^ value, String^ parameter )
		{
			auto numberValue = dynamic_cast<IBox<int32>^>( value );
			int32 numberParameter = parameter ? _wtoi( parameter->Data() ) : 0ll;
			return numberValue
				? ( comparisonInnerFunc( numberValue->Value, numberParameter ) ? Visibility::Visible : Visibility::Collapsed )
				: DependencyProperty::UnsetValue;
		};
		break;
	}
	}
}