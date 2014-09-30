# Xamcc
Xamcc is MVVM infrastructure for C++/CX.

Support platforms:

- Windows 8.1/Windows Server 2012 R2
- Windows Phone 8.1

## License
This component and demoapp is “MIT license.”

## Avaliable
- DependencyObject/Property Preprocessor
- Command support (Support STL functional.)
- M to VM vector (Support Vector and C++/CX Helper Deque.)

## Sample code

### Model vector to ViewModel vector
	ViewModelCollection = ViewModelHelper::CreateDispatcherVector<Windows::Foundation::DateTime, String^>(
	  processor_.GetVector(),
	  []( Windows::Foundation::DateTime from )
	  {
	    using namespace Windows::Globalization::DateTimeFormatting;
	    return ( ref new DateTimeFormatter( "longtime" ) )->Format( from );
	  },
	  dispatcher );

### Binding window title (Windows only)
	<Page
	  xmlns:i="using:Microsoft.Xaml.Interactivity"
	  xmlns:b="using:Mntone.Xamcc.Interactions">
	  <i:Interaction.Behaviors>
	    <b:WindowTitleBehavior IsEnabled="{Binding IsTitleEnabled}" Title="{Binding Title}" />
	  </i:Interaction.Behaviors>
	</Page>


### Binding progress indicator (Windows Phone only)
	<Page
	  xmlns:i="using:Microsoft.Xaml.Interactivity"
	  xmlns:b="using:Mntone.Xamcc.Interactions">
	  <i:Interaction.Behaviors>
	    <b:ProgressIndicatorBehavior
	      IsEnabled="{Binding IsIndicatorEnabled}"
	      IsIndeterminate="{Binding IsIndicatorIndeterminate}"
	      Text="{Binding IndicatorMessage}"
	      Minimum="{Binding IndicatorMinValue}"
	      Maximum="{Binding IndicatorMaxValue}"
	      Value="{Binding IndicatorCurrentValue}" />
	  </i:Interaction.Behaviors>
	</Page>

# Related project
- [C++/CX Helper](//github.com/mntone/CppCx-Helper)