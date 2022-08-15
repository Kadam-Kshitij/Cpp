#include <iostream>

class Base
{
	int x;

	Base( const int& val ) : x{ val }
	{
	}
public:
	static Base* getInstance( const int& val )
	{
		return ( new Base( val ) );
	}

	void get() const
	{
		std::cout << x << std::endl;
	}
};

class Derived : public Base
{
};

int main()
{
	Base* b = Base::getInstance( 89 );
	b->get();

	// CTE
	// Derived d;	
}
