#include "pch.h"
#include "TimeSpanHelper.h"
#include "include\Foundation\TimeSpanReference.h"

using namespace std::chrono;
using namespace Platform;
using namespace Windows::Foundation;
using namespace Mntone::Xamcc::Foundation;

namespace std { namespace chrono {
	
	using days = duration<int, std::ratio<86400>>;
	using weeks = duration<int, std::ratio<604800>>;

} }

TimeSpanHelper::TimeSpanHelper()
{ }

bool TimeSpanHelper::Equals( TimeSpan target, TimeSpan value )
{
	return target.Duration == value.Duration;
}

TimeSpan TimeSpanHelper::FromNanoseconds( int64 value )
{
	return TimeSpanReference( nanoseconds( value ) );
}

TimeSpan TimeSpanHelper::FromTicks( int64 value )
{
	return TimeSpanReference( system_clock::duration( value ) );
}

TimeSpan TimeSpanHelper::FromMicroseconds( int64 value )
{
	return TimeSpanReference( microseconds( value ) );
}

TimeSpan TimeSpanHelper::FromMilliseconds( int64 value )
{
	return TimeSpanReference( milliseconds( value ) );
}

TimeSpan TimeSpanHelper::FromSeconds( int64 value )
{
	return TimeSpanReference( seconds( value ) );
}

TimeSpan TimeSpanHelper::FromMinutes( int32 value )
{
	return TimeSpanReference( minutes( value ) );
}

TimeSpan TimeSpanHelper::FromHours( int32 value )
{
	return TimeSpanReference( hours( value ) );
}

TimeSpan TimeSpanHelper::FromDays( int32 value )
{
	return TimeSpanReference( duration_cast<system_clock::duration>( days( value ) ) );
}

TimeSpan TimeSpanHelper::FromWeeks( int32 value )
{
	return TimeSpanReference( duration_cast<system_clock::duration>( weeks( value ) ) );
}


TimeSpan TimeSpanHelper::Add( TimeSpan target, TimeSpan value )
{
	return TimeSpan{ target.Duration + value.Duration };
}

TimeSpan TimeSpanHelper::Subtract( TimeSpan target, TimeSpan value )
{
	return TimeSpan{ target.Duration - value.Duration };
}

int64 TimeSpanHelper::Compare( TimeSpan timeSpan1, TimeSpan timeSpan2 )
{
	return timeSpan2.Duration - timeSpan1.Duration;
}


int64 TimeSpanHelper::GetTicks( TimeSpan value )
{
	return value.Duration;
}

int64 TimeSpanHelper::GetMicroseconds( TimeSpan value )
{
	return duration_cast<microseconds>( system_clock::duration( value.Duration ) ).count();
}

int64 TimeSpanHelper::GetMilliseconds( TimeSpan value )
{
	return duration_cast<milliseconds>( system_clock::duration( value.Duration ) ).count();
}

int64 TimeSpanHelper::GetSeconds( TimeSpan value )
{
	return duration_cast<seconds>( system_clock::duration( value.Duration ) ).count();
}

int32 TimeSpanHelper::GetMinutes( TimeSpan value )
{
	return duration_cast<minutes>( system_clock::duration( value.Duration ) ).count();
}

int32 TimeSpanHelper::GetHours( TimeSpan value )
{
	return duration_cast<hours>( system_clock::duration( value.Duration ) ).count();
}

int32 TimeSpanHelper::GetDays( TimeSpan value )
{
	return duration_cast<days>( system_clock::duration( value.Duration ) ).count();
}

int32 TimeSpanHelper::GetWeeks( TimeSpan value )
{
	return duration_cast<weeks>( system_clock::duration( value.Duration ) ).count();
}

float64 TimeSpanHelper::GetTotalMicroseconds( TimeSpan value )
{
	return static_cast<float64>( value.Duration ) / 10.0;
}

float64 TimeSpanHelper::GetTotalMilliseconds( TimeSpan value )
{
	return GetTotalMicroseconds( value ) / 1000.0;
}

float64 TimeSpanHelper::GetTotalSeconds( TimeSpan value )
{
	return GetTotalMilliseconds( value ) / 1000.0;
}

float64 TimeSpanHelper::GetTotalMinute( TimeSpan value )
{
	return GetTotalSeconds( value ) / 60.0;
}

float64 TimeSpanHelper::GetTotalHours( TimeSpan value )
{
	return GetTotalMinute( value ) / 60.0;
}

float64 TimeSpanHelper::GetTotalDays( TimeSpan value )
{
	return GetTotalHours( value ) / 24.0;
}

float64 TimeSpanHelper::GetTotalWeeks( TimeSpan value )
{
	return GetTotalDays( value ) / 7.0;
}

TimeSpan TimeSpanHelper::Zero::get()
{
	return TimeSpan{ 0 };
}