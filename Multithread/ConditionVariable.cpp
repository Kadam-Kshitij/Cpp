#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>
#include <condition_variable>

std::mutex mu;
std::condition_variable cv;
static int x = 0;

void func()
{
	std::unique_lock< std::mutex > ul( mu );
	std::cout << "Wait start\n";
	cv.wait( ul, [](){ return ( 1 == x ); } );
	std::cout << "Wait over\n";
}

void foo()
{
	std::this_thread::sleep_for( std::chrono::milliseconds( 3000 ) );
	std::cout << "Nofify\n";
	x = 2;
	cv.notify_one();
}

int main()
{
	std::thread t1( func );
	std::thread t2( foo );

	t1.join();
	t2.join();
}

// -- Output --
// Wait start
// Wait over
// Nofify
