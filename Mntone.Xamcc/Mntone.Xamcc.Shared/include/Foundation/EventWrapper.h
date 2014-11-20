#pragma once
#include <functional>

namespace Mntone { namespace Xamcc { namespace Foundation {

	template<typename T>
	ref class EventWrapper sealed
	{
	internal:
		EventWrapper(
			T^ sender,
			::Windows::Foundation::EventRegistrationToken token,
			::std::function<void( T^, ::Windows::Foundation::EventRegistrationToken )> removeHandlerFunc )
			: sender_( sender )
			, eventToken_( token )
			, removeHandlerFunc_( removeHandlerFunc )
		{ }

	public:
		virtual ~EventWrapper()
		{
			auto sender = sender_.Resolve<T>();
			if( sender )
			{
				removeHandlerFunc_( sender, eventToken_ );
			}
		}

	private:
		::Platform::WeakReference sender_;
		::Windows::Foundation::EventRegistrationToken eventToken_;
		::std::function<void( T^, ::Windows::Foundation::EventRegistrationToken )> removeHandlerFunc_;
	};

} } }