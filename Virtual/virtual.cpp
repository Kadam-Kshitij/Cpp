#include <iostream>

class Base
{
public:
	Base()
	{
		std::cout << "Base - \n";
	}
	~Base()
	{
		std::cout << "~Base - \n";
	}

	virtual void foo() const
	{
		std::cout << "BaseFOO\n";
	}

	void goo() const
	{
		std::cout << "GOO\n";
	}
};

class Derived : public Base
{
public:
	Derived()
	{
		std::cout << "Derived - \n";
	}
	~Derived()
	{
		std::cout << "~Derived - \n\n";
	}

	void foo() const override
	{
		std::cout << "DerivedFOO\n";
	}

	void hoo() const
	{
		std::cout << "HOO\n";
	}
};

int main()
{
	Derived obj;
	obj.foo();	// DerivedFOO
	obj.goo();	// GOO
	obj.hoo();	// HOO

	Base b;
	b.foo();	// BaseFOO
	b.goo();	// GOO
	// b.hoo(); // CTE

	Base s = obj;
	s.foo();	// BaseFOO
	s.goo();	// GOO
	// s.hoo(); // CTE

	Base* ptr = &obj;
	ptr->foo();	// DerivedFOO
	ptr->goo();	// GOO
	// ptr->hoo();	// CTE

	Base& ref = obj;
	ref.foo();	// DerivedFOO
	ref.goo();	// GOO
	// ref.hoo(); // CTE
}
