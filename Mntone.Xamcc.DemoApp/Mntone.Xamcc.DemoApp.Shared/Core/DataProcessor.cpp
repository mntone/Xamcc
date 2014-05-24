#include "pch.h"
#include "DataProcessor.h"

using namespace Platform;
using namespace Platform::Collections;
using namespace Windows::Foundation;
using namespace Windows::System::Threading;
using namespace Mntone::Xamcc;

DataProcessor::DataProcessor()
	: Vector_( ref new Vector<DateTime>() )
	, Deque_( ref new Deque<DateTime>() )
{
	auto calender = ref new Windows::Globalization::Calendar();
	calender->SetToNow();
	Vector_->Append( calender->GetDateTime() );
	Vector_->Append( calender->GetDateTime() );
	Vector_->Append( calender->GetDateTime() );
	Deque_->Prepend( calender->GetDateTime() );
	Deque_->Prepend( calender->GetDateTime() );
	Deque_->Prepend( calender->GetDateTime() );

	TimeSpan timeSpan;
	timeSpan.Duration = 1 * 10000000;
	timer_ = ThreadPoolTimer::CreatePeriodicTimer(
		ref new TimerElapsedHandler( [this]( ThreadPoolTimer^ timer )
		{
			auto calender = ref new Windows::Globalization::Calendar();
			calender->SetToNow();
			Vector_->Append( calender->GetDateTime() );
			Deque_->Prepend( calender->GetDateTime() );
		} ),
		timeSpan );
}

Vector<DateTime>^ DataProcessor::GetVector()
{
	return Vector_;
}

Deque<DateTime>^ DataProcessor::GetDeque()
{
	return Deque_;
}