// == Output ==


// ============================================================
#include <iostream>

class Base
{
	int val;
public:
	Base( const int& v ) : val{ v }
	{	
	}

	int get() const
	{
		return val;
	}

	void print() const
	{
		std::cout << val << std::endl;
	}

	bool operator<( const Base& b );
};

bool Base::operator<( const Base& b )
{
	return ( val < b.get() );
}

// ============================================================
int main()
{
	Base b1{ 23 };
	Base b2{ 9 };

	if ( b1 < b2 )
	{
		std::cout << "Debug1\n";
	}
	else
	{
		std::cout << "Debug2\n";
	}
}
