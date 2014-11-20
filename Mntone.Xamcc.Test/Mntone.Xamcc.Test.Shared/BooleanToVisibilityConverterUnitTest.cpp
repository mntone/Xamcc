#include "pch.h"

using namespace Platform;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Windows::UI::Xaml;

namespace Mntone { namespace Xamcc { namespace Test {

	TEST_CLASS( PLATFORM_PREFIX( BooleanToVisibilityConverterUnitTest ) )
	{
	public:
		PLATFORM_PREFIX( BooleanToVisibilityConverterUnitTest )( )
		{
			converter_ = ref new Converters::BooleanToVisibilityConverter();
			invertedConverter_ = ref new Converters::BooleanToVisibilityConverter();
			invertedConverter_->IsInversed = true;
		}

		TEST_METHOD( ConvertTrueTestMethod )
		{
			auto ret = converter_->Convert( true, Visibility::typeid, nullptr, nullptr );
			auto castedRet = dynamic_cast<IBox<Visibility>^>( ret );
			Assert::IsNotNull( castedRet );
			Assert::AreEqual( Visibility::Visible, castedRet->Value );
		}

		TEST_METHOD( ConvertFalseTestMethod )
		{
			auto ret = converter_->Convert( false, Visibility::typeid, nullptr, nullptr );
			auto castedRet = dynamic_cast<IBox<Visibility>^>( ret );
			Assert::IsNotNull( castedRet );
			Assert::AreEqual( Visibility::Collapsed, castedRet->Value );
		}

		TEST_METHOD( ConvertBackVisibleTestMethod )
		{
			auto ret = converter_->ConvertBack( Visibility::Visible, bool::typeid, nullptr, nullptr );
			auto castedRet = dynamic_cast<IBox<bool>^>( ret );
			Assert::IsNotNull( castedRet );
			Assert::IsTrue( castedRet->Value );
		}

		TEST_METHOD( ConvertBackCollapsedTestMethod )
		{
			auto ret = converter_->ConvertBack( Visibility::Collapsed, bool::typeid, nullptr, nullptr );
			auto castedRet = dynamic_cast<IBox<bool>^>( ret );
			Assert::IsNotNull( castedRet );
			Assert::IsFalse( castedRet->Value );
		}

		TEST_METHOD( InvertedConvertTrueTestMethod )
		{
			auto ret = invertedConverter_->Convert( true, Visibility::typeid, nullptr, nullptr );
			auto castedRet = dynamic_cast<IBox<Visibility>^>( ret );
			Assert::IsNotNull( castedRet );
			Assert::AreEqual( Visibility::Collapsed, castedRet->Value );
		}

		TEST_METHOD( InvertedConvertFalseTestMethod )
		{
			auto ret = invertedConverter_->Convert( false, Visibility::typeid, nullptr, nullptr );
			auto castedRet = dynamic_cast<IBox<Visibility>^>( ret );
			Assert::IsNotNull( castedRet );
			Assert::AreEqual( Visibility::Visible, castedRet->Value );
		}

		TEST_METHOD( InvertedConvertBackVisibleTestMethod )
		{
			auto ret = invertedConverter_->ConvertBack( Visibility::Visible, bool::typeid, nullptr, nullptr );
			auto castedRet = dynamic_cast<IBox<bool>^>( ret );
			Assert::IsNotNull( castedRet );
			Assert::IsFalse( castedRet->Value );
		}

		TEST_METHOD( InvertedConvertBackCollapsedTestMethod )
		{
			auto ret = invertedConverter_->ConvertBack( Visibility::Collapsed, bool::typeid, nullptr, nullptr );
			auto castedRet = dynamic_cast<IBox<bool>^>( ret );
			Assert::IsNotNull( castedRet );
			Assert::IsTrue( castedRet->Value );
		}

	private:
		Converters::BooleanToVisibilityConverter
			^ converter_,
			^ invertedConverter_;
	};

} } }