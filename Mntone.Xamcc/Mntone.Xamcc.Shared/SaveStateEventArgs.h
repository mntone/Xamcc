#pragma once

namespace Mntone { namespace Xamcc {

	public ref class SaveStateEventArgs sealed
	{
	public:
		SaveStateEventArgs( Windows::Foundation::Collections::IMap<Platform::String^, Platform::Object^>^ pageState );

	public:		
		property Windows::Foundation::Collections::IMap<Platform::String^, Platform::Object^>^ PageState
		{
			Windows::Foundation::Collections::IMap<Platform::String^, Platform::Object^>^ get();
		}

	private:
		Windows::Foundation::Collections::IMap<Platform::String^, Platform::Object^>^ pageState_;
	};

} }