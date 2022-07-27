// == Output ==
// 23
// 56

#include <iostream>

class Base1
{
protected:
	int x;
public:
	Base1() : x{ 23 }
	{
	}
};

class Base2
{
protected:
	int x;
public:
	Base2() : x{ 56 }
	{
	}
};

class Derived : public Base1, public Base2
{
public:
	Derived() : Base1{}, Base2{}
	{
	}

	void foo()
	{
		std::cout << Base1::x << std::endl;
		std::cout << Base2::x << std::endl;
	}
};

int main()
{
	Derived d;
	d.foo();
}
