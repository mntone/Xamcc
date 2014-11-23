# Xamcc
Xamcc is MVVM toolkit for C++/CX.

Support platforms:

- Windows 8.1/Windows Server 2012 R2
- Windows Phone 8.1

## License
This component and demo application is under “MIT license.”

## Avaliable
- Property/DependencyObject Preprocessor
- Command support (Support STL functional.)
- M to VM vector (Support Vector)
- Commonly used behavior and converters

## Sample code

### Model vector to ViewModel vector
	EventWrapper<IObservableVector<DateTime>>^ eventWrapper;
	ViewModelCollection = ViewModelHelper::CreateDispatcherVector<DateTime, String^>(
	  processor_.GetVector(),
	  []( DateTime from ) { return DateTimeFormatter::LongTime->Format( from ); },
	  dispatcher,
	  &eventWrapper );

### Number Comparison converter
	<Grid>
	  <Grid.Resources>
	    <converters:NumberComparisonToVisibilityConveter
	      x:Key="EqualToParameterToVisibilityConverter"
	      NumberType="Int32"
	      ComparisonType="EqualTo" />
	  </Grid.Resources>
	  <Border
	    Background="Red"
	    Visibility="{Binding Age, Converter={StaticResource equalToParameterToVisibilityConverter}, ConverterParameter=2, Mode=OneWay}" />
	  <!-- Visible Border object when Age == 2. -->
	</Grid>

### Typed DateTemplate selector
	<Grid>
	  <Grid.Resources>
	    <controls:TypedDataTemplateSelector x:Key="TypedDataTemplateSelector" />
	  </Grid.Resources>
	  <ListView
	    ItemTemplateSelector="{StaticResource TypedDataTemplateSelector}"
	    ItemsSource="{Binding XCollectiton}">
	    <ListView.Resources>
	      <DataTemplate x:Key="Type:X.AObject">
	        <Border Margin="5">
	  	      <TextBlock Text="A" />
	        </Border>
	      </DataTemplate>
	      <DataTemplate x:Key="Type:X.BObject">
	        <Border Margin="5">
		      <TextBlock Text="B" />
		    </Border>
		  </DataTemplate>
	    </ListView.Resources>
	  </ListView>
	</Grid>

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