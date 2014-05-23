#include "pch.h"
#include "MainPage.xaml.h"

using namespace Mntone::Xamcc::DemoApp::Views;

MainPage::MainPage()
{
	InitializeComponent();

	NavigationHelper = ref new Mntone::Xamcc::NavigationHelper( this );
}

IMPL_DP_GETSET( MainPage, Mntone::Xamcc::NavigationHelper, NavigationHelper, nullptr )