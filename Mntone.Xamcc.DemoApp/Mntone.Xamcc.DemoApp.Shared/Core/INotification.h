#pragma once

namespace Mntone { namespace Xamcc { namespace DemoApp { namespace Core {

	public enum class NotificationType
	{
		Favorite,
		Follow,
	};

	public interface class INotification
	{
		property Core::NotificationType NotificationType
		{
			Core::NotificationType get();
		}
		property ::Platform::String^ Id
		{
			::Platform::String^ get();
		}
	};

} } } }