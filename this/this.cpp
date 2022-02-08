#include <iostream>

class Base
{
public:
	Base()
	{
		std::cout << "Constructor " << this << std::endl;
		std::cout << "sizeof = " << sizeof( this ) << std::endl;
	}

	void foo()
	{
		std::cout << this << std::endl;
		// CTE - this is rvalue not lvalue.
		// So cannot access its address
		// this = new Base;
		// std::cout << &this;
	}

	// CTE - this pointer is not available inside this pointer
	// static void goo()
	// {
	// 	std::cout << this << std::endl;
	// }
	
	friend void hoo();
};

void hoo()
{
	std::cout << __FUNCTION__ << std::endl;
	// CTE - this not available in friend function
	// std::cout << this;
}

int main()
{
	Base obj;
	std::cout << &obj << std::endl;
	obj.foo();

	Base* o = new Base;
	std::cout << o << std::endl;
        o->foo();

	hoo();
}

/**
OUTPUT
Constructor 0x7ffd3dad4fff
8
0x7ffd3dad4fff
0x7ffd3dad4fff
Constructor 0x55c857d5a2c0
8
0x55c857d5a2c0
0x55c857d5a2c0
hoo
**/
