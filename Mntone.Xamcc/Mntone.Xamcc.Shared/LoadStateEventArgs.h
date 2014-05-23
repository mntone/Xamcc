#pragma once

namespace Mntone { namespace Xamcc {

	public ref class LoadStateEventArgs sealed
	{
	public:
		LoadStateEventArgs(
			Platform::Object^ navigationParameter,
			Windows::Foundation::Collections::IMap<Platform::String^, Platform::Object^>^ pageState );

	public:
		property Platform::Object^ NavigationParameter
		{
			Platform::Object^ get();
		}
		property Windows::Foundation::Collections::IMap<Platform::String^, Platform::Object^>^ PageState
		{
			Windows::Foundation::Collections::IMap<Platform::String^, Platform::Object^>^ get();
		}

	private:
		Platform::Object^ navigationParameter_;
		Windows::Foundation::Collections::IMap<Platform::String^, Platform::Object^>^ pageState_;
	};

} }