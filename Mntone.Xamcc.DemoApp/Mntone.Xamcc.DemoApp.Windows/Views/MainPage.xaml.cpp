#include "pch.h"
#include "MainPage.xaml.h"

using namespace Mntone::Xamcc::DemoApp::Views;

MainPage::MainPage()
{
	InitializeComponent();

	NavigationHelper = ref new Mntone::Xamcc::NavigationHelper( this );
	pageSizeStateHelper_ = ref new Mntone::Xamcc::PageSizeStateHelper( this, 640, 1024 );
}

IMPL_DP_GETSET( MainPage, Mntone::Xamcc::NavigationHelper, NavigationHelper, nullptr )