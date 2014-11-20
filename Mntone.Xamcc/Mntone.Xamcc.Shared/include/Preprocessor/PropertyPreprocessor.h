#pragma once

#ifndef PROPERTY_HELPER_USE
#define PROPERTY_HELPER_USE 1
#endif

#ifdef PROPERTY_HELPER_USE
#define __PROP_LOCAL_VALUE(__NAME__) __NAME__##_
#define IMPL_PROP_GET(__CLASS__, __TYPE__, __NAME__) __TYPE__^ __CLASS__::__NAME__::get(){return __PROP_LOCAL_VALUE(__NAME__);}
#define IMPL_PROP_SET(__CLASS__, __TYPE__, __NAME__) void __CLASS__::__NAME__::set(__TYPE__^ value){__PROP_LOCAL_VALUE(__NAME__)=value;}
#define IMPL_PROP_GETSET(__CLASS__, __TYPE__, __NAME__) IMPL_PROP_GET(__CLASS__, __TYPE__, __NAME__) IMPL_PROP_SET(__CLASS__, __TYPE__, __NAME__)
#define IMPL_NF_SET(__CLASS__, __TYPE__, __NAME__) \
void __CLASS__::__NAME__::set(__TYPE__^ value) \
{ \
	if(value!=__PROP_LOCAL_VALUE(__NAME__)) \
	{ \
		__PROP_LOCAL_VALUE(__NAME__)=value; \
		RaisePropertyChange(#__NAME__); \
	} \
}
#define IMPL_NF_GETSET(__CLASS__, __TYPE__, __NAME__) IMPL_PROP_GET(__CLASS__, __TYPE__, __NAME__) IMPL_NF_SET(__CLASS__, __TYPE__, __NAME__)

#define IMPL_PROP_VALUE_GET(__CLASS__, __TYPE__, __NAME__) __TYPE__ __CLASS__::__NAME__::get(){return __PROP_LOCAL_VALUE(__NAME__);}
#define IMPL_PROP_VALUE_SET(__CLASS__, __TYPE__, __NAME__) void __CLASS__::__NAME__::set(__TYPE__ value){__PROP_LOCAL_VALUE(__NAME__)=value;}
#define IMPL_PROP_VALUE_GETSET(__CLASS__, __TYPE__, __NAME__) IMPL_PROP_VALUE_GET(__CLASS__, __TYPE__, __NAME__) IMPL_PROP_VALUE_SET(__CLASS__, __TYPE__, __NAME__)
#define IMPL_NF_VALUE_SET(__CLASS__, __TYPE__, __NAME__) \
void __CLASS__::__NAME__::set(__TYPE__ value) \
{ \
	if(value!=__PROP_LOCAL_VALUE(__NAME__)) \
	{ \
		__PROP_LOCAL_VALUE(__NAME__)=value; \
		RaisePropertyChange(#__NAME__); \
	} \
}
#define IMPL_NF_VALUE_GETSET(__CLASS__, __TYPE__, __NAME__) IMPL_PROP_VALUE_GET(__CLASS__, __TYPE__, __NAME__) IMPL_NF_VALUE_SET(__CLASS__, __TYPE__, __NAME__)
#endif