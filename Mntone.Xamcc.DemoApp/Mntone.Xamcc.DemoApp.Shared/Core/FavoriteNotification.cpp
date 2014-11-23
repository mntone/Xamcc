#include "pch.h"
#include "FavoriteNotification.h"

using namespace Platform;
using namespace Windows::Foundation;
using namespace Mntone::Xamcc::DemoApp::Core;

FavoriteNotification::FavoriteNotification( DateTime dateTime, String^ key )
{
	Id_ = dateTime.UniversalTime.ToString() + key;
}