// Scoped enum. Strongly typed and strongly scoped.
// Better to use enum class then normal enums.

#include <iostream>

enum class Color
{
	black,
	white
};

enum class Animal
{
	cat,
	dog
};

int main()
{
	// Need to use scope
	Color color = Color::black;

	// Need to use static_cast to print
	std::cout << static_cast< int >( color ) << std::endl;

	Animal animal = Animal::cat;
	// Compilation error ---> Since compiler does not know how to compare type Color and Animal
	// if ( color == animal ) {}

	if ( Color::black == color )
	{
		std::cout << "Will reach here" << std::endl;
	}
}