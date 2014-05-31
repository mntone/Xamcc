#include "pch.h"
#include "PageSizeStateHelper.h"
#include "include\DependencyObjectPreprocessor.h"

using namespace Platform;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Mntone::Xamcc;

PageSizeStateHelper::PageSizeStateHelper( Page^ page )
	: PageSizeVisualStateGroupName_( "PageSizeViewStates" )
	, PageSizeCompactVisualStateName_( "PageSizeCompact" )
	, PageSizeMiddleVisualStateName_( "PageSizeMiddle" )
	, PageSizeFullVisualStateName_( "PageSizeFull" )
	, WidthThresholdBetweenCompactAndMiddle_( 500.0f )
	, WidthThresholdBetweenMiddleAndFull_( 768.0f )
{
	unloadedEventToken_ = page->Unloaded += ref new RoutedEventHandler( this, &PageSizeStateHelper::OnUnloaded );
	sizeChangedEventToken_ = page->SizeChanged += ref new SizeChangedEventHandler( this, &PageSizeStateHelper::OnSizeChanged );
}

PageSizeStateHelper::PageSizeStateHelper( Page^ page, float32 widthThreashold )
	: PageSizeVisualStateGroupName_( "PageSizeViewStates" )
	, PageSizeCompactVisualStateName_( "PageSizeCompact" )
	, PageSizeMiddleVisualStateName_( "PageSizeMiddle" )
	, PageSizeFullVisualStateName_( "PageSizeFull" )
	, WidthThresholdBetweenCompactAndMiddle_( widthThreashold )
	, WidthThresholdBetweenMiddleAndFull_( widthThreashold )
{
	unloadedEventToken_ = page->Unloaded += ref new RoutedEventHandler( this, &PageSizeStateHelper::OnUnloaded );
	sizeChangedEventToken_ = page->SizeChanged += ref new SizeChangedEventHandler( this, &PageSizeStateHelper::OnSizeChanged );
}

PageSizeStateHelper::PageSizeStateHelper(
	Page^ page,
	float32 widthThreasholdBetweenCompactAndMiddle,
	float32 widthThresholdBetweenMiddleAndFull )
	: PageSizeVisualStateGroupName_( "PageSizeViewStates" )
	, PageSizeCompactVisualStateName_( "PageSizeCompact" )
	, PageSizeMiddleVisualStateName_( "PageSizeMiddle" )
	, PageSizeFullVisualStateName_( "PageSizeFull" )
	, WidthThresholdBetweenCompactAndMiddle_( widthThreasholdBetweenCompactAndMiddle )
	, WidthThresholdBetweenMiddleAndFull_( widthThresholdBetweenMiddleAndFull )
{
	unloadedEventToken_ = page->Unloaded += ref new RoutedEventHandler( this, &PageSizeStateHelper::OnUnloaded );
	sizeChangedEventToken_ = page->SizeChanged += ref new SizeChangedEventHandler( this, &PageSizeStateHelper::OnSizeChanged );
}

void PageSizeStateHelper::OnUnloaded( Object^ sender, RoutedEventArgs^ e )
{
	auto page = safe_cast<Page^>( sender );
	page->Unloaded -= unloadedEventToken_;
	page->SizeChanged -= sizeChangedEventToken_;
}

void PageSizeStateHelper::OnSizeChanged( Object^ sender, SizeChangedEventArgs^ e )
{
	auto page = safe_cast<Page^>( sender );
	const auto width = e->NewSize.Width;
	if( width <= WidthThresholdBetweenCompactAndMiddle_ )
	{
		VisualStateManager::GoToState( page, PageSizeCompactVisualStateName_, false );
	}
	else if( width <= WidthThresholdBetweenMiddleAndFull_ )
	{
		VisualStateManager::GoToState( page, PageSizeMiddleVisualStateName_, false );
	}
	else
	{
		VisualStateManager::GoToState( page, PageSizeFullVisualStateName_, false );
	}
}

String^ PageSizeStateHelper::PageSizeVisualStateGroupName::get()
{
	return PageSizeVisualStateGroupName_;
}

void PageSizeStateHelper::PageSizeVisualStateGroupName::set( String^ value )
{
	PageSizeVisualStateGroupName_ = value;
}

String^ PageSizeStateHelper::PageSizeCompactVisualStateName::get()
{
	return PageSizeCompactVisualStateName_;
}

void PageSizeStateHelper::PageSizeCompactVisualStateName::set( String^ value )
{
	PageSizeCompactVisualStateName_ = value;
}

String^ PageSizeStateHelper::PageSizeMiddleVisualStateName::get()
{
	return PageSizeMiddleVisualStateName_;
}

void PageSizeStateHelper::PageSizeMiddleVisualStateName::set( String^ value )
{
	PageSizeMiddleVisualStateName_ = value;
}

String^ PageSizeStateHelper::PageSizeFullVisualStateName::get()
{
	return PageSizeFullVisualStateName_;
}

void PageSizeStateHelper::PageSizeFullVisualStateName::set( String^ value )
{
	PageSizeFullVisualStateName_ = value;
}

float32 PageSizeStateHelper::WidthThresholdBetweenCompactAndMiddle::get()
{
	return WidthThresholdBetweenCompactAndMiddle_;
}

void PageSizeStateHelper::WidthThresholdBetweenCompactAndMiddle::set( float32 value )
{
	WidthThresholdBetweenCompactAndMiddle_ = value;
}

float32 PageSizeStateHelper::WidthThresholdBetweenMiddleAndFull::get()
{
	return WidthThresholdBetweenMiddleAndFull_;
}

void PageSizeStateHelper::WidthThresholdBetweenMiddleAndFull::set( float32 value )
{
	WidthThresholdBetweenMiddleAndFull_ = value;
}