// == Output ==
// Foo Derived
// Foo Base
// Foo Base
// Foo Base

#include <iostream>

class Base
{
public:
	void foo()
	{
		std::cout << "Foo Base\n";
	}
};

class Derived : public Base
{
public:
	void foo()
	{
		std::cout << "Foo Derived\n";
		Base::foo();
	}
};

int main()
{
	Derived d;
	d.foo();
	d.Base::foo();

	Base* ptr = &d;
	ptr->foo();
}
