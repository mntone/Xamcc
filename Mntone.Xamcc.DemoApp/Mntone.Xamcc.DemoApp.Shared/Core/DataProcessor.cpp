#include "pch.h"
#include "DataProcessor.h"
#include "FavoriteNotification.h"
#include "FollowNotification.h"

using namespace Platform;
using namespace Platform::Collections;
using namespace Windows::Foundation;
using namespace Windows::System::Threading;
using namespace Mntone::Xamcc::DemoApp::Core;

DataProcessor::DataProcessor()
	: Vector_( ref new Vector<DateTime>() )
	, Vector2_( ref new Vector<DateTime>() )
	, Vector3_( ref new Vector<INotification^>() )
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

			auto dt = calender->GetDateTime();
			Vector_->Append( dt );
			Vector2_->InsertAt( 0, dt );
			
			INotification^ no;
			if( dt.UniversalTime % 10 == 0 )
			{
				no = ref new FollowNotification( dt, ( dt.UniversalTime % 10 ).ToString() );
			}
			else
			{
				no = ref new FavoriteNotification( dt, ( dt.UniversalTime % 10 ).ToString() );
			}
			Vector3_->InsertAt( 0, no );
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

Vector<INotification^>^ DataProcessor::GetVector3()
{
	return Vector3_;
}