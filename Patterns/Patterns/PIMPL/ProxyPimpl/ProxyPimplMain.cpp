#include "ProxyPimplMain.h"

ClassUsedProxy::ClassUsedProxy()
{ 
	impl = std::make_unique<pimpl<ProxyPimpl::implimentation>>();
}

ClassUsedProxy::~ClassUsedProxy() { } // or =default

void ClassUsedProxy::SayHi()
{
	printf("Now pipl say hi to you!\n");
	(*impl)->say_Hi();
}
