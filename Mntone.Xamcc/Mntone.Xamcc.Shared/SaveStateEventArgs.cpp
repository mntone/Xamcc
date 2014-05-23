#include "pch.h"
#include "SaveStateEventArgs.h"

using namespace Platform;
using namespace Windows::Foundation::Collections;
using namespace Mntone::Xamcc;

SaveStateEventArgs::SaveStateEventArgs( IMap<String^, Object^>^ pageState )
	: pageState_( pageState )
{ }

IMap<String^, Object^>^ SaveStateEventArgs::PageState::get()
{
	return pageState_;
}