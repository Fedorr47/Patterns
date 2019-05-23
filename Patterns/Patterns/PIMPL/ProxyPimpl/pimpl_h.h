#pragma once
#include <memory>

template<typename T>
class pimpl {
private:
	std::unique_ptr<T> m;
public:
	pimpl();
	template<typename ...Args> pimpl(Args&& ...);
	~pimpl();
	T* operator->();
	T& operator*();
};