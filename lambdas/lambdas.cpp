// Kind of anonymous functions in C++
// Used in STL algorithms to as 

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	// Syntax
	// [capture-clause] ( int x, int y ) -> return val { statements };
	// return type is generally not needed as it is figured out by compiler
	// however in some cases it might not be able to. IN such cases return type must be given.
	auto l = [] ( int a ) { return a + 6; };
	std::cout << l( 34 ) << std::endl;	// 40

	// int x = 12, y = 9;
	// foo( ( int )( [] ( int x, int y ) -> int { return x > y ? x : y; } ) );

	// Here all external values are referenced inside lambdas by reference
	int a = 12, b = 90;
	auto l1 = [&] ( int x, int y ) { a = 100 + x; b = 200 + y; };
	l1( 14, 27 );
	std::cout << a << " " <<  b << std::endl;	// 114 227

	// Here all externel values are referenced inside lambdas by value
	int a1 = 12, b1 = 90;
        auto l2 = [=] { std::cout << a1 + b1 << std::endl; };	// 102
	l2();

	// CTE - assignment to read only variables
	// auto l3 = [=] { a = 10; };		// All external variables as reference
	// auto l4 = [a,&b] { a = 10; };	// Here a is by value, b by reference
	
	// Another way to send by reference
	auto l5 = [] ( int& x ) { x = 999; };
	l5( b1 );
	std::cout << "b1 = " << b1 << std::endl; // 999

	// CTE - a1 not captured - [] means external values cannot be referenced
	// auto l6 = [] { a1 = 12; };

	// Use of lambdas in STL algorithms
	std::vector< int > v = { 1, 2, 3, 4 , 17 };
	std::for_each( v.begin(), v.end(), [] ( int& x ) { std::cout << 2 * x << " "; } );
	std::cout << "\n";
}
