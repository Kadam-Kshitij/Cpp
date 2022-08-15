// == Output ==
// NULL
// Success
// End

#include <iostream>
#include <exception>

// If new fails then bad_alloc exception is thrown.
// But if we write new ( std::nothrow ), then instead of throwing an exception
// null is returned.

int main()
{
	try
	{
		char* ptr = new ( std::nothrow ) char[0x7ffffffff];

		if ( ptr == NULL )
		{
			std::cout << "NULL\n";
		}
		std::cout << "Success\n";
	}
	catch ( const std::bad_alloc& ex )
	{
		std::cout << "Catch\n";
		std::cout << ex.what() << std::endl;
	}

	std::cout << "End\n";
}
