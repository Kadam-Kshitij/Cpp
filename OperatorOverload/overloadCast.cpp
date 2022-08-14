#include <iostream>

class Money
{
    int m;
    std::string str;
    int arr[10];
public:
    Money( int x, std::string s ) : m{x}, str{s}
    {
        for ( int i = 0; i < 10; ++i )
        {
            arr[i] = i * 4 + 10 + m;
        }
    }

    operator int() const
    {
        return m;
    }
    operator std::string() const
    {
        return str;
    }

    int& operator[]( const int& index )
    {
        return arr[index];
    }
    const int& operator[]( const int& index ) const
    {
        return arr[index];
    }

    void operator()( const float& f ) const
    {
        std::cout << m << " " << f << " " << str << std::endl;
    }

    Money& operator++()
    {
        this->m += 1;
        return *this;
    }
    Money operator++( int )
    {
        Money tmp( *this );
        this->m += 1;
        return tmp;
    }
};

int main()
{
    Money m( 23, "This is a string\n" );

    int a = static_cast< int >( m );
    std::cout << "a = " << a << std::endl;

    std::string s = static_cast< std::string >( m );
    std::cout << "s = " << s << std::endl;
    m[0] = 9;
    m[4] = 12;
    for ( int i = 0; i < 10; ++i )
    {
        std::cout << m[i] << " ";
    }
    std::cout << std::endl;

    const Money m1( 90, "This is a\n" );
    for ( int i = 0; i < 10; ++i )
    {
        std::cout << m1[i] << " ";
    }
    std::cout << std::endl;

    m( 23.45f );
    m1( 44.6f );

    Money m3 = ++m;
    m3( 3.4f );
    Money m4 = m++;
    m4( 3.4f );
    m( 5.6f );

}
