#pragma once

#include <memory>

class MyClassImpl;
class MyClass
{
public:
	explicit MyClass();
	~MyClass();

	// movable:
	MyClass(MyClass && rhs) noexcept;
	MyClass& operator=(MyClass && rhs) noexcept;

	// and copyable:
	MyClass(const MyClass& rhs);
	MyClass& operator=(const MyClass& rhs);

	void DoSth();
	void DoConst() const;

private:
	// const access:
	const MyClassImpl* Pimpl() const { return m_pImpl.get(); }
	MyClassImpl* Pimpl() { return m_pImpl.get(); }

	std::unique_ptr<MyClassImpl> m_pImpl;
};