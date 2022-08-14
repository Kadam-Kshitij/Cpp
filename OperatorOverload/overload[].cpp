#include <iostream>
#include <vector>
#include <algorithm>

int global = 11;

class Base
{
    std::vector< int > vect;
public:
    Base()
    {
        for( int i = 1; i < 10; ++i )
        {
            vect.push_back( global );
            ++global;
        }
    }

    void print() const
    {
        for_each( vect.begin(), vect.end(), []( int x ){ std::cout << x << " "; } );
        std::cout << std::endl;
    }

    int& operator[]( const int& i )
    {
        return vect[i-1];
    }

    const int& operator[]( const int& i ) const
    {
        return vect[i-1];
    }
};

int main()
{
    Base b;
    std::cout << b[3] << std::endl;
    b[5] = 99;
    b[4] = 78;
    b.print();

    const Base c;
    std::cout << c[3] << std::endl;
    c.print();

}
