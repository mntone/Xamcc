#pragma once
#include <functional>

namespace Mntone { namespace Xamcc { namespace Commands {

	template<typename T>
	ref class RelayCommand2
		: [Windows::Foundation::Metadata::Default] ::Windows::UI::Xaml::Input::ICommand
	{
	internal:
		RelayCommand2( ::Platform::Object^ parent, ::std::function<void( T^, ::Platform::Object^ )> executeCallback )
		{
			if( parent == nullptr || executeCallback == nullptr )
			{
				throw ref new ::Platform::NullReferenceException();
			}

			parent_ = parent;
			executeCallback_ = executeCallback;
			canExecuteCallback_ = []( T^, ::Platform::Object^ ) -> bool { return true; };
		}

		RelayCommand2(
			::Platform::Object^ parent,
			::std::function<void( T^, ::Platform::Object^ )> executeCallback,
			::std::function<bool( T^, ::Platform::Object^ )> canExecuteCallback )
		{
			if( parent == nullptr || executeCallback == nullptr || canExecuteCallback == nullptr )
			{
				throw ref new ::Platform::NullReferenceException();
			}

			parent_ = parent;
			executeCallback_ = executeCallback;
			canExecuteCallback_ = canExecuteCallback;
		}

	public:
		virtual bool CanExecute( ::Platform::Object^ parameter )
		{
			auto that = parent_.Resolve<T>();
			if( that )
			{
				return canExecuteCallback_( that, parameter );
			}
			return false;
		}
		virtual void Execute( ::Platform::Object^ parameter )
		{
			auto that = parent_.Resolve<T>();
			if( that )
			{
				executeCallback_( that, parameter );
			}
		}

		void RaiseCanExecuteChanged()
		{
			CanExecuteChanged( this, nullptr );
		}

	public:
		virtual event Windows::Foundation::EventHandler<::Platform::Object^>^ CanExecuteChanged;

	protected private:
		::Platform::WeakReference parent_;
		::std::function<void( T^, ::Platform::Object^ )> executeCallback_;
		::std::function<bool( T^, ::Platform::Object^ )> canExecuteCallback_;
	};

} } }