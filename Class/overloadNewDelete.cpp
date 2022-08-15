// == Output ==
// Base
// 23
// ======
// new Operator
// Base
// 90
// 90 ~Base
// delete Operator
// 23 ~Base

#include <iostream>

class Base
{
	int x;

public:
	Base( const int& val ) : x{ val }
	{
		std::cout << "Base\n";
	}
	~Base()
	{
		std::cout << x << " ~Base\n";
	}

	void* operator new( size_t size )
	{
		std::cout << "new Operator\n";
		return malloc( size );
	}

	void operator delete( void* ptr )
	{
		std::cout << "delete Operator\n";
		free( ptr );
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

	std::cout << "======\n";

	Base* ptr = new Base( 90 );
	ptr->get();

	delete ptr;
}
