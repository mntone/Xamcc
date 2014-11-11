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

	using namespace Mntone::Xamcc::Interactions;
	using namespace Windows::UI::Xaml;
	using namespace Windows::UI::Xaml::Data;

	auto pib = ref new ProgressIndicatorBehavior();

	auto b = ref new Binding();
	b->Path = ref new PropertyPath( "IsIndicatorEnabled" );
	b->Source = DataContext;
	b->Mode = BindingMode::OneWay;
	BindingOperations::SetBinding( pib, ProgressIndicatorBehavior::IsEnabledProperty, b );

	auto b2 = ref new Binding();
	b2->Path = ref new PropertyPath( "IsIndicatorIndeterminate" );
	b2->Source = DataContext;
	b2->Mode = BindingMode::OneWay;
	BindingOperations::SetBinding( pib, ProgressIndicatorBehavior::IsIndeterminateProperty, b2 );

	auto b3 = ref new Binding();
	b3->Path = ref new PropertyPath( "IndicatorMessage" );
	b3->Source = DataContext;
	b3->Mode = BindingMode::OneWay;
	BindingOperations::SetBinding( pib, ProgressIndicatorBehavior::TextProperty, b3 );

	auto b4 = ref new Binding();
	b4->Path = ref new PropertyPath( "IndicatorMinValue" );
	b4->Source = DataContext;
	b4->Mode = BindingMode::OneWay;
	BindingOperations::SetBinding( pib, ProgressIndicatorBehavior::MinimumProperty, b4 );

	auto b5 = ref new Binding();
	b5->Path = ref new PropertyPath( "IndicatorMaxValue" );
	b5->Source = DataContext;
	b5->Mode = BindingMode::OneWay;
	BindingOperations::SetBinding( pib, ProgressIndicatorBehavior::MaximumProperty, b5 );

	auto b6 = ref new Binding();
	b6->Path = ref new PropertyPath( "IndicatorCurrentValue" );
	b6->Source = DataContext;
	b6->Mode = BindingMode::OneWay;
	BindingOperations::SetBinding( pib, ProgressIndicatorBehavior::ValueProperty, b6 );

	bc_ = ref new Microsoft::Xaml::Interactivity::BehaviorCollection();
	bc_->Append( pib );
	bc_->Attach( this );
}

void MainPage::OnNavigatedFrom( ::Windows::UI::Xaml::Navigation::NavigationEventArgs^ e )
{
	bc_->Detach();
	bc_ = nullptr;
}

IMPL_DP_GETSET( MainPage, Mntone::Xamcc::NavigationHelper, NavigationHelper, nullptr )