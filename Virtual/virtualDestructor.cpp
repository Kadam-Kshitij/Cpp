// == Output ==
// 
// If Base destructor is virtual
// ~Derived()
// ~Base()
//
// If Base destructor is not virtual
// ~Base()

#include <iostream>

class Base
{
public:
	virtual ~Base()
	{
		std::cout << "~Base()\n";
	}
};

class Derived : public Base
{
public:
	~Derived()
	{
		std::cout << "~Derived()\n";
	}
};

int main()
{
	Base* ptr = new Derived();
	delete ptr;
}
