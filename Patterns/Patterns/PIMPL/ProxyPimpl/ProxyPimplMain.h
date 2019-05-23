#pragma once
#include <memory>

#include "ProxyPimpl.h"

class ClassUsedProxy {
public:
	ClassUsedProxy();
	~ClassUsedProxy();
	void SayHi();
private:
	std::unique_ptr<pimpl<ProxyPimpl::implimentation>> impl;
};