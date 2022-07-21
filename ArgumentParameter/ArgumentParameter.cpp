#include <iostream>

int global = 12;

void foo( int* ptr )
{
	ptr = &global;
}

void goo( int*& ptr )
{
	ptr = &global;
}

int main()
{
	int a = 10;
	int* ptr = &a;

	foo( ptr );	// Pointer not passed by reference
	std::cout << *ptr << std::endl;

	goo( ptr ); // pointer passed by reference
	std::cout << *ptr << std::endl;	
}

// Output
// 10
// 12
