#pragma once
#include <chrono>

namespace Mntone { namespace Xamcc { namespace Foundation {

class TimeSpanReference
{
public:
	TimeSpanReference() { }
	explicit TimeSpanReference( int64 value )
	{
		sysTime_ = ::std::chrono::system_clock::duration( value );
	}
	explicit TimeSpanReference( ::std::chrono::nanoseconds value )
	{
		sysTime_ = ::std::chrono::duration_cast<::std::chrono::system_clock::duration>( value );
	}
	explicit TimeSpanReference( ::std::chrono::system_clock::duration value )
	{
		sysTime_ = value;
	}
	explicit TimeSpanReference( ::std::chrono::microseconds value )
	{
		sysTime_ = value;
	}
	explicit TimeSpanReference( ::std::chrono::milliseconds value )
	{
		sysTime_ = value;
	}
	explicit TimeSpanReference( ::std::chrono::seconds value )
	{
		sysTime_ = value;
	}
	explicit TimeSpanReference( ::std::chrono::minutes value )
	{
		sysTime_ = value;
	}
	explicit TimeSpanReference( ::std::chrono::hours value )
	{
		sysTime_ = value;
	}

	int64 Duration() const
	{
		return sysTime_.count();
	}

	operator ::std::chrono::nanoseconds() const
	{
		return sysTime_;
	}
	operator ::std::chrono::system_clock::duration() const
	{
		return sysTime_;
	}
	operator ::std::chrono::microseconds() const
	{
		return ::std::chrono::duration_cast<::std::chrono::microseconds>( sysTime_ );
	}
	operator ::std::chrono::milliseconds() const
	{
		return ::std::chrono::duration_cast<::std::chrono::milliseconds>( sysTime_ );
	}
	operator ::std::chrono::seconds() const
	{
		return ::std::chrono::duration_cast<::std::chrono::seconds>( sysTime_ );
	}
	operator ::std::chrono::minutes() const
	{
		return ::std::chrono::duration_cast<::std::chrono::minutes>( sysTime_ );
	}
	operator ::std::chrono::hours() const
	{
		return ::std::chrono::duration_cast<::std::chrono::hours>( sysTime_ );
	}

	operator ::Windows::Foundation::TimeSpan() const
	{
		return ::Windows::Foundation::TimeSpan{ sysTime_.count() };
	}

private:
	::std::chrono::system_clock::duration sysTime_;
};

} } }