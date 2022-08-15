// == Output ==
// 78 88
// 78 93

#include <iostream>

class Base
{
	int x;
	mutable int y;

public:
	Base( const int& val ) : x{ val }, y{ val + 10 }
	{
	}

	void foo() const
	{
		y += 5;
		// x += 90; // CTE
	}

	void get() const
	{

		std::cout << x << " " << y << std::endl;
	}
};

int main()
{
	const Base b( 78 );
	b.get();

	b.foo();
	b.get();
}
