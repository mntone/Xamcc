#include "pch.h"
#include "MainPage.xaml.h"

using namespace Mntone::Xamcc::DemoApp::Views;

MainPage::MainPage()
{
	InitializeComponent();
}

void MainPage::OnNavigatedTo( ::Windows::UI::Xaml::Navigation::NavigationEventArgs^ e )
{
	NavigationHelper = ref new Mntone::Xamcc::NavigationHelper( this );
	pageSizeStateHelper_ = ref new Mntone::Xamcc::PageSizeStateHelper( this, 640, 1024 );

	using namespace Mntone::Xamcc::Interactions;
	using namespace Windows::UI::Xaml;
	using namespace Windows::UI::Xaml::Data;

	auto wtb = ref new WindowTitleBehavior();
	auto b = ref new Binding();
	b->Path = ref new PropertyPath( "IsTitleEnabled" );
	b->Source = DataContext;
	b->Mode = BindingMode::OneWay;
	BindingOperations::SetBinding( wtb, WindowTitleBehavior::IsEnabledProperty, b );
	auto b2 = ref new Binding();
	b2->Path = ref new PropertyPath( "Title" );
	b2->Source = DataContext;
	b2->Mode = BindingMode::OneWay;
	BindingOperations::SetBinding( wtb, WindowTitleBehavior::TitleProperty, b2 );

	auto ica = ref new Microsoft::Xaml::Interactions::Core::InvokeCommandAction();
	auto b3 = ref new Binding();
	b3->Path = ref new PropertyPath( "F5Command" );
	b3->Source = DataContext;
	b3->Mode = BindingMode::OneWay;
	BindingOperations::SetBinding( ica, Microsoft::Xaml::Interactions::Core::InvokeCommandAction::CommandProperty, b3 );
	auto kbc = ref new KeyTriggerBehavior();
	kbc->Key = Windows::System::VirtualKey::F5;
	kbc->Actions->Append( ica );

	bc_ = ref new Microsoft::Xaml::Interactivity::BehaviorCollection();
	bc_->Append( wtb );
	bc_->Append( kbc );
	bc_->Attach( this );
}

void MainPage::OnNavigatedFrom( ::Windows::UI::Xaml::Navigation::NavigationEventArgs^ e )
{
	bc_->Detach();
	bc_ = nullptr;
}

IMPL_DP_GETSET( MainPage, Mntone::Xamcc::NavigationHelper, NavigationHelper, nullptr )