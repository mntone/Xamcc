#include "pch.h"
#include "VisualTreeHelper2.h"
#include <queue>

using namespace Platform;
using namespace Platform::Collections;
using namespace std;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::UI::Xaml::Media;
using namespace Mntone::Xamcc::Controls;

#define VTH2_RETURN return ref new VectorView<DependencyObject^>( move( data ) );

VisualTreeHelper2::VisualTreeHelper2()
{ }

IVectorView<DependencyObject^>^ VisualTreeHelper2::GetDescendantsOfType( DependencyObject^ reference, TypeName typeName )
{
	vector<DependencyObject^> data = GetDescendantsInternal( reference );
	OfType( data, typeName );
	VTH2_RETURN
}

IVectorView<DependencyObject^>^ VisualTreeHelper2::GetDescendants( DependencyObject^ reference )
{
	vector<DependencyObject^> data = GetDescendantsInternal( reference );
	VTH2_RETURN
}

vector<DependencyObject^> VisualTreeHelper2::GetDescendantsInternal( DependencyObject^ reference )
{
	vector<DependencyObject^> data;
	if( reference == nullptr )
	{
		return move( data );
	}

	queue<DependencyObject^> queue;

	auto popup = dynamic_cast<Popup^>( reference );
	if( popup != nullptr && popup->Child != nullptr )
	{
		queue.push( popup->Child );
		data.emplace_back( popup->Child );
	}
	else
	{
		const auto count = VisualTreeHelper::GetChildrenCount( reference );
		for( int32 i = 0; i < count; ++i )
		{
			auto child = VisualTreeHelper::GetChild( reference, i );
			queue.push( child );
			data.emplace_back( child );
		}
	}

	while( !queue.empty() )
	{
		reference = queue.front();
		queue.pop();

		popup = dynamic_cast<Popup^>( reference );
		if( popup != nullptr && popup->Child != nullptr )
		{
			queue.push( popup->Child );
			data.emplace_back( popup->Child );
			continue;
		}

		const auto count = VisualTreeHelper::GetChildrenCount( reference );
		for( int32 i = 0; i < count; ++i )
		{
			auto child = VisualTreeHelper::GetChild( reference, i );
			queue.push( child );
			data.emplace_back( child );
		}
	}

	return move( data );
}

IVectorView<DependencyObject^>^ VisualTreeHelper2::GetAncestors( DependencyObject^ reference )
{
	vector<DependencyObject^> data;
	if( reference == nullptr )
	{
		VTH2_RETURN
	}

	auto parent = VisualTreeHelper::GetParent( reference );
	while( parent != nullptr )
	{
		data.emplace_back( parent );
		parent = VisualTreeHelper::GetParent( parent );
	}

	VTH2_RETURN
}

IVectorView<DependencyObject^>^ VisualTreeHelper2::GetChildrenOfType( DependencyObject^ reference, TypeName typeName )
{
	vector<DependencyObject^> data = GetChildrenInternal( reference );
	OfType( data, typeName );
	VTH2_RETURN
}

IVectorView<DependencyObject^>^ VisualTreeHelper2::GetChildren( DependencyObject^ reference )
{
	vector<DependencyObject^> data = GetChildrenInternal( reference );
	VTH2_RETURN
}

vector<DependencyObject^> VisualTreeHelper2::GetChildrenInternal( DependencyObject^ reference )
{
	vector<DependencyObject^> data;
	if( reference == nullptr )
	{
		return move( data );
	}

	auto popup = dynamic_cast<Popup^>( reference );
	if( popup != nullptr && popup->Child != nullptr )
	{
		data.emplace_back( popup->Child );
		return move( data );
	}

	const auto count = VisualTreeHelper::GetChildrenCount( reference );
	for( int32 i = 0; i < count; ++i )
	{
		auto child = VisualTreeHelper::GetChild( reference, i );
		data.emplace_back( child );
	}

	return move( data );
}

IVectorView<DependencyObject^>^ VisualTreeHelper2::GetSiblingsOfType( DependencyObject^ reference, TypeName typeName )
{
	vector<DependencyObject^> data = GetSiblingsInternal( reference );
	OfType( data, typeName );
	VTH2_RETURN
}

IVectorView<DependencyObject^>^ VisualTreeHelper2::GetSiblings( DependencyObject^ reference )
{
	vector<DependencyObject^> data = GetSiblingsInternal( reference );
	VTH2_RETURN
}

vector<DependencyObject^> VisualTreeHelper2::GetSiblingsInternal( DependencyObject^ reference )
{
	vector<DependencyObject^> data;
	if( reference == nullptr )
	{
		return move( data );
	}

	auto parent = VisualTreeHelper::GetParent( reference );
	if( parent == nullptr )
	{
		data.emplace_back( reference );
		return move( data );
	}

	auto popup = dynamic_cast<Popup^>( parent );
	if( popup != nullptr && popup->Child != nullptr )
	{
		data.emplace_back( popup->Child );
		return move( data );
	}

	const auto count = VisualTreeHelper::GetChildrenCount( parent );
	for( int32 i = 0; i < count; ++i )
	{
		auto child = VisualTreeHelper::GetChild( reference, i );
		data.emplace_back( child );
	}

	return move( data );
}

void VisualTreeHelper2::OfType( vector<DependencyObject^>& data, TypeName typeName )
{
	data.erase(
		remove_if(
			begin( data ),
			end( data ),
			[typeName]( DependencyObject^ d ) { return TypeName( d->GetType() ).Name != typeName.Name; } ),
		end( data ) );
}