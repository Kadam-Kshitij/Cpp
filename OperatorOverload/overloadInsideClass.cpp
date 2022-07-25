// == Output ==
// Carey Alex
// Carey Alex Alex

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

	
	Base operator+( const Base& b2 )
	{
		Base b{ str + " " + b2.str };
		return b;
	}
};

// ============================================================
int main()
{
	Base b1{ "Carey" };
	Base b2{ "Alex" };

	Base b3 = b1 + b2;
	b3.print();

	Base b4 = b3 + b2;
	b4.print();
}
