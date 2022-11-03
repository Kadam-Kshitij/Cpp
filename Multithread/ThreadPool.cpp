#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <algorithm>
#include <chrono>

static int threadCount = 1;

// ---------------------------------------------------------------------
struct myThread {
	std::thread th;
	std::condition_variable cv;
	std::mutex mu;
	bool isStarted;
	void* ( *fn )( void* );
	int count;
	bool run;
};


// ---------------------------------------------------------------------
struct threadPool {
	std::vector< myThread* > poolVect;
	std::mutex mu;
};


// ---------------------------------------------------------------------
void* foo( void* ptr )
{
	myThread* currentThread = ( myThread* )ptr;

	for( int i = 0; i < 5; ++i )
	{
		std::cout << "Thread : " << currentThread->count << std::endl;
		std::this_thread::sleep_for( std::chrono::milliseconds( 1000 ) );
	}
	return nullptr;
}


// ---------------------------------------------------------------------
class ThreadPool
{
private:
	threadPool* pool;
	void loopFunction( myThread* th );

public:
	ThreadPool();
	~ThreadPool();

	void addThreadToPool();
	void startThread( void* ( *fptr )( void* ) );
};


// ---------------------------------------------------------------------
ThreadPool::ThreadPool()
{
	pool = new threadPool();
}

ThreadPool::~ThreadPool()
{
	for_each( pool->poolVect.begin(), pool->poolVect.end(),
		 []( auto& ptr ){ delete ptr; } );
	delete pool;
}

void ThreadPool::addThreadToPool()
{
	myThread* thread = new myThread();
	thread->isStarted = false;
	thread->run = false;
	thread->count = threadCount;
	++threadCount;

	pool->mu.lock();
	pool->poolVect.push_back( thread );
	pool->mu.unlock();
}

void ThreadPool::startThread( void* ( *fptr )( void* ) )
{
	if ( 0 == pool->poolVect.size() )
	{
		std::cout << "No threads available\n";
		return;
	}

	pool->mu.lock();
	myThread* currentThread = pool->poolVect[pool->poolVect.size()-1];
	pool->poolVect.pop_back();
	pool->mu.unlock();

	currentThread->fn = fptr;

	if ( ! currentThread->isStarted )
	{
		currentThread->isStarted = true;
		currentThread->th = std::thread( &ThreadPool::loopFunction, this, currentThread );
	}
	else
	{
		currentThread->run = true;
		currentThread->cv.notify_all();
	}
}

void ThreadPool::loopFunction( myThread* th )
{
	myThread* currentThread = th;

	while(1)
	{
		currentThread->fn( ( void* )currentThread );
		pool->mu.lock();
		pool->poolVect.push_back( currentThread );
		pool->mu.unlock();
		currentThread->run = false;
		std::unique_lock< std::mutex > ul( currentThread->mu );
		currentThread->cv.wait( ul, [&]{ return currentThread->run; } );
	}
}


// ---------------------------------------------------------------------
int main()
{
	ThreadPool* pool = new ThreadPool();
	for( int i = 0; i < 4; ++i )
	{
		pool->addThreadToPool();
	}

	for( int i = 0; i < 4; ++i )
	{
		pool->startThread( &foo );
	}

	std::this_thread::sleep_for( std::chrono::milliseconds( 6000 ) );

	for( int i = 0; i < 2; ++i )
	{
		pool->startThread( &foo );
	}

	std::this_thread::sleep_for( std::chrono::milliseconds( 6000 ) );

	for( int i = 0; i < 2; ++i )
	{
		pool->startThread( &foo );
	}

	while(1)
	{
	}
}
