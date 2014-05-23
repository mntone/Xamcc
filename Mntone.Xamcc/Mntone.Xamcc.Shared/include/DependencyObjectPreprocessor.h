#pragma once

#ifndef DEPENDENCY_OBJECT_HELPER_USE
#define __IMPL_DP_PROP(__NAME__) __NAME__##Property_
#define __IMPL_DP_GET(__CLASS__, __TYPE__, __NAME__) __TYPE__^ __CLASS__::__NAME__::get(){return dynamic_cast<__TYPE__^>(GetValue(__IMPL_DP_PROP(__NAME__)));}
#define __IMPL_DP_SET(__CLASS__, __TYPE__, __NAME__) void __CLASS__::__NAME__::set(__TYPE__^ value){SetValue(__IMPL_DP_PROP(__NAME__),value);}
#define __IMPL_DP_VALUE_GET(__CLASS__, __TYPE__, __NAME__) __TYPE__ __CLASS__::__NAME__::get(){return static_cast<__TYPE__>(GetValue(__IMPL_DP_PROP(__NAME__)));}
#define __IMPL_DP_VALUE_SET(__CLASS__, __TYPE__, __NAME__) void __CLASS__::__NAME__::set(__TYPE__ value){SetValue(__IMPL_DP_PROP(__NAME__),value);}

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
#endif