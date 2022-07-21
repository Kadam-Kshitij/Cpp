#include <iostream>
#include <vector>

int main()
{
	std::vector< int > v = { 1, 2, 3, 4, 5, 6 };
	std::cout << "Vector capacity, size = " << v.capacity() << " " << v.size() << std::endl;

	v.push_back( 12 );
	std::cout << "Vector capacity, size = " << v.capacity() << " " << v.size() << std::endl;
	
	v.push_back( 12 );
	std::cout << "Vector capacity, size = " << v.capacity() << " " << v.size() << std::endl;
}

// Output
// Vector capacity, size = 6 6
// Vector capacity, size = 12 7
// Vector capacity, size = 12 8

// Capacity doubles everytime a reallocation of vector happens
