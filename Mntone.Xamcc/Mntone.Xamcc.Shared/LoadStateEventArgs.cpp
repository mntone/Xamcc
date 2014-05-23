#include "pch.h"
#include "LoadStateEventArgs.h"

using namespace Platform;
using namespace Windows::Foundation::Collections;
using namespace Mntone::Xamcc;

LoadStateEventArgs::LoadStateEventArgs( Object^ navigationParameter, IMap<String^, Object^>^ pageState )
	: navigationParameter_( navigationParameter )
	, pageState_( pageState )
{ }

Object^ LoadStateEventArgs::NavigationParameter::get()
{
	return navigationParameter_;
}

IMap<String^, Object^>^ LoadStateEventArgs::PageState::get()
{
	return pageState_;
}