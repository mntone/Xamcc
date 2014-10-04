#pragma once
#include "App.g.h"

namespace Mntone { namespace Xamcc { namespace DemoApp {

	ref class App sealed
	{
	public:
		App();

	private:
		//~App();

	protected:
		virtual void OnLaunched( Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ e ) override sealed;

	private:
		void OnNavigationFailed( Platform::Object^ sender, Windows::UI::Xaml::Navigation::NavigationFailedEventArgs^ e );
		void OnSuspending( Platform::Object^ sender, Windows::ApplicationModel::SuspendingEventArgs^ e );

#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
		void OnNavigated( Platform::Object^ sender, Windows::UI::Xaml::Navigation::NavigationEventArgs^ e );
#endif

	private:
		//Windows::Foundation::EventRegistrationToken suspendingEventToken_;

#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
		Windows::Foundation::EventRegistrationToken navigatedEventToken_;
		Windows::UI::Xaml::Media::Animation::TransitionCollection^ transitions_;
#endif
	};

} } }