#include "pch.h"
#include "DataProcessor.h"

using namespace Platform;
using namespace Platform::Collections;
using namespace Windows::Foundation;
using namespace Windows::System::Threading;
using namespace Mntone::Xamcc;

DataProcessor::DataProcessor()
	: Vector_( ref new Vector<DateTime>() )
{
	TimeSpan timeSpan;
	timeSpan.Duration = 1 * 10000000;
	timer_ = ThreadPoolTimer::CreatePeriodicTimer(
		ref new TimerElapsedHandler( [this]( ThreadPoolTimer^ timer )
		{
			auto calender = ref new Windows::Globalization::Calendar();
			calender->SetToNow();
			Vector_->Append( calender->GetDateTime() );
		} ),
		timeSpan );
}

Vector<DateTime>^ DataProcessor::GetVector()
{
	return Vector_;
}