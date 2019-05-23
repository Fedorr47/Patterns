// PIMPL_all.cpp : Defines the entry point for the application.
//

#include "PIMPL/ProxyPimpl/ProxyPimplMain.h"
#include "PIMPL/BackPimpl/simplePimple.h"

using namespace std;

int main()
{
	//ClassUsedProxy *cud = new ClassUsedProxy;
	//cud->SayHi();

	MyClass myObject;
	myObject.DoSth();

	const MyClass secondObject;
	secondObject.DoConst();

	return 0;
}