#include <iostream>

class foo
{
private:
	int x;
	float y;
	char ch;
public:
	foo() : x( 10 ), y( 13.5 ), ch( 'H' )
	{
	}
};

int main()
{
	foo* p = new foo;
	int* ptr = NULL;
	ptr = reinterpret_cast< int* >( p );
	std::cout << *ptr << std::endl;
	++ptr;
	float* fptr = reinterpret_cast< float* >( ptr );
	std::cout << *fptr << std::endl;
	++fptr;
	char* cptr = reinterpret_cast< char* >( fptr );
        std::cout << *cptr << std::endl;
}

/**
OUTPUT
10
13.5
H
**/
