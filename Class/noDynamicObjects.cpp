#include <iostream>

class Base
{
	int x;

	void* operator new( size_t size );
public:
	Base( const int& val ) : x{ val }
	{
	}

	void get() const
	{
		std::cout << x << std::endl;
	}
};

int main()
{
	Base b( 23 );
	b.get();

	// CTE - new is private
	// Base* ptr = new Base( 90 );
}
