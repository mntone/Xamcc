#include "pch.h"
#include "FollowNotification.h"

using namespace Platform;
using namespace Windows::Foundation;
using namespace Mntone::Xamcc::DemoApp::Core;

FollowNotification::FollowNotification( DateTime dateTime, String^ key )
{
	Id_ = dateTime.UniversalTime.ToString() + key;
}