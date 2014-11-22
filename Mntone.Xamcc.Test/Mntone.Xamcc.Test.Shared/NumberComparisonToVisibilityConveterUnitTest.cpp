#include "pch.h"

using namespace Platform;
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Windows::UI::Xaml;

namespace Mntone { namespace Xamcc { namespace Test {

	TEST_CLASS( PLATFORM_PREFIX( NumberComparisonToVisibilityConveterUnitTest ) )
	{
	public:
		TEST_METHOD( ConvertBackEqualToTestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			Assert::ExpectException<FailureException^>( [converter]
			{
				auto ret = converter->ConvertBack( true, int::typeid, nullptr, nullptr );
			} );
		}


		TEST_METHOD( ConvertInt16EqualTo0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Int16;
			TestZero<int16>( converter, []( int16 a ) { return a == 0; } );
		}
		TEST_METHOD( ConvertInt16EqualTo24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Int16;
			TestNonZero<int16>( converter, 24, []( int16 a, int16 b ) { return a == b; } );
		}

		TEST_METHOD( ConvertInt16NotEqualTo0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Int16;
			converter->ComparisonType = Converters::ComparisonType::NotEqualTo;
			TestZero<int16>( converter, []( int16 a ) { return a != 0; } );
		}
		TEST_METHOD( ConvertInt16NotEqualTo24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Int16;
			converter->ComparisonType = Converters::ComparisonType::NotEqualTo;
			TestNonZero<int16>( converter, 24, []( int16 a, int16 b ) { return a != b; } );
		}

		TEST_METHOD( ConvertInt16LessThan0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Int16;
			converter->ComparisonType = Converters::ComparisonType::LessThan;
			TestZero<int16>( converter, []( int16 a ) { return a < 0; } );
		}
		TEST_METHOD( ConvertInt16LessThan24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Int16;
			converter->ComparisonType = Converters::ComparisonType::LessThan;
			TestNonZero<int16>( converter, 24, []( int16 a, int16 b ) { return a < b; } );
		}

		TEST_METHOD( ConvertInt16LessThanOrEqualTo0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Int16;
			converter->ComparisonType = Converters::ComparisonType::LessThanOrEqualTo;
			TestZero<int16>( converter, []( int16 a ) { return a <= 0; } );
		}
		TEST_METHOD( ConvertInt16LessThanOrEqualTo24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Int16;
			converter->ComparisonType = Converters::ComparisonType::LessThanOrEqualTo;
			TestNonZero<int16>( converter, 24, []( int16 a, int16 b ) { return a <= b; } );
		}

		TEST_METHOD( ConvertInt16GreaterThan0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Int16;
			converter->ComparisonType = Converters::ComparisonType::GreaterThan;
			TestZero<int16>( converter, []( int16 a ) { return a > 0; } );
		}
		TEST_METHOD( ConvertInt16GreaterThan24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Int16;
			converter->ComparisonType = Converters::ComparisonType::GreaterThan;
			TestNonZero<int16>( converter, 24, []( int16 a, int16 b ) { return a > b; } );
		}

		TEST_METHOD( ConvertInt16GreaterThanOrEqualTo0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Int16;
			converter->ComparisonType = Converters::ComparisonType::GreaterThanOrEqualTo;
			TestZero<int16>( converter, []( int16 a ) { return a >= 0; } );
		}
		TEST_METHOD( ConvertInt16GreaterThanOrEqualTo24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Int16;
			converter->ComparisonType = Converters::ComparisonType::GreaterThanOrEqualTo;
			TestNonZero<int16>( converter, 24, []( int16 a, int16 b ) { return a >= b; } );
		}


		TEST_METHOD( ConvertUInt16EqualTo0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt16;
			TestZero<uint16>( converter, []( uint16 a ) { return a == 0; } );
		}
		TEST_METHOD( ConvertUInt16EqualTo24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt16;
			TestNonZero<uint16>( converter, 24, []( uint16 a, uint16 b ) { return a == b; } );
		}

		TEST_METHOD( ConvertUInt16NotEqualTo0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt16;
			converter->ComparisonType = Converters::ComparisonType::NotEqualTo;
			TestZero<uint16>( converter, []( uint16 a ) { return a != 0; } );
		}
		TEST_METHOD( ConvertUInt16NotEqualTo24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt16;
			converter->ComparisonType = Converters::ComparisonType::NotEqualTo;
			TestNonZero<uint16>( converter, 24, []( uint16 a, uint16 b ) { return a != b; } );
		}

		TEST_METHOD( ConvertUInt16LessThan0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt16;
			converter->ComparisonType = Converters::ComparisonType::LessThan;
			TestZero<uint16>( converter, []( uint16 a ) { return a < 0; } );
		}
		TEST_METHOD( ConvertUInt16LessThan24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt16;
			converter->ComparisonType = Converters::ComparisonType::LessThan;
			TestNonZero<uint16>( converter, 24, []( uint16 a, uint16 b ) { return a < b; } );
		}

		TEST_METHOD( ConvertUInt16LessThanOrEqualTo0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt16;
			converter->ComparisonType = Converters::ComparisonType::LessThanOrEqualTo;
			TestZero<uint16>( converter, []( uint16 a ) { return a <= 0; } );
		}
		TEST_METHOD( ConvertUInt16LessThanOrEqualTo24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt16;
			converter->ComparisonType = Converters::ComparisonType::LessThanOrEqualTo;
			TestNonZero<uint16>( converter, 24, []( uint16 a, uint16 b ) { return a <= b; } );
		}

		TEST_METHOD( ConvertUInt16GreaterThan0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt16;
			converter->ComparisonType = Converters::ComparisonType::GreaterThan;
			TestZero<uint16>( converter, []( uint16 a ) { return a > 0; } );
		}
		TEST_METHOD( ConvertUInt16GreaterThan24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt16;
			converter->ComparisonType = Converters::ComparisonType::GreaterThan;
			TestNonZero<uint16>( converter, 24, []( uint16 a, uint16 b ) { return a > b; } );
		}

		TEST_METHOD( ConvertUInt16GreaterThanOrEqualTo0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt16;
			converter->ComparisonType = Converters::ComparisonType::GreaterThanOrEqualTo;
			TestZero<uint16>( converter, []( uint16 a ) { return a >= 0; } );
		}
		TEST_METHOD( ConvertUInt16GreaterThanOrEqualTo24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt16;
			converter->ComparisonType = Converters::ComparisonType::GreaterThanOrEqualTo;
			TestNonZero<uint16>( converter, 24, []( uint16 a, uint16 b ) { return a >= b; } );
		}


		TEST_METHOD( ConvertInt32EqualTo0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			TestZero<int32>( converter, []( int32 a ) { return a == 0; } );
		}
		TEST_METHOD( ConvertInt32EqualTo24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			TestNonZero<int32>( converter, 24, []( int32 a, int32 b ) { return a == b; } );
		}

		TEST_METHOD( ConvertInt32NotEqualTo0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->ComparisonType = Converters::ComparisonType::NotEqualTo;
			TestZero<int32>( converter, []( int32 a ) { return a != 0; } );
		}
		TEST_METHOD( ConvertInt32NotEqualTo24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->ComparisonType = Converters::ComparisonType::NotEqualTo;
			TestNonZero<int32>( converter, 24, []( int32 a, int32 b ) { return a != b; } );
		}

		TEST_METHOD( ConvertInt32LessThan0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->ComparisonType = Converters::ComparisonType::LessThan;
			TestZero<int32>( converter, []( int32 a ) { return a < 0; } );
		}
		TEST_METHOD( ConvertInt32LessThan24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->ComparisonType = Converters::ComparisonType::LessThan;
			TestNonZero<int32>( converter, 24, []( int32 a, int32 b ) { return a < b; } );
		}

		TEST_METHOD( ConvertInt32LessThanOrEqualTo0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->ComparisonType = Converters::ComparisonType::LessThanOrEqualTo;
			TestZero<int32>( converter, []( int32 a ) { return a <= 0; } );
		}
		TEST_METHOD( ConvertInt32LessThanOrEqualTo24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->ComparisonType = Converters::ComparisonType::LessThanOrEqualTo;
			TestNonZero<int32>( converter, 24, []( int32 a, int32 b ) { return a <= b; } );
		}

		TEST_METHOD( ConvertInt32GreaterThan0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->ComparisonType = Converters::ComparisonType::GreaterThan;
			TestZero<int32>( converter, []( int32 a ) { return a > 0; } );
		}
		TEST_METHOD( ConvertInt32GreaterThan24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->ComparisonType = Converters::ComparisonType::GreaterThan;
			TestNonZero<int32>( converter, 24, []( int32 a, int32 b ) { return a > b; } );
		}

		TEST_METHOD( ConvertInt32GreaterThanOrEqualTo0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->ComparisonType = Converters::ComparisonType::GreaterThanOrEqualTo;
			TestZero<int32>( converter, []( int32 a ) { return a >= 0; } );
		}
		TEST_METHOD( ConvertInt32GreaterThanOrEqualTo24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->ComparisonType = Converters::ComparisonType::GreaterThanOrEqualTo;
			TestNonZero<int32>( converter, 24, []( int32 a, int32 b ) { return a >= b; } );
		}


		TEST_METHOD( ConvertUInt32EqualTo0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt32;
			TestZero<uint32>( converter, []( uint32 a ) { return a == 0; } );
		}
		TEST_METHOD( ConvertUInt32EqualTo24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt32;
			TestNonZero<uint32>( converter, 24, []( uint32 a, uint32 b ) { return a == b; } );
		}

		TEST_METHOD( ConvertUInt32NotEqualTo0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt32;
			converter->ComparisonType = Converters::ComparisonType::NotEqualTo;
			TestZero<uint32>( converter, []( uint32 a ) { return a != 0; } );
		}
		TEST_METHOD( ConvertUInt32NotEqualTo24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt32;
			converter->ComparisonType = Converters::ComparisonType::NotEqualTo;
			TestNonZero<uint32>( converter, 24, []( uint32 a, uint32 b ) { return a != b; } );
		}

		TEST_METHOD( ConvertUInt32LessThan0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt32;
			converter->ComparisonType = Converters::ComparisonType::LessThan;
			TestZero<uint32>( converter, []( uint32 a ) { return a < 0; } );
		}
		TEST_METHOD( ConvertUInt32LessThan24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt32;
			converter->ComparisonType = Converters::ComparisonType::LessThan;
			TestNonZero<uint32>( converter, 24, []( uint32 a, uint32 b ) { return a < b; } );
		}

		TEST_METHOD( ConvertUInt32LessThanOrEqualTo0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt32;
			converter->ComparisonType = Converters::ComparisonType::LessThanOrEqualTo;
			TestZero<uint32>( converter, []( uint32 a ) { return a <= 0; } );
		}
		TEST_METHOD( ConvertUInt32LessThanOrEqualTo24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt32;
			converter->ComparisonType = Converters::ComparisonType::LessThanOrEqualTo;
			TestNonZero<uint32>( converter, 24, []( uint32 a, uint32 b ) { return a <= b; } );
		}

		TEST_METHOD( ConvertUInt32GreaterThan0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt32;
			converter->ComparisonType = Converters::ComparisonType::GreaterThan;
			TestZero<uint32>( converter, []( uint32 a ) { return a > 0; } );
		}
		TEST_METHOD( ConvertUInt32GreaterThan24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt32;
			converter->ComparisonType = Converters::ComparisonType::GreaterThan;
			TestNonZero<uint32>( converter, 24, []( uint32 a, uint32 b ) { return a > b; } );
		}

		TEST_METHOD( ConvertUInt32GreaterThanOrEqualTo0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt32;
			converter->ComparisonType = Converters::ComparisonType::GreaterThanOrEqualTo;
			TestZero<uint32>( converter, []( uint32 a ) { return a >= 0; } );
		}
		TEST_METHOD( ConvertUInt32GreaterThanOrEqualTo24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt32;
			converter->ComparisonType = Converters::ComparisonType::GreaterThanOrEqualTo;
			TestNonZero<uint32>( converter, 24, []( uint32 a, uint32 b ) { return a >= b; } );
		}


		TEST_METHOD( ConvertInt64EqualTo0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Int64;
			TestZero<int64>( converter, []( int64 a ) { return a == 0; } );
		}
		TEST_METHOD( ConvertInt64EqualTo24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Int64;
			TestNonZero<int64>( converter, 24, []( int64 a, int64 b ) { return a == b; } );
		}

		TEST_METHOD( ConvertInt64NotEqualTo0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Int64;
			converter->ComparisonType = Converters::ComparisonType::NotEqualTo;
			TestZero<int64>( converter, []( int64 a ) { return a != 0; } );
		}
		TEST_METHOD( ConvertInt64NotEqualTo24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Int64;
			converter->ComparisonType = Converters::ComparisonType::NotEqualTo;
			TestNonZero<int64>( converter, 24, []( int64 a, int64 b ) { return a != b; } );
		}

		TEST_METHOD( ConvertInt64LessThan0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Int64;
			converter->ComparisonType = Converters::ComparisonType::LessThan;
			TestZero<int64>( converter, []( int64 a ) { return a < 0; } );
		}
		TEST_METHOD( ConvertInt64LessThan24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Int64;
			converter->ComparisonType = Converters::ComparisonType::LessThan;
			TestNonZero<int64>( converter, 24, []( int64 a, int64 b ) { return a < b; } );
		}

		TEST_METHOD( ConvertInt64LessThanOrEqualTo0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Int64;
			converter->ComparisonType = Converters::ComparisonType::LessThanOrEqualTo;
			TestZero<int64>( converter, []( int64 a ) { return a <= 0; } );
		}
		TEST_METHOD( ConvertInt64LessThanOrEqualTo24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Int64;
			converter->ComparisonType = Converters::ComparisonType::LessThanOrEqualTo;
			TestNonZero<int64>( converter, 24, []( int64 a, int64 b ) { return a <= b; } );
		}

		TEST_METHOD( ConvertInt64GreaterThan0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Int64;
			converter->ComparisonType = Converters::ComparisonType::GreaterThan;
			TestZero<int64>( converter, []( int64 a ) { return a > 0; } );
		}
		TEST_METHOD( ConvertInt64GreaterThan24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Int64;
			converter->ComparisonType = Converters::ComparisonType::GreaterThan;
			TestNonZero<int64>( converter, 24, []( int64 a, int64 b ) { return a > b; } );
		}

		TEST_METHOD( ConvertInt64GreaterThanOrEqualTo0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Int64;
			converter->ComparisonType = Converters::ComparisonType::GreaterThanOrEqualTo;
			TestZero<int64>( converter, []( int64 a ) { return a >= 0; } );
		}
		TEST_METHOD( ConvertInt64GreaterThanOrEqualTo24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Int64;
			converter->ComparisonType = Converters::ComparisonType::GreaterThanOrEqualTo;
			TestNonZero<int64>( converter, 24, []( int64 a, int64 b ) { return a >= b; } );
		}


		TEST_METHOD( ConvertUInt64EqualTo0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt64;
			TestZero<uint64>( converter, []( uint64 a ) { return a == 0; } );
		}
		TEST_METHOD( ConvertUInt64EqualTo24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt64;
			TestNonZero<uint64>( converter, 24, []( uint64 a, uint64 b ) { return a == b; } );
		}

		TEST_METHOD( ConvertUInt64NotEqualTo0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt64;
			converter->ComparisonType = Converters::ComparisonType::NotEqualTo;
			TestZero<uint64>( converter, []( uint64 a ) { return a != 0; } );
		}
		TEST_METHOD( ConvertUInt64NotEqualTo24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt64;
			converter->ComparisonType = Converters::ComparisonType::NotEqualTo;
			TestNonZero<uint64>( converter, 24, []( uint64 a, uint64 b ) { return a != b; } );
		}

		TEST_METHOD( ConvertUInt64LessThan0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt64;
			converter->ComparisonType = Converters::ComparisonType::LessThan;
			TestZero<uint64>( converter, []( uint64 a ) { return a < 0; } );
		}
		TEST_METHOD( ConvertUInt64LessThan24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt64;
			converter->ComparisonType = Converters::ComparisonType::LessThan;
			TestNonZero<uint64>( converter, 24, []( uint64 a, uint64 b ) { return a < b; } );
		}

		TEST_METHOD( ConvertUInt64LessThanOrEqualTo0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt64;
			converter->ComparisonType = Converters::ComparisonType::LessThanOrEqualTo;
			TestZero<uint64>( converter, []( uint64 a ) { return a <= 0; } );
		}
		TEST_METHOD( ConvertUInt64LessThanOrEqualTo24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt64;
			converter->ComparisonType = Converters::ComparisonType::LessThanOrEqualTo;
			TestNonZero<uint64>( converter, 24, []( uint64 a, uint64 b ) { return a <= b; } );
		}

		TEST_METHOD( ConvertUInt64GreaterThan0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt64;
			converter->ComparisonType = Converters::ComparisonType::GreaterThan;
			TestZero<uint64>( converter, []( uint64 a ) { return a > 0; } );
		}
		TEST_METHOD( ConvertUInt64GreaterThan24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt64;
			converter->ComparisonType = Converters::ComparisonType::GreaterThan;
			TestNonZero<uint64>( converter, 24, []( uint64 a, uint64 b ) { return a > b; } );
		}

		TEST_METHOD( ConvertUInt64GreaterThanOrEqualTo0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt64;
			converter->ComparisonType = Converters::ComparisonType::GreaterThanOrEqualTo;
			TestZero<uint64>( converter, []( uint64 a ) { return a >= 0; } );
		}
		TEST_METHOD( ConvertUInt64GreaterThanOrEqualTo24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::UInt64;
			converter->ComparisonType = Converters::ComparisonType::GreaterThanOrEqualTo;
			TestNonZero<uint64>( converter, 24, []( uint64 a, uint64 b ) { return a >= b; } );
		}


		TEST_METHOD( ConvertSingleEqualTo0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Single;
			TestZeroF<float32>( converter, []( float32 a ) { return a == 0; } );
		}
		TEST_METHOD( ConvertSingleEqualTo24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Single;
			TestNonZeroF<float32>( converter, 24, []( float32 a, float32 b ) { return a == b; } );
		}

		TEST_METHOD( ConvertSingleNotEqualTo0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Single;
			converter->ComparisonType = Converters::ComparisonType::NotEqualTo;
			TestZeroF<float32>( converter, []( float32 a ) { return a != 0; } );
		}
		TEST_METHOD( ConvertSingleNotEqualTo24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Single;
			converter->ComparisonType = Converters::ComparisonType::NotEqualTo;
			TestNonZeroF<float32>( converter, 24, []( float32 a, float32 b ) { return a != b; } );
		}

		TEST_METHOD( ConvertSingleLessThan0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Single;
			converter->ComparisonType = Converters::ComparisonType::LessThan;
			TestZeroF<float32>( converter, []( float32 a ) { return a < 0; } );
		}
		TEST_METHOD( ConvertSingleLessThan24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Single;
			converter->ComparisonType = Converters::ComparisonType::LessThan;
			TestNonZeroF<float32>( converter, 24, []( float32 a, float32 b ) { return a < b; } );
		}

		TEST_METHOD( ConvertSingleLessThanOrEqualTo0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Single;
			converter->ComparisonType = Converters::ComparisonType::LessThanOrEqualTo;
			TestZeroF<float32>( converter, []( float32 a ) { return a <= 0; } );
		}
		TEST_METHOD( ConvertSingleLessThanOrEqualTo24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Single;
			converter->ComparisonType = Converters::ComparisonType::LessThanOrEqualTo;
			TestNonZeroF<float32>( converter, 24, []( float32 a, float32 b ) { return a <= b; } );
		}

		TEST_METHOD( ConvertSingleGreaterThan0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Single;
			converter->ComparisonType = Converters::ComparisonType::GreaterThan;
			TestZeroF<float32>( converter, []( float32 a ) { return a > 0; } );
		}
		TEST_METHOD( ConvertSingleGreaterThan24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Single;
			converter->ComparisonType = Converters::ComparisonType::GreaterThan;
			TestNonZeroF<float32>( converter, 24, []( float32 a, float32 b ) { return a > b; } );
		}

		TEST_METHOD( ConvertSingleGreaterThanOrEqualTo0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Single;
			converter->ComparisonType = Converters::ComparisonType::GreaterThanOrEqualTo;
			TestZeroF<float32>( converter, []( float32 a ) { return a >= 0; } );
		}
		TEST_METHOD( ConvertSingleGreaterThanOrEqualTo24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Single;
			converter->ComparisonType = Converters::ComparisonType::GreaterThanOrEqualTo;
			TestNonZeroF<float32>( converter, 24, []( float32 a, float32 b ) { return a >= b; } );
		}


		TEST_METHOD( ConvertDoubleEqualTo0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Double;
			TestZeroF<float64>( converter, []( float64 a ) { return a == 0; } );
		}
		TEST_METHOD( ConvertDoubleEqualTo24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Double;
			TestNonZeroF<float64>( converter, 24, []( float64 a, float64 b ) { return a == b; } );
		}

		TEST_METHOD( ConvertDoubleNotEqualTo0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Double;
			converter->ComparisonType = Converters::ComparisonType::NotEqualTo;
			TestZeroF<float64>( converter, []( float64 a ) { return a != 0; } );
		}
		TEST_METHOD( ConvertDoubleNotEqualTo24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Double;
			converter->ComparisonType = Converters::ComparisonType::NotEqualTo;
			TestNonZeroF<float64>( converter, 24, []( float64 a, float64 b ) { return a != b; } );
		}

		TEST_METHOD( ConvertDoubleLessThan0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Double;
			converter->ComparisonType = Converters::ComparisonType::LessThan;
			TestZeroF<float64>( converter, []( float64 a ) { return a < 0; } );
		}
		TEST_METHOD( ConvertDoubleLessThan24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Double;
			converter->ComparisonType = Converters::ComparisonType::LessThan;
			TestNonZeroF<float64>( converter, 24, []( float64 a, float64 b ) { return a < b; } );
		}

		TEST_METHOD( ConvertDoubleLessThanOrEqualTo0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Double;
			converter->ComparisonType = Converters::ComparisonType::LessThanOrEqualTo;
			TestZeroF<float64>( converter, []( float64 a ) { return a <= 0; } );
		}
		TEST_METHOD( ConvertDoubleLessThanOrEqualTo24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Double;
			converter->ComparisonType = Converters::ComparisonType::LessThanOrEqualTo;
			TestNonZeroF<float64>( converter, 24, []( float64 a, float64 b ) { return a <= b; } );
		}

		TEST_METHOD( ConvertDoubleGreaterThan0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Double;
			converter->ComparisonType = Converters::ComparisonType::GreaterThan;
			TestZeroF<float64>( converter, []( float64 a ) { return a > 0; } );
		}
		TEST_METHOD( ConvertDoubleGreaterThan24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Double;
			converter->ComparisonType = Converters::ComparisonType::GreaterThan;
			TestNonZeroF<float64>( converter, 24, []( float64 a, float64 b ) { return a > b; } );
		}

		TEST_METHOD( ConvertDoubleGreaterThanOrEqualTo0TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Double;
			converter->ComparisonType = Converters::ComparisonType::GreaterThanOrEqualTo;
			TestZeroF<float64>( converter, []( float64 a ) { return a >= 0; } );
		}
		TEST_METHOD( ConvertDoubleGreaterThanOrEqualTo24TestMethod )
		{
			auto converter = ref new Converters::NumberComparisonToVisibilityConveter();
			converter->NumberType = Converters::NumberType::Double;
			converter->ComparisonType = Converters::ComparisonType::GreaterThanOrEqualTo;
			TestNonZeroF<float64>( converter, 24, []( float64 a, float64 b ) { return a >= b; } );
		}

	private:
		template<typename N>
		void TestZero( Converters::NumberComparisonToVisibilityConveter^ converter, function<bool( N )> comparisonFunc )
		{
			random_device seedGenerator;
			auto getNewNumber = bind( uniform_int_distribution<N>( numeric_limits<N>::min(), numeric_limits<N>::max() ), mt19937_64( seedGenerator() ) );
			
			for( auto i = 0; i < 1000; ++i )
			{
				auto n = getNewNumber();
				auto ret = converter->Convert( n, Visibility::typeid, nullptr, nullptr );
				auto castedRet = dynamic_cast<IBox<Visibility>^>( ret );
				Assert::IsNotNull( castedRet );
				Assert::AreEqual( comparisonFunc( n ) ? Visibility::Visible : Visibility::Collapsed, castedRet->Value );
			}
		}

		template<typename N>
		void TestNonZero( Converters::NumberComparisonToVisibilityConveter^ converter, N x, function<bool( N, N )> comparisonFunc )
		{
			random_device seedGenerator;
			auto getNewNumber = bind( uniform_int_distribution<N>( numeric_limits<N>::min(), numeric_limits<N>::max() ), mt19937_64( seedGenerator() ) );

			for( auto i = 0; i < 1000; ++i )
			{
				auto n = getNewNumber();
				auto ret = converter->Convert( n, Visibility::typeid, x.ToString(), nullptr );
				auto castedRet = dynamic_cast<IBox<Visibility>^>( ret );
				Assert::IsNotNull( castedRet );
				Assert::AreEqual( comparisonFunc( n, x ) ? Visibility::Visible : Visibility::Collapsed, castedRet->Value );
			}
		}

		template<typename N>
		void TestZeroF( Converters::NumberComparisonToVisibilityConveter^ converter, function<bool( N )> comparisonFunc )
		{
			random_device seedGenerator;
			auto getNewNumber = bind( uniform_real_distribution<N>( numeric_limits<N>::min(), numeric_limits<N>::max() ), mt19937_64( seedGenerator() ) );

			for( auto i = 0; i < 1000; ++i )
			{
				auto n = getNewNumber();
				auto ret = converter->Convert( n, Visibility::typeid, nullptr, nullptr );
				auto castedRet = dynamic_cast<IBox<Visibility>^>( ret );
				Assert::IsNotNull( castedRet );
				Assert::AreEqual( comparisonFunc( n ) ? Visibility::Visible : Visibility::Collapsed, castedRet->Value );
			}
		}

		template<typename N>
		void TestNonZeroF( Converters::NumberComparisonToVisibilityConveter^ converter, N x, function<bool( N, N )> comparisonFunc )
		{
			random_device seedGenerator;
			auto getNewNumber = bind( uniform_real_distribution<N>( numeric_limits<N>::min(), numeric_limits<N>::max() ), mt19937_64( seedGenerator() ) );

			for( auto i = 0; i < 1000; ++i )
			{
				auto n = getNewNumber();
				auto ret = converter->Convert( n, Visibility::typeid, x.ToString(), nullptr );
				auto castedRet = dynamic_cast<IBox<Visibility>^>( ret );
				Assert::IsNotNull( castedRet );
				Assert::AreEqual( comparisonFunc( n, x ) ? Visibility::Visible : Visibility::Collapsed, castedRet->Value );
			}
		}
	};

} } }