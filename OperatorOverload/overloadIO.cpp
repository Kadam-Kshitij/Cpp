// == Output ==
// Enter 2 names : John Man
// John
// Man

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
	friend std::istream& operator>>( std::istream& os, Base& b );
};

std::ostream& operator<<( std::ostream& os, const Base& b )
{
	os << b.str;
	return os;
}

std::istream& operator>>( std::istream& is, Base& b )
{
	is >> b.str;
	return is;
}

// ============================================================
int main()
{
	Base b1{ "Carey" };
	Base b2{ "Alex" };

	std::cout << "Enter 2 names : ";
	std::cin >> b1;
	std::cin >> b2;

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
}
