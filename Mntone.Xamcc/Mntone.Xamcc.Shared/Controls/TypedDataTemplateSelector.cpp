#include "pch.h"
#include "TypedDataTemplateSelector.h"

using namespace Platform;
using namespace Mntone::Xamcc::Controls;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::UI::Xaml::Media;

TypedDataTemplateSelector::TypedDataTemplateSelector()
	: IsCacheEnabled_( true )
{ }

DataTemplate^ TypedDataTemplateSelector::SelectTemplateCore( Object^ item, DependencyObject^ container )
{
	auto targetKey = item ? ( "Type:" + TypeName( item->GetType() ).Name ) : DefaultTemplateKey_;
	return FindTemplate( item, targetKey, container );
}

#define CHECK( __RETURN__ ) if( ( __RETURN__ ) != nullptr ) { return( __RETURN__ ); }
DataTemplate^ TypedDataTemplateSelector::FindTemplate( Object^ item, String^ targetKey, DependencyObject^ container )
{
	DataTemplate^ ret;
	if( IsCacheEnabled_ )
	{
		ret = FindCachingTemplate( targetKey );
		CHECK( ret );
	}

	if( container != nullptr )
	{
		auto frameworkElement = dynamic_cast<FrameworkElement^>( container );
		while( frameworkElement != nullptr )
		{
			ret = FindTemplate( frameworkElement->Resources, targetKey );
			CHECK( ret );

			frameworkElement = dynamic_cast<FrameworkElement^>( VisualTreeHelper::GetParent( frameworkElement ) );
		}
	}
	
	ret = FindTemplate( Application::Current->Resources, targetKey );
	CHECK( ret );

	if( targetKey != DefaultTemplateKey_ )
	{
		ret = FindTemplate( item, DefaultTemplateKey_, container );
		if( ret == nullptr )
		{
			throw ref new FailureException();
		}
	}
	return ret;
}

DataTemplate^ TypedDataTemplateSelector::FindTemplate( ResourceDictionary^ resourceDictionary, String^ key )
{
	if( resourceDictionary->HasKey( key ) )
	{
		return dynamic_cast<DataTemplate^>( resourceDictionary->Lookup( key ) );
	}
	return nullptr;
}

DataTemplate^ TypedDataTemplateSelector::FindCachingTemplate( String^ key )
{
	auto ret = templateMap_.find( key );
	if( ret != templateMap_.end() )
	{
		return ret->second;
	}
	return nullptr;
}

void TypedDataTemplateSelector::IsCacheEnabled::set( bool value )
{
	if( IsCacheEnabled_ != value )
	{
		IsCacheEnabled_ = value;

		templateMap_.clear();
	}
}