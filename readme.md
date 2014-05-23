# Xamcc
Xamcc is MVVM infrastructure for C++/CX.

Support platforms:

- Windows 8.1/Windows Server 2012 R2
- Windows Phone 8.1

## License
This component and demoapp is “MIT license.”

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