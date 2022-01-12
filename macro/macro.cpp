#include <iostream>

#define x 5+2
#define p foo( 23 )

#define z 0
#define y 2

int foo ( int i )
{
	return 10 + i;
}

int main()
{
	// Just replaces whatever content is present with the substitution text
	std::cout << x << "\n";	// Prints 7
	std::cout << p << "\n";	// Prints 33

	// ifdef only checks if defined. #if also checks value is not zero
#ifdef z
	std::cout << "Debug 0" << z << "\n";
#endif
#if z
	std::cout << "Debug 1" << z << "\n";
#endif

#if y == 2
	std::cout << "Debug 2" << "\n";
#else
	std::cout << "Debug 3" << "\n";
#endif	
}
