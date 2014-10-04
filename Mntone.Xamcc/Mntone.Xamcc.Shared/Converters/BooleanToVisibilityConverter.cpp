#include "pch.h"
#include "BooleanToVisibilityConverter.h"

using namespace Platform;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Interop;
using namespace Mntone::Xamcc::Converters;

BooleanToVisibilityConverter::BooleanToVisibilityConverter()
	: DefaultValue_( true )
{ }

Object^ BooleanToVisibilityConverter::Convert( Object^ value, TypeName /*targetType*/, Object^ /*parameter*/, String^ /*language*/ )
{
	auto flag = dynamic_cast<IBox<bool>^>( value );
	if( flag )
	{
		return flag->Value ^ IsInversed_ ? Visibility::Visible : Visibility::Collapsed;
	}
	return DefaultValue_ ^ IsInversed_ ? Visibility::Visible : Visibility::Collapsed;
}

Object^ BooleanToVisibilityConverter::ConvertBack( Object^ value, TypeName /*targetType*/, Object^ /*parameter*/, String^ /*language*/ )
{
	auto visibility = dynamic_cast<IBox<Visibility>^>( value );
	if( visibility )
	{
		return ( visibility->Value == Visibility::Visible ) ^ IsInversed_ ? true : false;
	}
	return DefaultValue_;
}