#pragma once

namespace Mntone { namespace Xamcc {

	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class VisualTreeHelper2 sealed
	{
	private:
		VisualTreeHelper2();

	public:
		static Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::DependencyObject^>^ GetDescendantsOfType( Windows::UI::Xaml::DependencyObject^ reference, Windows::UI::Xaml::Interop::TypeName typeName );
		static Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::DependencyObject^>^ GetDescendants( Windows::UI::Xaml::DependencyObject^ reference );

		static Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::DependencyObject^>^ GetAncestors( Windows::UI::Xaml::DependencyObject^ reference );
		
		static Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::DependencyObject^>^ GetChildrenOfType( Windows::UI::Xaml::DependencyObject^ reference, Windows::UI::Xaml::Interop::TypeName typeName );
		static Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::DependencyObject^>^ GetChildren( Windows::UI::Xaml::DependencyObject^ reference );

		static Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::DependencyObject^>^ GetSiblingsOfType( Windows::UI::Xaml::DependencyObject^ reference, Windows::UI::Xaml::Interop::TypeName typeName );
		static Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::DependencyObject^>^ GetSiblings( Windows::UI::Xaml::DependencyObject^ reference );

	private:
		static void OfType( std::vector<Windows::UI::Xaml::DependencyObject^>& data, Windows::UI::Xaml::Interop::TypeName typeName );

		static std::vector<Windows::UI::Xaml::DependencyObject^> GetDescendantsInternal( Windows::UI::Xaml::DependencyObject^ reference );
		static std::vector<Windows::UI::Xaml::DependencyObject^> GetChildrenInternal( Windows::UI::Xaml::DependencyObject^ reference );
		static std::vector<Windows::UI::Xaml::DependencyObject^> GetSiblingsInternal( Windows::UI::Xaml::DependencyObject^ reference );
	};

} }