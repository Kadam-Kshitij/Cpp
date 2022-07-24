// == Output ==
// Goo
// Foo 82

#include <iostream>

class Base
{
	class Nested
	{
		int a;
	public:
		Nested( int x ) : a{ x }
		{
		}

		void foo()
		{
			std::cout << "Foo " << a << std::endl;
		}
	}* obj;

public:
	Base( int x ) : obj{ new Nested( x ) }
	{
	}

	void goo()
	{
		std::cout << "Goo\n";
		obj->foo();
	}
};

int main()
{
	Base b( 82 );
	b.goo();
}
