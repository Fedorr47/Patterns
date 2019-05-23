#include <iostream>

#include "simplePimple.h"

void* operator new(size_t count) {
	std::cout << "allocating " << count << " bytes\n";
	return malloc(count);
}

void operator delete(void* ptr) noexcept {
	std::cout << "global op delete called\n";
	free(ptr);
}

class MyClassImpl
{
public:
	MyClassImpl(MyClass* pBackPtr) : m_pMainClass(pBackPtr) { }
	~MyClassImpl() = default;

	void DoSth() { std::cout << "Val (incremented): " << ++m_val << "\n"; }

	// try to uncomment (or comment 'const' for the method)
	void DoConst() const {
		std::cout << "Val: " << /*++*/m_val << "\n";
	}

private:
	int m_val{ 0 };
	MyClass* m_pMainClass{ nullptr }; // back pointer
};

MyClass::MyClass() : m_pImpl(new MyClassImpl(this))
{
	std::cout << __FUNCSIG__ << "\n";
}

MyClass::~MyClass() { std::cout << __FUNCSIG__ << "\n"; }
MyClass::MyClass(MyClass &&) noexcept = default;
MyClass& MyClass::operator=(MyClass &&) noexcept = default;

MyClass::MyClass(const MyClass& rhs)
	: m_pImpl(new MyClassImpl(*rhs.m_pImpl))
{}

MyClass& MyClass::operator=(const MyClass& rhs) {
	if (this != &rhs)
		m_pImpl.reset(new MyClassImpl(*rhs.m_pImpl));

	return *this;
}

void MyClass::DoSth()
{
	Pimpl()->DoSth();
}

void MyClass::DoConst() const
{
	Pimpl()->DoConst();
}