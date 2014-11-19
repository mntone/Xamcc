#include "pch.h"
#include "BooleanToNegativeBooleanConverter.h"

using namespace Platform;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Interop;
using namespace Mntone::Xamcc::Converters;

BooleanToNegativeBooleanConverter::BooleanToNegativeBooleanConverter()
{ }

Object^ BooleanToNegativeBooleanConverter::Convert( Object^ value, TypeName /*targetType*/, Object^ /*parameter*/, String^ /*language*/ )
{
	auto flag = dynamic_cast<IBox<bool>^>( value );
	if( flag != nullptr )
	{
		return !flag->Value;
	}
	return DependencyProperty::UnsetValue;
}

Object^ BooleanToNegativeBooleanConverter::ConvertBack( Object^ value, TypeName /*targetType*/, Object^ /*parameter*/, String^ /*language*/ )
{
	auto flag = dynamic_cast<IBox<bool>^>( value );
	if( flag != nullptr )
	{
		return !flag->Value;
	}
	return nullptr;
}