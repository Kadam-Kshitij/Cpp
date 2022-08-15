#include <iostream>

class Base
{
	int x;

public:
	Base( const int& val ) : x{ val }
	{
	}

	void get() const
	{
		std::cout << x << std::endl;
	}
};

template< typename T >
class smartPointer
{
	T* ptr;
public:
	smartPointer( T* x ) : ptr{ x }
	{
	}

	~smartPointer()
	{
		delete ptr;
	}

	T* operator->()
	{
		return ptr;
	}
};	


int main()
{
	Base* b = new Base( 47 );
	smartPointer< Base > sp( b );
	sp->get();
}
