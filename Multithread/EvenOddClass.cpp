#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

class Base
{
	std::string obj;
public:
	Base( const std::string& s );
	void even( const int& n, const std::string& str );
	void odd( const int& n, const std::string& str );
};

Base::Base( const std::string& s ) : obj{ s }
{
}

void Base::even( const int& n, const std::string& str )
{
	for( int i = 0; i < n; i += 2 )
	{
		std::cout << str << i << " " << obj << "\n";
		std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
	}
}

void Base::odd( const int& n, const std::string& str )
{
	for( int i = 1; i < n; i += 2 )
	{
		std::cout << str << i << " " << obj << "\n";
		std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
	}
}

int main()
{
	Base b1( "obj1" );
	Base b2( "obj2" );

	std::thread t1( &Base::even, b1, 10, "Even " );
	std::thread t2( &Base::odd, b2, 10, "Odd " );

	t1.join();
	t2.join();
}

// -- Output --
// Even 0 obj1
// Odd 1 obj2
// Even 2 obj1
// Odd 3 obj2
// Even 4 obj1
// Odd 5 obj2
// Even 6 obj1
// Odd 7 obj2
// Even 8 obj1
// Odd 9 obj2
