#pragma once
#include <utility>
#include "pimpl_h.h"

template<typename T>
pimpl<T>::pimpl() : m{ new T{} } { }

template<typename T>
template<typename ...Args>
pimpl<T>::pimpl(Args&& ...args)
	: m{ new T{ std::forward<Args>(args)... } } {
	printf("Constructor pimpl\n");
}

template<typename T>
pimpl<T>::~pimpl() { }

template<typename T>
T* pimpl<T>::operator->() { 
	printf("-> pimpl\n");
	return m.get(); 
}

template<typename T>
T& pimpl<T>::operator*() { 
	printf("* pimpl\n");
	return *m.get(); 
}
