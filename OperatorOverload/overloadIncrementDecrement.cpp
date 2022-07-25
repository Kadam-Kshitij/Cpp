// == Output ==
// 23
// 23
// 25
// 24
// 24

// ============================================================
#include <iostream>

class Base
{
	int val;
public:
	Base( const int& v ) : val{ v }
	{
	}

	void print() const
	{
		std::cout << val << std::endl;
	}

	Base& operator++();
	Base operator++( int );
	Base& operator--();
	Base operator--( int );
};

Base& Base::operator++()
{
	++val;
	return *this;
}

Base Base::operator++( int )
{
	Base b{ *this };
	++val;
	return b;
}

Base& Base::operator--()
{
	--val;
	return *this;
}

Base Base::operator--( int )
{
	Base b{ *this };
	--val;
	return b;
}

// ============================================================
int main()
{
	Base b1{ 23 };

	Base b3 = b1++;
	Base b4 = ++b1;

	Base b5 = --b1;
	Base b6 = b1--;

	b1.print();
	b3.print();
	b4.print();
	b5.print();
	b6.print();
}
