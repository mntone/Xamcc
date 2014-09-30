#include "pch.h"
#include "MainPageViewModel.h"

using namespace Mntone::Xamcc::Commands;
using namespace Platform;
using namespace Windows::UI::Core;
using namespace Windows::UI::Popups;
using namespace Windows::UI::Xaml;
using namespace Mntone::Xamcc::DemoApp::ViewModels;

MainPageViewModel::MainPageViewModel( CoreDispatcher^ dispatcher )
	: dispatcherHelper_( ref new DispatcherHelper( dispatcher ) )
{
	ButtonCommand = ref new RelayCommand(
		[]( Object^ ) { ( ref new MessageDialog( "Clicked!" ) )->ShowAsync(); },
		[this]( Object^ ) { return IsButtonEnabled; } );
	ButtonAlwaysCanExecuteCommand = ref new RelayCommand(
		[]( Object^ ) { ( ref new MessageDialog( "Clicked!" ) )->ShowAsync(); } );

	ViewModelCollection = ViewModelHelper::CreateDispatcherVector<Windows::Foundation::DateTime, String^>(
		processor_.GetVector(),
		[]( Windows::Foundation::DateTime from )
		{
			using namespace Windows::Globalization::DateTimeFormatting;
			return ( ref new DateTimeFormatter( "longtime" ) )->Format( from );
		},
		dispatcher );
	ViewModelCollection2 = ViewModelHelper::CreateDispatcherDeque<Windows::Foundation::DateTime, String^>(
		processor_.GetDeque(),
		[]( Windows::Foundation::DateTime from )
		{
			using namespace Windows::Globalization::DateTimeFormatting;
			return ( ref new DateTimeFormatter( "longtime" ) )->Format( from );
		},
		dispatcher );
}

void MainPageViewModel::OnIsButtonEnabledPropertyChanged( DependencyObject^ d, DependencyPropertyChangedEventArgs^ e )
{
	auto that = dynamic_cast<MainPageViewModel^>( d );
	if( that != nullptr )
	{
		that->ButtonCommand->RaiseCanExecuteChanged();
	}
}

IMPL_DP_GETSET( MainPageViewModel, String, ButtonMessage, PropertyMetadata::Create( "Click me" ) )
IMPL_DP_VALUE_GETSET( MainPageViewModel, bool, IsButtonEnabled,
	PropertyMetadata::Create( true, ref new PropertyChangedCallback( &MainPageViewModel::OnIsButtonEnabledPropertyChanged ) ) )
IMPL_DP_GETSET( MainPageViewModel, RelayCommand, ButtonCommand, nullptr )
IMPL_DP_GETSET( MainPageViewModel, RelayCommand, ButtonAlwaysCanExecuteCommand, nullptr )
IMPL_DP_GETSET( MainPageViewModel, Collections::Vector<String^>, ViewModelCollection, nullptr )
IMPL_DP_GETSET( MainPageViewModel, Collections::Deque<String^>, ViewModelCollection2, nullptr )

#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
IMPL_DP_VALUE_GETSET( MainPageViewModel, bool, IsIndicatorEnabled, PropertyMetadata::Create( false ) )
IMPL_DP_VALUE_GETSET( MainPageViewModel, bool, IsIndicatorIndeterminate, PropertyMetadata::Create( false ) )
IMPL_DP_GETSET( MainPageViewModel, String, IndicatorMessage, PropertyMetadata::Create( "LoadingÅc" ) )
IMPL_DP_VALUE_GETSET( MainPageViewModel, float, IndicatorMinValue, PropertyMetadata::Create( 0.f ) )
IMPL_DP_VALUE_GETSET( MainPageViewModel, float, IndicatorMaxValue, PropertyMetadata::Create( 1.f ) )
IMPL_DP_VALUE_GETSET( MainPageViewModel, float, IndicatorCurrentValue, PropertyMetadata::Create( 0.5f ) )
#endif