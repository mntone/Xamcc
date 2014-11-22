#pragma once
#include <functional>

namespace Mntone { namespace Xamcc { namespace Commands {

	ref class RelayCommand
		: [Windows::Foundation::Metadata::Default] ::Windows::UI::Xaml::Input::ICommand
	{
	internal:
		RelayCommand( ::std::function<void( ::Platform::Object^ )> executeCallback )
		{
			if( executeCallback == nullptr )
			{
				throw ref new Platform::NullReferenceException();
			}

			executeCallback_ = executeCallback;
			canExecuteCallback_ = []( ::Platform::Object^ ) -> bool { return true; };
		}

		RelayCommand(
			::std::function<void( ::Platform::Object^ )> executeCallback,
			::std::function<bool( ::Platform::Object^ )> canExecuteCallback )
		{
			if( executeCallback == nullptr || canExecuteCallback == nullptr )
			{
				throw ref new Platform::NullReferenceException();
			}

			executeCallback_ = executeCallback;
			canExecuteCallback_ = canExecuteCallback;
		}

	public:
		virtual bool CanExecute( ::Platform::Object^ parameter )
		{
			return canExecuteCallback_( parameter );
		}
		virtual void Execute( ::Platform::Object^ parameter )
		{
			executeCallback_( parameter );
		}

		void RaiseCanExecuteChanged()
		{
			CanExecuteChanged( this, nullptr );
		}

	public:
		virtual event Windows::Foundation::EventHandler<::Platform::Object^>^ CanExecuteChanged;

	protected private:
		::std::function<void( ::Platform::Object^ )> executeCallback_;
		::std::function<bool( ::Platform::Object^ )> canExecuteCallback_;
	};

} } }