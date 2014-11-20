#pragma once

namespace Mntone { namespace Xamcc { namespace Foundation {

	public ref class TimeSpanHelper sealed
	{
	public:
		static bool Equals( ::Windows::Foundation::TimeSpan target, ::Windows::Foundation::TimeSpan value );

		static ::Windows::Foundation::TimeSpan FromNanoseconds( int64 value );
		static ::Windows::Foundation::TimeSpan FromTicks( int64 value );
		static ::Windows::Foundation::TimeSpan FromMicroseconds( int64 value );
		static ::Windows::Foundation::TimeSpan FromMilliseconds( int64 value );
		static ::Windows::Foundation::TimeSpan FromSeconds( int64 value );
		static ::Windows::Foundation::TimeSpan FromMinutes( int32 value );
		static ::Windows::Foundation::TimeSpan FromHours( int32 value );
		static ::Windows::Foundation::TimeSpan FromDays( int32 value );
		static ::Windows::Foundation::TimeSpan FromWeeks( int32 value );

		static ::Windows::Foundation::TimeSpan Add( ::Windows::Foundation::TimeSpan target, ::Windows::Foundation::TimeSpan value );
		static ::Windows::Foundation::TimeSpan Subtract( ::Windows::Foundation::TimeSpan target, ::Windows::Foundation::TimeSpan value );

		static int64 Compare( ::Windows::Foundation::TimeSpan timeSpan1, ::Windows::Foundation::TimeSpan timeSpan2 );

		static int64 GetTicks( ::Windows::Foundation::TimeSpan value );
		static int64 GetMicroseconds( ::Windows::Foundation::TimeSpan value );
		static int64 GetMilliseconds( ::Windows::Foundation::TimeSpan value );
		static int64 GetSeconds( ::Windows::Foundation::TimeSpan value );
		static int32 GetMinutes( ::Windows::Foundation::TimeSpan value );
		static int32 GetHours( ::Windows::Foundation::TimeSpan value );
		static int32 GetDays( ::Windows::Foundation::TimeSpan value );
		static int32 GetWeeks( ::Windows::Foundation::TimeSpan value );

		static float64 GetTotalMicroseconds( ::Windows::Foundation::TimeSpan value );
		static float64 GetTotalMilliseconds( ::Windows::Foundation::TimeSpan value );
		static float64 GetTotalSeconds( ::Windows::Foundation::TimeSpan value );
		static float64 GetTotalMinute( ::Windows::Foundation::TimeSpan value );
		static float64 GetTotalHours( ::Windows::Foundation::TimeSpan value );
		static float64 GetTotalDays( ::Windows::Foundation::TimeSpan value );
		static float64 GetTotalWeeks( ::Windows::Foundation::TimeSpan value );

		static property ::Windows::Foundation::TimeSpan Zero
		{
			::Windows::Foundation::TimeSpan get();
		}

	private:
		TimeSpanHelper();
	};

} } }