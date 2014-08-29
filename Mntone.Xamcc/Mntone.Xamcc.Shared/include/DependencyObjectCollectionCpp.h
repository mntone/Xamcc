#pragma once

namespace Mntone { namespace Xamcc {

	namespace WUXI = ::Windows::UI::Xaml::Interop;

	[Windows::UI::Xaml::Data::Bindable]
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class DependencyObjectCollectionCpp
		: ::Windows::UI::Xaml::DependencyObjectCollection
		, ::Windows::UI::Xaml::Interop::IBindableObservableVector
	{
	private:
		using MyObject = ::Windows::UI::Xaml::DependencyObject^;
		using WUXI_Base = ::Windows::UI::Xaml::Interop::IBindableObservableVector;

	internal:
		DependencyObjectCollectionCpp() { }

	private:
		void OnVectorChanged(
			::Windows::Foundation::Collections::IObservableVector<MyObject>^ sender,
			::Windows::Foundation::Collections::IVectorChangedEventArgs^ args ) { wuxiEvent_( this, args ); }

		virtual WUXI::IBindableIterator^ BindableFirst() sealed = WUXI_Base::First { return safe_cast<WUXI::IBindableIterator^>( First() ); }
		virtual ::Platform::Object^ BindableGetAt( uint32 index ) sealed = WUXI_Base::GetAt { return GetAt( index ); }
		virtual bool BindableIndexOf( ::Platform::Object^ value, uint32* index ) sealed = WUXI_Base::IndexOf { return IndexOf( safe_cast<MyObject>( value ), index ); }
		virtual WUXI::IBindableVectorView^ BindableGetView() sealed = WUXI_Base::GetView { return safe_cast<WUXI::IBindableVectorView^>( GetView() ); }
		virtual void BindableSetAt( uint32 index, ::Platform::Object^ item ) sealed = WUXI_Base::SetAt { SetAt( index, safe_cast<MyObject>( item ) ); }
		virtual void BindableInsertAt( uint32 index, ::Platform::Object^ item ) sealed = WUXI_Base::InsertAt { InsertAt( index, safe_cast<MyObject>( item ) ); }
		virtual void BindableAppend( ::Platform::Object^ item ) sealed = WUXI_Base::Append { Append( safe_cast<MyObject>( item ) ); }
		virtual void BindableRemoveAt( uint32 index ) sealed = WUXI_Base::RemoveAt { RemoveAt( index ); }
		virtual void BindableRemoveAtEnd() sealed = WUXI_Base::RemoveAtEnd { RemoveAtEnd(); }
		virtual void BindableClear() sealed = WUXI_Base::Clear { Clear(); }
		virtual ::Windows::Foundation::EventRegistrationToken BindableEventAdd( ::Windows::UI::Xaml::Interop::BindableVectorChangedEventHandler^ e ) sealed = WUXI_Base::VectorChanged::add
		{
			VectorChanged += ref new ::Windows::Foundation::Collections::VectorChangedEventHandler<MyObject>( this, &DependencyObjectCollectionCpp::OnVectorChanged );
			return wuxiEvent_ += e;
		}
		virtual void BindableEventRemove( ::Windows::Foundation::EventRegistrationToken t ) sealed = WUXI_Base::VectorChanged::remove { wuxiEvent_ -= t; }

	private:
		virtual property uint32 BindableSize
		{
			virtual uint32 get() sealed = WUXI_Base::Size::get { return Size; }
		}

	private:
		event ::Windows::UI::Xaml::Interop::BindableVectorChangedEventHandler^ wuxiEvent_;
	};

} }