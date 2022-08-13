#include <iostream>

int main()
{
	int** ptr = new int*[3];

	for( int i = 0; i < 3; ++i )
	{
		ptr[i] = new int[4];
	}

	for ( int i = 0; i < 3; ++i )
	{
		for( int j = 0; j < 4; ++j )
		{
			ptr[i][j] = i * 10 + j;
		}
	}

	for ( int i = 0; i < 3; ++i )
	{
		for( int j = 0; j < 4; ++j )
		{
			std::cout << ptr[i][j] << std::endl;
		}
	}

	for( int i = 0; i < 3; ++i )
	{
		delete[] ptr[i];
	}

	delete[] ptr;
}
