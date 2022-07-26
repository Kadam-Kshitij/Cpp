// == Output ==
// Base
// Derived
// Derived

#include <iostream>

class Base
{
public:
	virtual void foo( std::ostream& os ) const
	{
		os << "Base\n";
	}
	friend std::ostream& operator<<( std::ostream& os, const Base& b );
};

std::ostream& operator<<( std::ostream& os, const Base& b )
{
	b.foo( os );
	return os;
}

class Derived : public Base
{
public:
	void foo( std::ostream& os ) const override
	{
		os << "Derived\n";
	}
	friend std::ostream& operator<<( std::ostream& os, const Derived& d );
};

std::ostream& operator<<( std::ostream& os, const Derived& d )
{
	d.foo( os );
	return os;
}

int main()
{
	Base b;
	Derived d;
	std::cout << b;
	std::cout << d;

	Base* ptr = &d;
	std::cout << *ptr;
}
