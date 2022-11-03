#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

void even( const int& n, const std::string& str )
{
	for( int i = 0; i < n; i += 2 )
	{
		std::cout << str << i << "\n";
		std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
	}
}

void odd( const int& n, const std::string& str )
{
	for( int i = 1; i < n; i += 2 )
	{
		std::cout << str << i << "\n";
		std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
	}
}

int main()
{
	std::thread t1( even, 10, "Even " );
	std::thread t2( odd, 10, "Odd " );

	t1.join();
	t2.join();
}

// -- Output --
// Even 0
// Odd 1
// Even 2
// Odd 3
// Even 4
// Odd 5
// Even 6
// Odd 7
// Even 8
// Odd 9
