#pragma once

namespace Mntone { namespace Xamcc { namespace DemoApp { namespace ViewModels {

	ref class MainPageViewModel;

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