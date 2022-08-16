// == Output ==
// this is a string
// this is a string
// thxs is a string
// this is a string

#include <iostream>
#include <string.h>

class Base
{
	char* ch;
public:
	Base( const char* str )
	{
		int length = strlen( str ) + 1;
		ch = new char[length];
		for( int i = 0; i < length; ++i )
		{
			ch[i] = str[i];
		}
	}

	Base( const Base& obj )
	{
		int length = strlen( obj.ch ) + 1;
		ch = new char[length];

		for( int i = 0; i < length; ++i )
		{
			ch[i] = obj.ch[i];
		}		
	}

	void print() const
	{
		std::cout << ch << std::endl;
	}

	void change()
	{
		ch[2] = 'x';	
	}

};

int main()
{
	Base b( "this is a string" );
	b.print();

	Base b1 = b;
	b1.print();

	b.change();
	b.print();
	b1.print();

}
