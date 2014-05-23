#pragma once
#include "SaveStateEventArgs.h"

namespace Mntone { namespace Xamcc {

	public delegate void SaveStateEventHandler( Platform::Object^ sender, SaveStateEventArgs^ e );

} }