// == Output ==
// Base - BaseFOO
// Derived - DerivedFOO
// ~Derived - DerivedFOO
// ~Base - BaseFOO

#include <iostream>

class Base
{
public:
	Base()
	{
		std::cout << "Base - ";
		foo();
	}
	~Base()
	{
		std::cout << "~Base - ";
		foo();
	}

	virtual void foo() const
	{
		std::cout << "BaseFOO\n";
	}
};

class Derived : public Base
{
public:
	Derived()
	{
		std::cout << "Derived - ";
		foo();
	}
	~Derived()
	{
		std::cout << "~Derived - ";
		foo();
	}

	void foo() const override
	{
		std::cout << "DerivedFOO\n";
	}
};

int main()
{
	Derived obj;
}
