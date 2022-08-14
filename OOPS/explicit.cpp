// == Output ==
// With explicit - CTE
// Without explicit
// 23
// Foo 
// 34

#include <iostream>

class Base
{
	int ch;
public:
	/* explicit */ Base( const int c ) : ch{ c }
	{
	}

	void print() const
	{
		std::cout << ch << std::endl;
	}
};

void foo( Base b )
{
	std::cout << "Foo " << std::endl;
	b.print();
}

int main()
{
	Base b{ 23 };
	b.print();

	foo( 34 );
}
