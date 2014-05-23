#pragma once
#include "MainPageViewModel.h"

namespace Mntone { namespace Xamcc { namespace DemoApp { namespace ViewModels {

	[Windows::UI::Xaml::Data::Bindable]
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class ViewModelLocator sealed
		: public Windows::UI::Xaml::DependencyObject
	{
	public:
		ViewModelLocator();

	public:
		property MainPageViewModel^ MainPage
		{
			MainPageViewModel^ get();
		}
	};

} } } }