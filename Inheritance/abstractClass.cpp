// == Output ==
// Foo
// Goo
// Foo
// Goo
// Foo
// Goo

//===================================================
#include <iostream>

class Base
{
public:
	virtual void foo() = 0;
	void goo()
	{
		std::cout << "Goo" << std::endl;
	}
};

class Derived : public Base
{
public:
	void foo() override
	{
		std::cout << "Foo" << std::endl;
	}
};

//===================================================
int main()
{
	// CTE - Cannot create instance of abstract class
	// Base b;

	Base* ptr = new Derived();
	ptr->foo();
	ptr->goo();

	Derived obj;
	obj.foo();
	obj.goo();

	Base& ref = obj;
	ref.foo();
	ref.goo();
}
