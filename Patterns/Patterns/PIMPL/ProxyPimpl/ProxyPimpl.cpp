#include "ProxyPimpl.h"


namespace ProxyPimpl
{
	implimentation::implimentation()
	{
		printf("Constructor pimple_container\n");
	}


	implimentation::~implimentation()
	{
	}

	void implimentation::say_Hi()
	{
		printf("Hi from pimpl container\n");
	}
}

