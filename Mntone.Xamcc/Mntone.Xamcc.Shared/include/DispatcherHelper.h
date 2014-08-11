#pragma once
#include <functional>

namespace Mntone { namespace Xamcc { 

	[::Windows::Foundation::Metadata::WebHostHidden]
	public ref class DispatcherHelper sealed
	{
	internal:
		DispatcherHelper()
			: Dispatcher_( nullptr )
		{ }

		DispatcherHelper( ::Windows::UI::Core::CoreDispatcher^ dispatcher )
			: Dispatcher_( dispatcher )
		{ }

		inline Windows::Foundation::IAsyncAction^ InvokeAsync( std::function<void()> func )
		{
			if( !Dispatcher_->HasThreadAccess )
			{
				return Dispatcher_->RunAsync(
					::Windows::UI::Core::CoreDispatcherPriority::Normal,
					ref new ::Windows::UI::Core::DispatchedHandler( func ) );
			}

			func();
			return nullptr;
		}

		inline Windows::Foundation::IAsyncAction^ InvokeAsync( ::Windows::UI::Core::CoreDispatcherPriority priority, std::function<void()> func )
		{
			if( !Dispatcher_->HasThreadAccess )
			{
				return Dispatcher_->RunAsync( priority, ref new ::Windows::UI::Core::DispatchedHandler( func ) );
			}

			func();
			return nullptr;
		}

	public:
		property ::Windows::UI::Core::CoreDispatcher^ Dispatcher
		{
			::Windows::UI::Core::CoreDispatcher^ get() { return Dispatcher_; }
			void set( ::Windows::UI::Core::CoreDispatcher^ value ) { Dispatcher_ = value; }
		}

	private:
		::Windows::UI::Core::CoreDispatcher^ Dispatcher_;
	};

} }