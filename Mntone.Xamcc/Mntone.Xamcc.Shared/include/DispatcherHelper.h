#pragma once
#include <functional>

namespace Mntone { namespace Xamcc { 

	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class DispatcherHelper sealed
	{
	internal:
		DispatcherHelper()
			: Dispatcher_( nullptr )
		{ }

		DispatcherHelper( Windows::UI::Core::CoreDispatcher^ dispatcher )
			: Dispatcher_( dispatcher )
		{ }

		Windows::Foundation::IAsyncAction^ InvokeAsync( std::function<void( void )> func )
		{
			return Dispatcher_->RunAsync(
				Windows::UI::Core::CoreDispatcherPriority::Normal,
				ref new Windows::UI::Core::DispatchedHandler( func ) );
		}

		Windows::Foundation::IAsyncAction^ InvokeAsync( Windows::UI::Core::CoreDispatcherPriority priority, std::function<void( void )> func )
		{
			return Dispatcher_->RunAsync( priority, ref new Windows::UI::Core::DispatchedHandler( func ) );
		}

	public:
		property Windows::UI::Core::CoreDispatcher^ Dispatcher
		{
			Windows::UI::Core::CoreDispatcher^ get() { return Dispatcher_; }
			void set( Windows::UI::Core::CoreDispatcher^ value ) { Dispatcher_ = value; }
		}

	private:
		Windows::UI::Core::CoreDispatcher^ Dispatcher_;
	};

} }