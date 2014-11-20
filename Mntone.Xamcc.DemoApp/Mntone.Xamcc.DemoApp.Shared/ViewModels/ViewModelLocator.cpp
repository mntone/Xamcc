#include "pch.h"
#include "ViewModelLocator.h"
#include "MainPageViewModel.h"

using namespace Windows::UI::Xaml;
using namespace Mntone::Xamcc::DemoApp::ViewModels;

ViewModelLocator::ViewModelLocator()
{ }

MainPageViewModel^ ViewModelLocator::MainPage::get()
{
	return ref new MainPageViewModel( Window::Current->Dispatcher );
}