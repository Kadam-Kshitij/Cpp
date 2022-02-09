#include <iostream>

int main()
{
	int a = 12, b = 56, y, x = 1;
	int arr[2] = { a, b };

	y = arr[x];
	std::cout << y << std::endl; 

	x = 0;
	y = arr[x];
        std::cout << y << std::endl;
}

/**
OUTPUT
56
12
**/
