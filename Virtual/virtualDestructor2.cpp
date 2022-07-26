// == Output ==
// 16
// 8

#include <iostream>

class Base
{
	double a;
public:
	virtual ~Base()
	{
		std::cout << "~Base()\n";
	}
};

class Base1
{
	double a;
public:
	~Base1()
	{
		std::cout << "~Base()\n";
	}
};

int main()
{
	std::cout << sizeof( Base ) << std::endl;
	std::cout << sizeof( Base1 ) << std::endl;
}
