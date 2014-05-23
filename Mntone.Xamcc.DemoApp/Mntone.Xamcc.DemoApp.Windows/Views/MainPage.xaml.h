#pragma once
#include "Views/MainPage.g.h"

namespace Mntone { namespace Xamcc { namespace DemoApp { namespace Views {

	public ref class MainPage sealed
	{
	public:
		MainPage();

	public:
		property Mntone::Xamcc::NavigationHelper^ NavigationHelper
		{
			Mntone::Xamcc::NavigationHelper^ get();
			void set( Mntone::Xamcc::NavigationHelper^ value );
		}

	private:
		static Windows::UI::Xaml::DependencyProperty^ NavigationHelperProperty_;
	};

} } } }