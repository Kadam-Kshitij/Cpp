#include <iostream>

// bool foo( int i )
// {
// 	std::cout << i << " ";
// 	return ( i == 100 ? true : foo( i+1 ) );
// }

// int main()
// {
// 	int i = 1;
// 	foo( i );
// }


class Base
{
public:
	static int val;

	Base()
	{
		std::cout << val << " ";
		++val; 
	}
};
int Base::val = 1;

int main()
{
	Base arr[100];
}
