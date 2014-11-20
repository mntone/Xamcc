#pragma once
#include <ppltasks.h>
#include <collection.h>
#include "DispatcherHelper.h"
#include "Foundation\EventWrapper.h"

namespace Mntone { namespace Xamcc { 

	class ViewModelHelper
	{
	public:
		template<typename T>
		static ::Platform::Collections::Vector<T>^ CreateDispatcherVector(
			::Windows::Foundation::Collections::IObservableVector<T>^ source )
		{
			::Windows::Foundation::EventRegistrationToken token;
			return CreateDispatcherVector<T, T>(
				source,
				[]( T value ) { return value; },
				ref new DispatcherHelper( ::Windows::UI::Xaml::Window::Current->Dispatcher ),
				&token );
		}

		template<typename T>
		static ::Platform::Collections::Vector<T>^ CreateDispatcherVector(
			::Windows::Foundation::Collections::IObservableVector<T>^ source,
			::Windows::Foundation::EventRegistrationToken* token )
		{
			return CreateDispatcherVector<T, T>(
				source,
				[]( T value ) { return value; },
				ref new DispatcherHelper( ::Windows::UI::Xaml::Window::Current->Dispatcher ),
				token );
		}

		template<typename T>
		static ::Platform::Collections::Vector<T>^ CreateDispatcherVector(
			::Windows::Foundation::Collections::IObservableVector<T>^ source,
			Foundation::EventWrapper<::Windows::Foundation::Collections::IObservableVector<T>>^* eventWrapper )
		{
			return CreateDispatcherVector<T, T>(
				source,
				[]( T value ) { return value; },
				ref new DispatcherHelper( ::Windows::UI::Xaml::Window::Current->Dispatcher ),
				eventWrapper );
		}


		template<typename T>
		static ::Platform::Collections::Vector<T>^ CreateDispatcherVector(
			::Windows::Foundation::Collections::IObservableVector<T>^ source,
			::Windows::UI::Core::CoreDispatcher^ dispatcher )
		{
			::Windows::Foundation::EventRegistrationToken token;
			return CreateDispatcherVector<TModel, TViewModel>(
				source,
				[]( T value ) { return value; },
				ref new DispatcherHelper( dispatcher ),
				&token );
		}

		template<typename T>
		static ::Platform::Collections::Vector<T>^ CreateDispatcherVector(
			::Windows::Foundation::Collections::IObservableVector<T>^ source,
			::Windows::UI::Core::CoreDispatcher^ dispatcher,
			::Windows::Foundation::EventRegistrationToken* token )
		{
			return CreateDispatcherVector<TModel, TViewModel>(
				source,
				[]( T value ) { return value; },
				ref new DispatcherHelper( dispatcher ),
				token );
		}

		template<typename T>
		static ::Platform::Collections::Vector<T>^ CreateDispatcherVector(
			::Windows::Foundation::Collections::IObservableVector<T>^ source,
			::Windows::UI::Core::CoreDispatcher^ dispatcher,
			Foundation::EventWrapper<::Windows::Foundation::Collections::IObservableVector<T>>^* eventWrapper )
		{
			return CreateDispatcherVector<T, T>(
				source,
				[]( T value ) { return value; },
				ref new DispatcherHelper( dispatcher ),
				eventWrapper );
		}


		template<typename TModel, typename TViewModel>
		static ::Platform::Collections::Vector<TViewModel>^ CreateDispatcherVector(
			::Windows::Foundation::Collections::IObservableVector<TModel>^ source,
			::std::function<TViewModel( TModel )> converter )
		{
			::Windows::Foundation::EventRegistrationToken token;
			return CreateDispatcherVector<TModel, TViewModel>(
				source,
				converter,
				ref new DispatcherHelper( ::Windows::UI::Xaml::Window::Current->Dispatcher ),
				&token );
		}

		template<typename TModel, typename TViewModel>
		static ::Platform::Collections::Vector<TViewModel>^ CreateDispatcherVector(
			::Windows::Foundation::Collections::IObservableVector<TModel>^ source,
			::std::function<TViewModel( TModel )> converter,
			::Windows::Foundation::EventRegistrationToken* token )
		{
			return CreateDispatcherVector<TModel, TViewModel>(
				source,
				converter,
				ref new DispatcherHelper( ::Windows::UI::Xaml::Window::Current->Dispatcher ),
				token );
		}

		template<typename TModel, typename TViewModel>
		static ::Platform::Collections::Vector<TViewModel>^ CreateDispatcherVector(
			::Windows::Foundation::Collections::IObservableVector<TModel>^ source,
			::std::function<TViewModel( TModel )> converter,
			Foundation::EventWrapper<::Windows::Foundation::Collections::IObservableVector<TModel>>^* eventWrapper )
		{
			return CreateDispatcherVector<TModel, TViewModel>(
				source,
				converter,
				ref new DispatcherHelper( ::Windows::UI::Xaml::Window::Current->Dispatcher ),
				eventWrapper );
		}


