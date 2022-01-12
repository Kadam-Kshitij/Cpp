// Enum is like user defined data type

#include <iostream>

// Forward declaration of enum
enum State : int;
enum State : int
{
	goa,
	sikkim
};

enum Color
{
	red,	// 0
	green,	// 1
	blue	// 2
};

enum Animal
{
	cat = 1,	// 1
	dog,		// 2
	cow			// 3
};

// Can have -ve values
enum Country
{
	india = -1,		// -1
	cuba,			// 0
	germany = 4,	// 4
	australia		// 5
};

// Two enum can have same integer value
enum Color2
{
    color_black,		// 0
    color_red,			// 1
    color_blue,			// 2
    color_green = -1,	// -1
    color_white,		// 0
    color_cyan,			// 1
    color_yellow,		// 2
    color_magenta		// 3
};

enum Bird
{
	crow,
	kingfisher,
};

enum Bird2
{
	owl,
	sparrow
};

// Compilation error ---> Since india is already defined.
//enum Place
//{
//	mumbai,
//	india
//}

int main()
{
	Color color = red;
	std::cout << color << std::endl;	// Output as 0

	Animal animal = dog;
	std::cout << animal << std::endl;	// Output as 2

	Country country = india;
	std::cout << country << std::endl;	// Output as -1

	std::cout << std::endl;
	// Disadvantage of enum. Tries to compare integer values and enters the if loop
	color = green;
	animal = cat;
	if ( green == cat )
	{
		std::cout << "Wrongly output as true" << std::endl;
	}
	// This can be avoided using enum class

	// std::cout << std::endl;
	// Color2 color2 = color_black;
	// std::cout << color2 << std::endl;	// Output as 0
	// color2 = color_red;
	// std::cout << color2 << std::endl;	// Output as 1
	// color2 = color_blue;
	// std::cout << color2 << std::endl;	// Output as 2
	// color2 = color_green;
	// std::cout << color2 << std::endl;	// Output as -1
	// color2 = color_white;
	// std::cout << color2 << std::endl;	// Output as 0
	// color2 = color_cyan;
	// std::cout << color2 << std::endl;	// Output as 1
	// color2 = color_yellow;
	// std::cout << color2 << std::endl;	// Output as 2
	// color2 = color_magenta;
	// std::cout << color2 << std::endl;	// Output as 3

	// Enum can be of type int
	std::cout << std::endl;
	int bird = crow;
	std::cout << bird << std::endl;			// Output as 0

	std::cout << std::endl;
	// Another way to define
	// Bird2 bird2 = 1;  ----> Compilation error
	Bird2 bird2 = static_cast< Bird2 >( 1 );
	std::cout << bird2 << std::endl;		// Output as 1

}