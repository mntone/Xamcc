#pragma once
#include <ppltasks.h>
#include <collection.h>
#include "DispatcherHelper.h"

namespace Mntone { namespace Xamcc { 

	class ViewModelHelper
	{
	public:
		template<typename TModel, typename TViewModel>
		static ::Platform::Collections::Vector<TViewModel>^ CreateDispatcherVector(
			::Windows::Foundation::Collections::IObservableVector<TModel>^ source,
			::std::function<TViewModel( TModel )> converter,
			::Windows::UI::Core::CoreDispatcher^ dispatcher )
		{
			return CreateDispatcherVector<TModel, TViewModel>( source, converter, ref new DispatcherHelper( dispatcher ) );
		}

		template<typename TModel, typename TViewModel>
		static ::Platform::Collections::Vector<TViewModel>^ CreateDispatcherVector(
			::Windows::Foundation::Collections::IObservableVector<TModel>^ source,
			::std::function<TViewModel( TModel )> converter,
			DispatcherHelper^ dispatcher )
		{
			using namespace ::Windows::Foundation::Collections;
			using namespace ::Windows::UI::Core;

			if( source == nullptr || dispatcher == nullptr )
			{
				throw ref new ::Platform::NullReferenceException();
			}

			auto result = ref new ::Platform::Collections::Vector<TViewModel>( source->Size );
			::std::transform( begin( source ), end( source ), begin( result ), converter );

			source->VectorChanged += ref new VectorChangedEventHandler<TModel>(
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

#ifdef VECTOR_EXTENSION
		template<typename TModel, typename TViewModel>
		static ::Platform::Collections::Deque<TViewModel>^ CreateDispatcherDeque(
			::Windows::Foundation::Collections::IObservableVector<TModel>^ source,
			::std::function<TViewModel( TModel )> converter,
			::Windows::UI::Core::CoreDispatcher^ dispatcher )
		{
			return CreateDispatcherDeque<TModel, TViewModel>( source, converter, ref new DispatcherHelper( dispatcher ) );
		}

		template<typename TModel, typename TViewModel>
		static ::Platform::Collections::Deque<TViewModel>^ CreateDispatcherDeque(
			::Windows::Foundation::Collections::IObservableVector<TModel>^ source,
			::std::function<TViewModel( TModel )> converter,
			DispatcherHelper^ dispatcher )
		{
			using namespace ::Windows::Foundation::Collections;
			using namespace ::Windows::UI::Core;

			if( source == nullptr || dispatcher == nullptr )
			{
				throw ref new ::Platform::NullReferenceException();
			}

			auto result = ref new ::Platform::Collections::Deque<TViewModel>( source->Size );
			::std::transform( begin( source ), end( source ), begin( result ), converter );

			source->VectorChanged += ref new VectorChangedEventHandler<TModel>(
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
#endif
	};

} }