// Here since mutex is within Data,
// func can run in parallel for different threads
// if function paramter is different instance of data for each thread.

#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>

struct Data {
	int i;
	std::mutex mu;
	Data( const int& n )
	{
		i = n;	
	}
};

void func( Data& data )
{
	data.mu.lock();
	for( int i = 0; i < 20; ++i )
	{
		++data.i;	
		std::this_thread::sleep_for( std::chrono::milliseconds( 200 ) );
	}
	data.mu.unlock();
}

int main()
{
	auto start = std::chrono::system_clock::now();

	Data d1( 23 );
	Data d2( 78 );
	Data d3( 96 );

	/*
	 * If d1, d1, d1 - 12 seconds
	 * If d1, d1, d2 - 8 seconds
	 * If d1, d2, d3 - 4 seconds
	*/
	std::thread t1( func, std::ref( d1 ) );
	std::thread t2( func, std::ref( d2 ) );
	std::thread t3( func, std::ref( d3 ) );

	t1.join();
	t2.join();
	t3.join();

	std::cout << "Data 1 = " << d1.i << std::endl;
	std::cout << "Data 2 = " << d2.i << std::endl;
	std::cout << "Data 3 = " << d3.i << std::endl;

	auto end = std::chrono::system_clock::now();
	std::cout << "Time = " << ( end - start ).count() << std::endl;
}
