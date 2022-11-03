#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>

std::mutex mu;
static int n = 50;

void display( int c, const std::string& str )
{
	for( int i = 0; i < c; i += 2 )
	{
		mu.lock();
		if ( "First" == str )
		{
			++n;
		}
		else
		{
			--n;
		}
		std::cout << str << " " << n << "\n";
		mu.unlock();
		std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
	}
}

int main()
{
	std::thread t1( display, 10, "First" );
	std::thread t2( display, 10, "Second" );

	t1.join();
	t2.join();

	std::cout << "Final - " << n << std::endl;
}

// -- Output --
// First 51
// Second 50
// First 51
// Second 50
// First 51
// Second 50
// First 51
// Second 50
// First 51
// Second 50
// Final - 50
