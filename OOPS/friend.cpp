// == Output ==
// Foo
// Goo, a = 20
// Foo
// Hoo, a = 20

// ==========================================================
#include <iostream>

class Base
{
	int a;
public:
	Base() : a{ 20 }
	{
	}

	void foo() const
	{
		std::cout << "Foo\n";
	}

	friend class Friend;
	friend void goo( const Base& b );
};

// ==========================================================
void goo( const Base& b )
{
	b.foo();
	std::cout << "Goo, a = " << b.a << std::endl;
}

class Friend
{
public:
	void hoo( const Base& b )
	{
		b.foo();
		std::cout << "Hoo, a = " << b.a << std::endl;	
	}
};

// ==========================================================
int main()
{
	Base b;
	goo( b );

	Friend f;
	f.hoo( b );
}
