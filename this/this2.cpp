#include <iostream>

class Base
{
	int x;
public:
	Base() : x( 13 )
	{
		std::cout << "Constructor" << std::endl;
		//delete this;
	}
	~Base()
	{
		std::cout << "Destructor" << std::endl;
		//delete this;
	}

	void foo()
	{
		std::cout << "foo " << x << std::endl;
		delete this;
		std::cout << "foo " << x << std::endl;
	}
};

int main()
{
	Base* b = new Base;
	b->foo();
	delete b;
}

/**
OUTPUT
Constructor
foo 13
Destructor
foo 0
Destructor
free(): double free detected in tcache 2
Aborted (core dumped)
**?
