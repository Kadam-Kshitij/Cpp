#include <iostream>

using namespace std;

class Base
{
    int* ptr;
    char* ch;
public:
    Base( const int& i, const char* str )
    {
        ptr = new int;
        *ptr = i;

        int length = std::strlen( str );
        ch = new char[length+1];

        for ( int i = 0; i < length+1; ++i )
        {
            ch[i] = str[i];
        }
    }

    Base( const Base& obj )
    {
        this->ptr = new int;
        *( this->ptr ) = *( obj.ptr );

        int length = std::strlen( obj.ch );

        this->ch = new char[ length + 1 ];
        for( int i = 0; i < length + 1; ++i )
        {
            ch[i] = obj.ch[i];
        }
        ch[0] = 'K';
    }

    void print() const
    {
        std::cout << *ptr << std::endl;
        std::cout << ch << std::endl;
    }

    void set( const int& i )
    {
        *ptr = i;
    }
    void changeString( const char c )
    {
        ch[4] = c;
    }
};

int main()
{
    Base b( 21, "This is a string" );
    b.print();

    Base b2( b );
    b2.print();
    b2.set( 90 );

    b.print();
    b2.print();

    b.set( 88 );
    b.print();
    b2.print();

    b.changeString( 'f' );
    b.print();
    b2.print();

    b2.changeString( 'o' );
    b.print();
    b2.print();
}
