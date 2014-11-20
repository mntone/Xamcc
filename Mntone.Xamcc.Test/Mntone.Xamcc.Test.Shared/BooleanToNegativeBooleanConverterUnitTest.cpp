#include "pch.h"

using namespace Platform;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Mntone { namespace Xamcc { namespace Test {

	TEST_CLASS( PLATFORM_PREFIX( BooleanToNegativeBooleanConverterUnitTest ) )
	{
	public:
		PLATFORM_PREFIX( BooleanToNegativeBooleanConverterUnitTest )()
		{
			converter_ = ref new Converters::BooleanToNegativeBooleanConverter();
		}

		TEST_METHOD( ConvertTrueTestMethod )
		{
			auto ret = converter_->Convert( true, bool::typeid, nullptr, nullptr );
			auto castedRet = dynamic_cast<IBox<bool>^>( ret );
			Assert::IsNotNull( castedRet );
			Assert::IsFalse( castedRet->Value );
		}

		TEST_METHOD( ConvertFalseTestMethod )
		{
			auto ret = converter_->Convert( false, bool::typeid, nullptr, nullptr );
			auto castedRet = dynamic_cast<IBox<bool>^>( ret );
			Assert::IsNotNull( castedRet );
			Assert::IsTrue( castedRet->Value );
		}

		TEST_METHOD( ConvertBackTrueTestMethod )
		{
			auto ret = converter_->ConvertBack( true, bool::typeid, nullptr, nullptr );
			auto castedRet = dynamic_cast<IBox<bool>^>( ret );
			Assert::IsNotNull( castedRet );
			Assert::IsFalse( castedRet->Value );
		}

		TEST_METHOD( ConvertBackFalseTestMethod )
		{
			auto ret = converter_->ConvertBack( false, bool::typeid, nullptr, nullptr );
			auto castedRet = dynamic_cast<IBox<bool>^>( ret );
			Assert::IsNotNull( castedRet );
			Assert::IsTrue( castedRet->Value );
		}

	private:
		Converters::BooleanToNegativeBooleanConverter^ converter_;
	};

} } }