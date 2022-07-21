#include <iostream>
#include <functional>	// For std::function

int foo( float f, std::string str )
{
	std::cout << "Function foo " << f << "\n";
	return 0;
}

int hoo( float f, std::string str )
{
	std::cout << "Function hoo " << f << "\n";
	return 0;
}

void goo( int ( *fptr )( float, std::string ) = foo )	// Provided default value
{
	fptr( 4.5, "qwe" );
}

class Base
{
public:
	void zoo( int z )
	{
		std::cout << "Function zoo " << z << "\n";
	}
};


int main()
{
	int ( *fptr1 )( float, std::string ) = foo;
	int ( *fptr2 )( float, std::string ) = &foo;

	fptr1( 23.4, "abc" );		// Implicit dereference
	( *fptr2 )( 41.7, "pqr" );	// Explicit dereference

	goo( fptr1 );	// Passing function pointer to function
	goo();

	int ( *fptrarray[] )( float, std::string ) = { foo, hoo };	// Array of function pointers
	( fptrarray[0] )( 12.9, "plo" );
	( fptrarray[1] )( 9.8, "pol" );

	std::function< int( float, std::string ) > fptr3 = hoo;		// Using std library
	fptr3( 3.67, "fgh" );

	// Function pointer to class member fnuctions
	Base b;
	void ( Base::*cptr )( int ) = &Base::zoo;
	( b.*cptr )( 23 );

	Base* obj = new Base();
	void ( Base::*cptr2 )( int ) = &Base::zoo;
	( obj->*cptr2 )( 71 );
}

// Output
// Function foo 23.4
// Function foo 41.7
// Function foo 4.5
// Function foo 4.5
// Function foo 12.9
// Function hoo 9.8
// Function hoo 3.67
// Function zoo 23
// Function zoo 71
