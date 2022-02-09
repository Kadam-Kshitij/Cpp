#include <iostream>

int& foo( int& y )
{
	return y;
}

int main()
{
	int y = 19;
	foo( y ) = 12;
	std::cout << y << std::endl;
}
