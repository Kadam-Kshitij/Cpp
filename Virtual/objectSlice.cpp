// == Output ==
// Derived
// Base

#include <iostream>

class Base
{
public:
	virtual void foo() const
	{
		std::cout << "Base" << std::endl;
	}
};

class Derived : public Base
{
public:
	void foo() const override
	{
		std::cout << "Derived" << std::endl;
	}
};

int main()
{
	Derived d;

	Base* ptr = &d;
	ptr->foo();

	Base b = d;
	b.foo();
}
