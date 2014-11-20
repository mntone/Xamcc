#include "pch.h"
#include "DataProcessor.h"

using namespace Platform;
using namespace Platform::Collections;
using namespace Windows::Foundation;
using namespace Windows::System::Threading;
using namespace Mntone::Xamcc;

DataProcessor::DataProcessor()
	: Vector_( ref new Vector<DateTime>() )
	, Vector2_( ref new Vector<DateTime>() )
{
	auto calender = ref new Windows::Globalization::Calendar();
	calender->SetToNow();
	Vector_->Append( calender->GetDateTime() );
	Vector_->Append( calender->GetDateTime() );
	Vector_->Append( calender->GetDateTime() );
	Vector2_->InsertAt( 0, calender->GetDateTime() );
	Vector2_->InsertAt( 0, calender->GetDateTime() );
	Vector2_->InsertAt( 0, calender->GetDateTime() );

	TimeSpan timeSpan;
	timeSpan.Duration = 1 * 10000000;
	timer_ = ThreadPoolTimer::CreatePeriodicTimer(
		ref new TimerElapsedHandler( [this]( ThreadPoolTimer^ timer )
		{
			auto calender = ref new Windows::Globalization::Calendar();
			calender->SetToNow();
			Vector_->Append( calender->GetDateTime() );
			Vector2_->InsertAt( 0, calender->GetDateTime() );
		} ),
		timeSpan );
}

Vector<DateTime>^ DataProcessor::GetVector()
{
	return Vector_;
}

Vector<DateTime>^ DataProcessor::GetVector2()
{
	return Vector2_;
}