// == Output ==
// Carey
// Alex

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

	friend std::ostream& operator<<( std::ostream& os, const Base& b );
};

std::ostream& operator<<( std::ostream& os, const Base& b )
{
	os << b.str;
	return os;
}

// ============================================================
int main()
{
	Base b1{ "Carey" };
	Base b2{ "Alex" };

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
}
