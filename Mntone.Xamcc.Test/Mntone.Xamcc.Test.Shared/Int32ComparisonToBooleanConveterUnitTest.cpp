#include "pch.h"

using namespace Platform;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Mntone { namespace Xamcc { namespace Test {

	TEST_CLASS( PLATFORM_PREFIX( Int32ComparisonToBooleanConveterUnitTest ) )
	{
	public:
		TEST_METHOD( ConvertBackEqualToTestMethod )
		{
			auto converter = ref new Converters::Int32ComparisonToBooleanConveter();
			Assert::ExpectException<FailureException^>( [converter]
			{
				auto ret = converter->ConvertBack( true, int::typeid, nullptr, nullptr );
			} );
		}


		TEST_METHOD( ConvertEqualTo0TestMethod )
		{
			auto converter = ref new Converters::Int32ComparisonToBooleanConveter();
			for( int32 n = -100; n <= 100; ++n )
			{
				auto ret = converter->Convert( n, bool::typeid, nullptr, nullptr );
				auto castedRet = dynamic_cast<IBox<bool>^>( ret );
				Assert::IsNotNull( castedRet );
				if( n == 0 )
				{
					Assert::IsTrue( castedRet->Value );
				}
				else
				{
					Assert::IsFalse( castedRet->Value );
				}
			}
		}

		TEST_METHOD( ConvertEqualTo24TestMethod )
		{
			auto converter = ref new Converters::Int32ComparisonToBooleanConveter();
			auto convertParameter = 24;
			for( int32 n = -100; n <= 100; ++n )
			{
				auto ret = converter->Convert( n, bool::typeid, convertParameter.ToString(), nullptr );
				auto castedRet = dynamic_cast<IBox<bool>^>( ret );
				Assert::IsNotNull( castedRet );
				if( n == convertParameter )
				{
					Assert::IsTrue( castedRet->Value );
				}
				else
				{
					Assert::IsFalse( castedRet->Value );
				}
			}
		}


		TEST_METHOD( ConvertNotEqualTo0TestMethod )
		{
			auto converter = ref new Converters::Int32ComparisonToBooleanConveter();
			converter->ComparisonType = Converters::ComparisonType::NotEqualTo;
			for( int32 n = -100; n <= 100; ++n )
			{
				auto ret = converter->Convert( n, bool::typeid, nullptr, nullptr );
				auto castedRet = dynamic_cast<IBox<bool>^>( ret );
				Assert::IsNotNull( castedRet );
				if( n == 0 )
				{
					Assert::IsFalse( castedRet->Value );
				}
				else
				{
					Assert::IsTrue( castedRet->Value );
				}
			}
		}

		TEST_METHOD( ConvertNotEqualTo24TestMethod )
		{
			auto converter = ref new Converters::Int32ComparisonToBooleanConveter();
			converter->ComparisonType = Converters::ComparisonType::NotEqualTo;
			auto convertParameter = 24;
			for( int32 n = -100; n <= 100; ++n )
			{
				auto ret = converter->Convert( n, bool::typeid, convertParameter.ToString(), nullptr );
				auto castedRet = dynamic_cast<IBox<bool>^>( ret );
				Assert::IsNotNull( castedRet );
				if( n == convertParameter )
				{
					Assert::IsFalse( castedRet->Value );
				}
				else
				{
					Assert::IsTrue( castedRet->Value );
				}
			}
		}


		TEST_METHOD( ConvertLessThan0TestMethod )
		{
			auto converter = ref new Converters::Int32ComparisonToBooleanConveter();
			converter->ComparisonType = Converters::ComparisonType::LessThan;
			for( int32 n = -100; n <= 100; ++n )
			{
				auto ret = converter->Convert( n, bool::typeid, nullptr, nullptr );
				auto castedRet = dynamic_cast<IBox<bool>^>( ret );
				Assert::IsNotNull( castedRet );
				if( n < 0 )
				{
					Assert::IsTrue( castedRet->Value );
				}
				else
				{
					Assert::IsFalse( castedRet->Value );
				}
			}
		}

		TEST_METHOD( ConvertLessThan24TestMethod )
		{
			auto converter = ref new Converters::Int32ComparisonToBooleanConveter();
			converter->ComparisonType = Converters::ComparisonType::LessThan;
			auto convertParameter = 24;
			for( int32 n = -100; n <= 100; ++n )
			{
				auto ret = converter->Convert( n, bool::typeid, convertParameter.ToString(), nullptr );
				auto castedRet = dynamic_cast<IBox<bool>^>( ret );
				Assert::IsNotNull( castedRet );
				if( n < convertParameter )
				{
					Assert::IsTrue( castedRet->Value );
				}
				else
				{
					Assert::IsFalse( castedRet->Value );
				}
			}
		}


		TEST_METHOD( ConvertLessThanOrEqualTo0TestMethod )
		{
			auto converter = ref new Converters::Int32ComparisonToBooleanConveter();
			converter->ComparisonType = Converters::ComparisonType::LessThanOrEqualTo;
			for( int32 n = -100; n <= 100; ++n )
			{
				auto ret = converter->Convert( n, bool::typeid, nullptr, nullptr );
				auto castedRet = dynamic_cast<IBox<bool>^>( ret );
				Assert::IsNotNull( castedRet );
				if( n <= 0 )
				{
					Assert::IsTrue( castedRet->Value );
				}
				else
				{
					Assert::IsFalse( castedRet->Value );
				}
			}
		}

		TEST_METHOD( ConvertLessThanOrEqualTo24TestMethod )
		{
			auto converter = ref new Converters::Int32ComparisonToBooleanConveter();
			converter->ComparisonType = Converters::ComparisonType::LessThanOrEqualTo;
			auto convertParameter = 24;
			for( int32 n = -100; n <= 100; ++n )
			{
				auto ret = converter->Convert( n, bool::typeid, convertParameter.ToString(), nullptr );
				auto castedRet = dynamic_cast<IBox<bool>^>( ret );
				Assert::IsNotNull( castedRet );
				if( n <= convertParameter )
				{
					Assert::IsTrue( castedRet->Value );
				}
				else
				{
					Assert::IsFalse( castedRet->Value );
				}
			}
		}


		TEST_METHOD( ConvertGreaterThan0TestMethod )
		{
			auto converter = ref new Converters::Int32ComparisonToBooleanConveter();
			converter->ComparisonType = Converters::ComparisonType::GreaterThan;
			for( int32 n = -100; n <= 100; ++n )
			{
				auto ret = converter->Convert( n, bool::typeid, nullptr, nullptr );
				auto castedRet = dynamic_cast<IBox<bool>^>( ret );
				Assert::IsNotNull( castedRet );
				if( n > 0 )
				{
					Assert::IsTrue( castedRet->Value );
				}
				else
				{
					Assert::IsFalse( castedRet->Value );
				}
			}
		}

		TEST_METHOD( ConvertGreaterThan24TestMethod )
		{
			auto converter = ref new Converters::Int32ComparisonToBooleanConveter();
			converter->ComparisonType = Converters::ComparisonType::GreaterThan;
			auto convertParameter = 24;
			for( int32 n = -100; n <= 100; ++n )
			{
				auto ret = converter->Convert( n, bool::typeid, convertParameter.ToString(), nullptr );
				auto castedRet = dynamic_cast<IBox<bool>^>( ret );
				Assert::IsNotNull( castedRet );
				if( n > convertParameter )
				{
					Assert::IsTrue( castedRet->Value );
				}
				else
				{
					Assert::IsFalse( castedRet->Value );
				}
			}
		}


		TEST_METHOD( ConvertGreaterThanOrEqualTo0TestMethod )
		{
			auto converter = ref new Converters::Int32ComparisonToBooleanConveter();
			converter->ComparisonType = Converters::ComparisonType::GreaterThanOrEqualTo;
			for( int32 n = -100; n <= 100; ++n )
			{
				auto ret = converter->Convert( n, bool::typeid, nullptr, nullptr );
				auto castedRet = dynamic_cast<IBox<bool>^>( ret );
				Assert::IsNotNull( castedRet );
				if( n >= 0 )
				{
					Assert::IsTrue( castedRet->Value );
				}
				else
				{
					Assert::IsFalse( castedRet->Value );
				}
			}
		}

		TEST_METHOD( ConvertGreaterThanOrEqualTo24TestMethod )
		{
			auto converter = ref new Converters::Int32ComparisonToBooleanConveter();
			converter->ComparisonType = Converters::ComparisonType::GreaterThanOrEqualTo;
			auto convertParameter = 24;
			for( int32 n = -100; n <= 100; ++n )
			{
				auto ret = converter->Convert( n, bool::typeid, convertParameter.ToString(), nullptr );
				auto castedRet = dynamic_cast<IBox<bool>^>( ret );
				Assert::IsNotNull( castedRet );
				if( n >= convertParameter )
				{
					Assert::IsTrue( castedRet->Value );
				}
				else
				{
					Assert::IsFalse( castedRet->Value );
				}
			}
		}
	};

} } }