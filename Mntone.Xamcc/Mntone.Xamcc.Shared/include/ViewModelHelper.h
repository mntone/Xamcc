#pragma once
#include <ppltasks.h>
#include <collection.h>

namespace Mntone { namespace Xamcc { 

	class ViewModelHelper
	{
	public:
		template<typename TModel, typename TViewModel>
		static Platform::Collections::Vector<TViewModel>^ CreateDispatcherVector(
			Platform::Collections::Vector<TModel>^ source,
			std::function<TViewModel( TModel )> converter,
			Windows::UI::Core::CoreDispatcher^ dispatcher )
		{
			using namespace Windows::Foundation::Collections;

			if( source == nullptr || dispatcher == nullptr )
			{
				throw ref new Platform::NullReferenceException();
			}

			auto result = ref new Platform::Collections::Vector<TViewModel>();
			for( auto&& model : source )
			{
				result->Append( converter( model ) );
			}

			source->VectorChanged += ref new VectorChangedEventHandler<TModel>(
			[result, converter, dispatcher]( IObservableVector<TModel>^ sender, IVectorChangedEventArgs^ e )
			{
				switch( e->CollectionChange )
				{
				case CollectionChange::Reset:
					dispatcher->RunAsync(
						Windows::UI::Core::CoreDispatcherPriority::Low,
						ref new Windows::UI::Core::DispatchedHandler( [sender, converter, result]
						{
							result->Clear();
							for( auto&& model : sender )
							{
								result->Append( converter( model ) );
							}
						} ) );
					break;

				case CollectionChange::ItemInserted:
					dispatcher->RunAsync(
						Windows::UI::Core::CoreDispatcherPriority::Low,
						ref new Windows::UI::Core::DispatchedHandler( [sender, e, converter, result]
						{
							result->InsertAt( e->Index, converter( sender->GetAt( e->Index ) ) );
						} ) );
					break;

				case CollectionChange::ItemRemoved:
					dispatcher->RunAsync(
						Windows::UI::Core::CoreDispatcherPriority::Low,
						ref new Windows::UI::Core::DispatchedHandler( [converter, e, result]
						{
							result->RemoveAt( e->Index );
						} ) );
					break;

				case CollectionChange::ItemChanged:
					dispatcher->RunAsync(
						Windows::UI::Core::CoreDispatcherPriority::Low,
						ref new Windows::UI::Core::DispatchedHandler( [sender, e, converter, result]
						{
							result->SetAt( e->Index, converter( sender->GetAt( e->Index ) ) );
						} ) );
					break;
				}
			} );

			return result;
		}
	};

} }