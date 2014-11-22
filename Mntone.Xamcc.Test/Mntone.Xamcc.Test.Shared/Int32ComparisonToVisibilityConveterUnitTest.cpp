#include "pch.h"

#pragma warning( disable: 4973 )

using namespace Platform;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Windows::UI::Xaml;

namespace Mntone { namespace Xamcc { namespace Test {

	TEST_CLASS( PLATFORM_PREFIX( Int32ComparisonToVisibilityConveterUnitTest ) )
	{
	public:
		TEST_METHOD( ConvertBackEqualToTestMethod )
		{
			auto converter = ref new Converters::Int32ComparisonToVisibilityConveter();
			Assert::ExpectException<FailureException^>( [converter]
			{
				auto ret = converter->ConvertBack( true, int::typeid, nullptr, nullptr );
			} );
		}


		TEST_METHOD( ConvertEqualTo0TestMethod )
		{
			auto converter = ref new Converters::Int32ComparisonToVisibilityConveter();
			for( int32 n = -100; n <= 100; ++n )
			{
				auto ret = converter->Convert( n, Visibility::typeid, nullptr, nullptr );
				auto castedRet = dynamic_cast<IBox<Visibility>^>( ret );
				Assert::IsNotNull( castedRet );
				if( n == 0 )
				{
					Assert::AreEqual( Visibility::Visible, castedRet->Value );
				}
				else
				{
					Assert::AreEqual( Visibility::Collapsed, castedRet->Value );
				}
			}
		}

		TEST_METHOD( ConvertEqualTo24TestMethod )
		{
			auto converter = ref new Converters::Int32ComparisonToVisibilityConveter();
			auto convertParameter = 24;
			for( int32 n = -100; n <= 100; ++n )
			{
				auto ret = converter->Convert( n, Visibility::typeid, convertParameter.ToString(), nullptr );
				auto castedRet = dynamic_cast<IBox<Visibility>^>( ret );
				Assert::IsNotNull( castedRet );
				if( n == convertParameter )
				{
					Assert::AreEqual( Visibility::Visible, castedRet->Value );
				}
				else
				{
					Assert::AreEqual( Visibility::Collapsed, castedRet->Value );
				}
			}
		}


		TEST_METHOD( ConvertNotEqualTo0TestMethod )
		{
			auto converter = ref new Converters::Int32ComparisonToVisibilityConveter();
			converter->ComparisonType = Converters::ComparisonType::NotEqualTo;
			for( int32 n = -100; n <= 100; ++n )
			{
				auto ret = converter->Convert( n, Visibility::typeid, nullptr, nullptr );
				auto castedRet = dynamic_cast<IBox<Visibility>^>( ret );
				Assert::IsNotNull( castedRet );
				if( n != 0 )
				{
					Assert::AreEqual( Visibility::Visible, castedRet->Value );
				}
				else
				{
					Assert::AreEqual( Visibility::Collapsed, castedRet->Value );
				}
			}
		}

		TEST_METHOD( ConvertNotEqualTo24TestMethod )
		{
			auto converter = ref new Converters::Int32ComparisonToVisibilityConveter();
			converter->ComparisonType = Converters::ComparisonType::NotEqualTo;
			auto convertParameter = 24;
			for( int32 n = -100; n <= 100; ++n )
			{
				auto ret = converter->Convert( n, Visibility::typeid, convertParameter.ToString(), nullptr );
				auto castedRet = dynamic_cast<IBox<Visibility>^>( ret );
				Assert::IsNotNull( castedRet );
				if( n != convertParameter )
				{
					Assert::AreEqual( Visibility::Visible, castedRet->Value );
				}
				else
				{
					Assert::AreEqual( Visibility::Collapsed, castedRet->Value );
				}
			}
		}


		TEST_METHOD( ConvertLessThan0TestMethod )
		{
			auto converter = ref new Converters::Int32ComparisonToVisibilityConveter();
			converter->ComparisonType = Converters::ComparisonType::LessThan;
			for( int32 n = -100; n <= 100; ++n )
			{
				auto ret = converter->Convert( n, Visibility::typeid, nullptr, nullptr );
				auto castedRet = dynamic_cast<IBox<Visibility>^>( ret );
				Assert::IsNotNull( castedRet );
				if( n < 0 )
				{
					Assert::AreEqual( Visibility::Visible, castedRet->Value );
				}
				else
				{
					Assert::AreEqual( Visibility::Collapsed, castedRet->Value );
				}
			}
		}

		TEST_METHOD( ConvertLessThan24TestMethod )
		{
			auto converter = ref new Converters::Int32ComparisonToVisibilityConveter();
			converter->ComparisonType = Converters::ComparisonType::LessThan;
			auto convertParameter = 24;
			for( int32 n = -100; n <= 100; ++n )
			{
				auto ret = converter->Convert( n, Visibility::typeid, convertParameter.ToString(), nullptr );
				auto castedRet = dynamic_cast<IBox<Visibility>^>( ret );
				Assert::IsNotNull( castedRet );
				if( n < convertParameter )
				{
					Assert::AreEqual( Visibility::Visible, castedRet->Value );
				}
				else
				{
					Assert::AreEqual( Visibility::Collapsed, castedRet->Value );
				}
			}
		}


		TEST_METHOD( ConvertLessThanOrEqualTo0TestMethod )
		{
			auto converter = ref new Converters::Int32ComparisonToVisibilityConveter();
			converter->ComparisonType = Converters::ComparisonType::LessThanOrEqualTo;
			for( int32 n = -100; n <= 100; ++n )
			{
				auto ret = converter->Convert( n, Visibility::typeid, nullptr, nullptr );
				auto castedRet = dynamic_cast<IBox<Visibility>^>( ret );
				Assert::IsNotNull( castedRet );
				if( n <= 0 )
				{
					Assert::AreEqual( Visibility::Visible, castedRet->Value );
				}
				else
				{
					Assert::AreEqual( Visibility::Collapsed, castedRet->Value );
				}
			}
		}

		TEST_METHOD( ConvertLessThanOrEqualTo24TestMethod )
		{
			auto converter = ref new Converters::Int32ComparisonToVisibilityConveter();
			converter->ComparisonType = Converters::ComparisonType::LessThanOrEqualTo;
			auto convertParameter = 24;
			for( int32 n = -100; n <= 100; ++n )
			{
				auto ret = converter->Convert( n, Visibility::typeid, convertParameter.ToString(), nullptr );
				auto castedRet = dynamic_cast<IBox<Visibility>^>( ret );
				Assert::IsNotNull( castedRet );
				if( n <= convertParameter )
				{
					Assert::AreEqual( Visibility::Visible, castedRet->Value );
				}
				else
				{
					Assert::AreEqual( Visibility::Collapsed, castedRet->Value );
				}
			}
		}


		TEST_METHOD( ConvertGreaterThan0TestMethod )
		{
			auto converter = ref new Converters::Int32ComparisonToVisibilityConveter();
			converter->ComparisonType = Converters::ComparisonType::GreaterThan;
			for( int32 n = -100; n <= 100; ++n )
			{
				auto ret = converter->Convert( n, Visibility::typeid, nullptr, nullptr );
				auto castedRet = dynamic_cast<IBox<Visibility>^>( ret );
				Assert::IsNotNull( castedRet );
				if( n > 0 )
				{
					Assert::AreEqual( Visibility::Visible, castedRet->Value );
				}
				else
				{
					Assert::AreEqual( Visibility::Collapsed, castedRet->Value );
				}
			}
		}

		TEST_METHOD( ConvertGreaterThan24TestMethod )
		{
			auto converter = ref new Converters::Int32ComparisonToVisibilityConveter();
			converter->ComparisonType = Converters::ComparisonType::GreaterThan;
			auto convertParameter = 24;
			for( int32 n = -100; n <= 100; ++n )
			{
				auto ret = converter->Convert( n, Visibility::typeid, convertParameter.ToString(), nullptr );
				auto castedRet = dynamic_cast<IBox<Visibility>^>( ret );
				Assert::IsNotNull( castedRet );
				if( n > convertParameter )
				{
					Assert::AreEqual( Visibility::Visible, castedRet->Value );
				}
				else
				{
					Assert::AreEqual( Visibility::Collapsed, castedRet->Value );
				}
			}
		}


		TEST_METHOD( ConvertGreaterThanOrEqualTo0TestMethod )
		{
			auto converter = ref new Converters::Int32ComparisonToVisibilityConveter();
			converter->ComparisonType = Converters::ComparisonType::GreaterThanOrEqualTo;
			for( int32 n = -100; n <= 100; ++n )
			{
				auto ret = converter->Convert( n, Visibility::typeid, nullptr, nullptr );
				auto castedRet = dynamic_cast<IBox<Visibility>^>( ret );
				Assert::IsNotNull( castedRet );
				if( n >= 0 )
				{
					Assert::AreEqual( Visibility::Visible, castedRet->Value );
				}
				else
				{
					Assert::AreEqual( Visibility::Collapsed, castedRet->Value );
				}
			}
		}

		TEST_METHOD( ConvertGreaterThanOrEqualTo24TestMethod )
		{
			auto converter = ref new Converters::Int32ComparisonToVisibilityConveter();
			converter->ComparisonType = Converters::ComparisonType::GreaterThanOrEqualTo;
			auto convertParameter = 24;
			for( int32 n = -100; n <= 100; ++n )
			{
				auto ret = converter->Convert( n, Visibility::typeid, convertParameter.ToString(), nullptr );
				auto castedRet = dynamic_cast<IBox<Visibility>^>( ret );
				Assert::IsNotNull( castedRet );
				if( n >= convertParameter )
				{
					Assert::AreEqual( Visibility::Visible, castedRet->Value );
				}
				else
				{
					Assert::AreEqual( Visibility::Collapsed, castedRet->Value );
				}
			}
		}
	};

} } }