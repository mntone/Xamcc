#pragma once

#ifndef DEPENDENCY_OBJECT_HELPER_USE
#define DEPENDENCY_OBJECT_HELPER_USE 1
#endif

#ifdef DEPENDENCY_OBJECT_HELPER_USE
#define __IMPL_DP_PROP(__NAME__) __NAME__##Property_
#define __IMPL_DP_GET(__CLASS__, __TYPE__, __NAME__) __TYPE__^ __CLASS__::__NAME__::get(){return safe_cast<__TYPE__^>(GetValue(__IMPL_DP_PROP(__NAME__)));}
#define __IMPL_DP_SET(__CLASS__, __TYPE__, __NAME__) void __CLASS__::__NAME__::set(__TYPE__^ value){SetValue(__IMPL_DP_PROP(__NAME__),value);}
#define __IMPL_DP_VALUE_GET(__CLASS__, __TYPE__, __NAME__) __TYPE__ __CLASS__::__NAME__::get(){return static_cast<__TYPE__>(GetValue(__IMPL_DP_PROP(__NAME__)));}
#define __IMPL_DP_VALUE_SET(__CLASS__, __TYPE__, __NAME__) void __CLASS__::__NAME__::set(__TYPE__ value){SetValue(__IMPL_DP_PROP(__NAME__),value);}
#define __IMPL_DP_ENUM_GET(__CLASS__, __TYPE__, __NAME__) __TYPE__ __CLASS__::__NAME__::get(){auto intValue = dynamic_cast<::Platform::IBox<int32>^>(GetValue(__IMPL_DP_PROP(__NAME__)));return intValue ? static_cast<__TYPE__>(intValue->Value) : static_cast<__TYPE__>(0);}
#define __IMPL_DP_ENUM_SET(__CLASS__, __TYPE__, __NAME__) void __CLASS__::__NAME__::set(__TYPE__ value){SetValue(__IMPL_DP_PROP(__NAME__),static_cast<int32>(value));}

#define __IMPL_DP_REG_BEGIN(__CLASS__, __TYPE__, __NAME__) \
Windows::UI::Xaml::DependencyProperty^ __CLASS__::__IMPL_DP_PROP(__NAME__) = Windows::UI::Xaml::DependencyProperty::Register( \
	#__NAME__, __TYPE__::typeid, __CLASS__::typeid,

#define __IMPL_DP_REG(__CLASS__, __TYPE__, __NAME__, __PM__) __IMPL_DP_REG_BEGIN(__CLASS__, __TYPE__, __NAME__) __PM__);

#define IMPL_DP_GET(__CLASS__, __TYPE__, __NAME__, __PM__) \
	__IMPL_DP_GET(__CLASS__, __TYPE__, __NAME__) \
	__IMPL_DP_REG(__CLASS__, __TYPE__, __NAME__, __PM__)

#define IMPL_DP_SET(__CLASS__, __TYPE__, __NAME__, __PM__) \
	__IMPL_DP_SET(__CLASS__, __TYPE__, __NAME__) \
	__IMPL_DP_REG(__CLASS__, __TYPE__, __NAME__, __PM__)

#define IMPL_DP_GETSET(__CLASS__, __TYPE__, __NAME__, __PM__) \
	__IMPL_DP_GET(__CLASS__, __TYPE__, __NAME__) \
	__IMPL_DP_SET(__CLASS__, __TYPE__, __NAME__) \
	__IMPL_DP_REG(__CLASS__, __TYPE__, __NAME__, __PM__)

#define IMPL_DP_VALUE_GET(__CLASS__, __TYPE__, __NAME__, __PM__) \
	__IMPL_DP_VALUE_GET(__CLASS__, __TYPE__, __NAME__) \
	__IMPL_DP_REG(__CLASS__, __TYPE__, __NAME__, __PM__)

#define IMPL_DP_VALUE_SET(__CLASS__, __TYPE__, __NAME__, __PM__) \
	__IMPL_DP_VALUE_SET(__CLASS__, __TYPE__, __NAME__) \
	__IMPL_DP_REG(__CLASS__, __TYPE__, __NAME__, __PM__)

#define IMPL_DP_VALUE_GETSET(__CLASS__, __TYPE__, __NAME__, __PM__) \
	__IMPL_DP_VALUE_GET(__CLASS__, __TYPE__, __NAME__) \
	__IMPL_DP_VALUE_SET(__CLASS__, __TYPE__, __NAME__) \
	__IMPL_DP_REG(__CLASS__, __TYPE__, __NAME__, __PM__)

#define IMPL_DP_ENUM_GET(__CLASS__, __TYPE__, __NAME__, __PM__) \
	__IMPL_DP_ENUM_GET(__CLASS__, __TYPE__, __NAME__) \
	__IMPL_DP_REG(__CLASS__, int, __NAME__, __PM__)

#define IMPL_DP_ENUM_SET(__CLASS__, __TYPE__, __NAME__, __PM__) \
	__IMPL_DP_ENUM_SET(__CLASS__, __TYPE__, __NAME__) \
	__IMPL_DP_REG(__CLASS__, int, __NAME__, __PM__)

#define IMPL_DP_ENUM_GETSET(__CLASS__, __TYPE__, __NAME__, __PM__) \
	__IMPL_DP_ENUM_GET(__CLASS__, __TYPE__, __NAME__) \
	__IMPL_DP_ENUM_SET(__CLASS__, __TYPE__, __NAME__) \
	__IMPL_DP_REG(__CLASS__, int, __NAME__, __PM__)
#endif