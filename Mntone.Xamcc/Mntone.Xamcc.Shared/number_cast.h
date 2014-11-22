#pragma once
#include <stdlib.h>

namespace {

	template<typename N> N number_cast( ::Platform::String^ str );
	template<> int8 number_cast( ::Platform::String^ str ) { return static_cast<int8>( _wtoi( str->Data() ) ); }
	template<> uint8 number_cast( ::Platform::String^ str ) { return static_cast<uint8>( wcstoul( str->Data(), nullptr, 10 ) ); }
	template<> int16 number_cast( ::Platform::String^ str ) { return static_cast<int16>( _wtoi( str->Data() ) ); }
	template<> uint16 number_cast( ::Platform::String^ str ) { return static_cast<uint16>( wcstoul( str->Data(), nullptr, 10 ) ); }
	template<> int32 number_cast( ::Platform::String^ str ) { return _wtoi( str->Data() ); }
	template<> uint32 number_cast( ::Platform::String^ str ) { return wcstoul( str->Data(), nullptr, 10 ); }
	template<> int64 number_cast( ::Platform::String^ str ) { return _wtoi64( str->Data() ); }
	template<> uint64 number_cast( ::Platform::String^ str ) { return wcstoull( str->Data(), nullptr, 10 ); }
	template<> float32 number_cast( ::Platform::String^ str ) { return static_cast<float32>( _wtof( str->Data() ) ); }
	template<> float64 number_cast( ::Platform::String^ str ) { return _wtof( str->Data() ); }

}