		template<typename TModel, typename TViewModel>
		static ::Platform::Collections::Vector<TViewModel>^ CreateDispatcherVector(
			::Windows::Foundation::Collections::IObservableVector<TModel>^ source,
			::std::function<TViewModel( TModel )> converter,
			::Windows::UI::Core::CoreDispatcher^ dispatcher )
		{
			::Windows::Foundation::EventRegistrationToken token;
			return CreateDispatcherVector<TModel, TViewModel>(
				source,
				converter,
				ref new DispatcherHelper( dispatcher ),
				&token );
		}

		template<typename TModel, typename TViewModel>
		static ::Platform::Collections::Vector<TViewModel>^ CreateDispatcherVector(
			::Windows::Foundation::Collections::IObservableVector<TModel>^ source,
			::std::function<TViewModel( TModel )> converter,
			::Windows::UI::Core::CoreDispatcher^ dispatcher,
			::Windows::Foundation::EventRegistrationToken* token )
		{
			return CreateDispatcherVector<TModel, TViewModel>(
				source,
				converter,
				ref new DispatcherHelper( dispatcher ),
				token );
		}

		template<typename TModel, typename TViewModel>
		static ::Platform::Collections::Vector<TViewModel>^ CreateDispatcherVector(
			::Windows::Foundation::Collections::IObservableVector<TModel>^ source,
			::std::function<TViewModel( TModel )> converter,
			::Windows::UI::Core::CoreDispatcher^ dispatcher,
			Foundation::EventWrapper<::Windows::Foundation::Collections::IObservableVector<TModel>>^* eventWrapper )
		{
			return CreateDispatcherVector<TModel, TViewModel>(
				source,
				converter,
				ref new DispatcherHelper( dispatcher ),
				eventWrapper );
		}


		template<typename TModel, typename TViewModel>
		static ::Platform::Collections::Vector<TViewModel>^ CreateDispatcherVector(
			::Windows::Foundation::Collections::IObservableVector<TModel>^ source,
			::std::function<TViewModel( TModel )> converter,
			DispatcherHelper^ dispatcher )
		{
			::Windows::Foundation::EventRegistrationToken token;
			return CreateDispatcherVector<TModel, TViewModel>(
				source,
				converter,
				dispatcher,
				&token );
		}

		template<typename TModel, typename TViewModel>
		static ::Platform::Collections::Vector<TViewModel>^ CreateDispatcherVector(
			::Windows::Foundation::Collections::IObservableVector<TModel>^ source,
			::std::function<TViewModel( TModel )> converter,
			DispatcherHelper^ dispatcher,
			::Windows::Foundation::EventRegistrationToken* token )
		{
			using namespace ::Windows::Foundation::Collections;
			using namespace ::Windows::UI::Core;

			if( source == nullptr || dispatcher == nullptr )
			{
				throw ref new ::Platform::NullReferenceException();
			}

			auto result = ref new ::Platform::Collections::Vector<TViewModel>( source->Size );
			::std::transform( begin( source ), end( source ), begin( result ), converter );

			*token = source->VectorChanged += ref new VectorChangedEventHandler<TModel>(
			[result, converter, dispatcher]( IObservableVector<TModel>^ sender, IVectorChangedEventArgs^ e )
			{
				switch( e->CollectionChange )
				{
				case CollectionChange::Reset:
					dispatcher->InvokeAsync( CoreDispatcherPriority::Low, [sender, converter, result]
					{
						result->Clear();
						for( auto&& model : sender )
						{
							result->Append( converter( model ) );
						}
					} );
					break;

				case CollectionChange::ItemInserted:
					dispatcher->InvokeAsync( CoreDispatcherPriority::Low, [sender, e, converter, result]
					{
						result->InsertAt( e->Index, converter( sender->GetAt( e->Index ) ) );
					} );
					break;

				case CollectionChange::ItemRemoved:
					dispatcher->InvokeAsync( CoreDispatcherPriority::Low, [e, result]
					{
						result->RemoveAt( e->Index );
					} );
					break;

				case CollectionChange::ItemChanged:
					dispatcher->InvokeAsync( CoreDispatcherPriority::Low, [sender, e, converter, result]
					{
						result->SetAt( e->Index, converter( sender->GetAt( e->Index ) ) );
					} );
					break;
				}
			} );

			return result;
		}

		template<typename TModel, typename TViewModel>
		static ::Platform::Collections::Vector<TViewModel>^ CreateDispatcherVector(
			::Windows::Foundation::Collections::IObservableVector<TModel>^ source,
			::std::function<TViewModel( TModel )> converter,
			DispatcherHelper^ dispatcher,
			Foundation::EventWrapper<::Windows::Foundation::Collections::IObservableVector<TModel>>^* eventWrapper )
		{
			::Windows::Foundation::EventRegistrationToken token;
			auto ret = CreateDispatcherVector<TModel, TViewModel>(
				source,
				converter,
				dispatcher,
				&token );
			*eventWrapper = ref new Foundation::EventWrapper<::Windows::Foundation::Collections::IObservableVector<TModel>>(
				source,
				token,
				[]( ::Windows::Foundation::Collections::IObservableVector<TModel>^ obj, ::Windows::Foundation::EventRegistrationToken token ) { obj->VectorChanged -= token; } );
			return ret;
		}
	};

} }