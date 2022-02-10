#include <iostream>

class A
{
public:
	A()
	{
		std::cout << "Construct A" << std::endl;
	}
	~A()
	{
		std::cout << "Destructor A" << std::endl;
	}
};

class B
{
public:
	static A a;
	static int i;
	B()
	{
		std::cout << "Constructor B" << std::endl;
	}
	~B()
	{
		std::cout << "Destructor B" << std::endl;
	}
};
A B::a;
int B::i = 13;

class C
{
public:
	static C obj;
	C()
	{
		std::cout << "Constructor C" << std::endl;
	}
	~C()
	{
		std::cout << "Destructor C" << std::endl;
	}
};
C C::obj;

int main()
{
	std::cout << "i = " << B::i << std::endl;
	B::i = 12;
	std::cout << "i = " << B::i << std::endl;
	B b1;
	B b2;
	std::cout << "End main" << std::endl;
}

/**
Construct A
Constructor C
i = 13
i = 12
Constructor B
Constructor B
End main
Destructor B
Destructor B
Destructor C
Destructor A
**/
