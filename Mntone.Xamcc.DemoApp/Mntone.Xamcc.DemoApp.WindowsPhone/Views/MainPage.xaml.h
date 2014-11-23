#pragma once
#include "Views\MainPage.g.h"
#include "Core\FavoriteNotification.h"
#include "Core\FollowNotification.h"

namespace Mntone { namespace Xamcc { namespace DemoApp { namespace Views {

	public ref class MainPage sealed
	{
	public:
		MainPage();

	protected:
		virtual void OnNavigatedTo( ::Windows::UI::Xaml::Navigation::NavigationEventArgs^ e ) override sealed;
		virtual void OnNavigatedFrom( ::Windows::UI::Xaml::Navigation::NavigationEventArgs^ e ) override sealed;

	public:
		property Mntone::Xamcc::NavigationHelper^ NavigationHelper
		{
			Mntone::Xamcc::NavigationHelper^ get();
			void set( Mntone::Xamcc::NavigationHelper^ value );
		}

	private:
		::Microsoft::Xaml::Interactivity::BehaviorCollection^ bc_;

		static Windows::UI::Xaml::DependencyProperty^ NavigationHelperProperty_;
	};

} } } }