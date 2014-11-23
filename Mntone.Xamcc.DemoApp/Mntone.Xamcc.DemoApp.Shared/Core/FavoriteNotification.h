#pragma once
#include "INotification.h"

namespace Mntone { namespace Xamcc { namespace DemoApp { namespace Core {

	[Windows::UI::Xaml::Data::Bindable]
	public ref class FavoriteNotification sealed
		: public INotification
	{
	public:
		FavoriteNotification( ::Windows::Foundation::DateTime dateTime, ::Platform::String^ key );

		property Core::NotificationType NotificationType
		{
			virtual Core::NotificationType get() { return Core::NotificationType::Favorite; }
		}
		property ::Platform::String^ Id
		{
			virtual ::Platform::String^ get() { return Id_; }
		}

	private:
		::Platform::String^ Id_;
	};

} } } }