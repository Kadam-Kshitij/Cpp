// == Output ==
// Kshitij Kadam
// Kshitij Kadam Kadam

// ============================================================
#include <iostream>

class Base
{
	std::string str;
public:
	Base( const std::string& s ) : str{ s }
	{
	}

	void print() const
	{
		std::cout << str << std::endl;
	}

	friend Base operator+( const Base& b1, const Base& b2 );
};

Base operator+( const Base& b1, const Base& b2 )
{
	Base b{ b1.str + " " + b2.str };
	return b;
}

// ============================================================
int main()
{
	Base b1{ "Kshitij" };
	Base b2{ "Kadam" };

	Base b3 = b1 + b2;
	b3.print();

	Base b4 = b3 + b2;
	b4.print();
}
