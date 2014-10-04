#include "pch.h"
#include "App.xaml.h"

using namespace Platform;
using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::Foundation;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Interop;
using namespace Mntone::Xamcc::DemoApp;

#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
using namespace Windows::UI::Xaml::Media::Animation;
using namespace Windows::UI::Xaml::Navigation;
#endif

namespace Mntone { namespace Xamcc { namespace DemoApp { namespace Views {

	ref class MainPage;

} } } }

App::App()
{
	InitializeComponent();

	/*suspendingEventToken_ =*/ Suspending += ref new SuspendingEventHandler( this, &App::OnSuspending );
}

void App::OnLaunched( LaunchActivatedEventArgs^ e )
{
#if _DEBUG
	if( IsDebuggerPresent() )
	{
		DebugSettings->EnableFrameRateCounter = true;
	}
#endif

	auto rootFrame = dynamic_cast<Frame^>( Window::Current->Content );
	if( rootFrame == nullptr )
	{
		rootFrame = ref new Frame();
		rootFrame->CacheSize = 1;
		rootFrame->Language = Windows::Globalization::ApplicationLanguages::Languages->GetAt( 0 );
		Window::Current->Content = rootFrame;
	}
	if( rootFrame->Content == nullptr )
	{
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
		if( rootFrame->ContentTransitions != nullptr )
		{
			transitions_ = ref new TransitionCollection();
			for( auto&& transition : rootFrame->ContentTransitions )
			{
				transitions_->Append( transition );
			}
			rootFrame->ContentTransitions = nullptr;
		}
		navigatedEventToken_ = rootFrame->Navigated += ref new NavigatedEventHandler( this, &App::OnNavigated );
#endif

		if( !rootFrame->Navigate( Views::MainPage::typeid, e->Arguments ) )
		{
			throw ref new FailureException( "Failed to create initial page." );
		}
	}
	Window::Current->Activate();
}

#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
void App::OnNavigated( Object^ sender, NavigationEventArgs^ e )
{
	auto rootFrame = safe_cast<Frame^>( sender );
	rootFrame->Navigated -= navigatedEventToken_;

	if( transitions_ == nullptr )
	{
		transitions_ = ref new TransitionCollection();
		transitions_->Append( ref new NavigationThemeTransition() );
	}
	rootFrame->ContentTransitions = transitions_;
}
#endif

void App::OnSuspending( Object^ sender, SuspendingEventArgs^ e )
{ }