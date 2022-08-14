#include <iostream>

void goo( int* ptr )
{
    std::cout << *ptr << std::endl;
}
void hoo( int& ref )
{
    std::cout << ref << std::endl;
}

class Base
{
public:
    virtual void foo()
    {
        std::cout << "Base\n";
    }
};

class Derived1 : public Base
{
public:
    void foo() override
    {
        std::cout << "Derived1\n";
    }
};

class Derived2 : public Base
{
public:
    void foo() override
    {
        std::cout << "Derived2\n";
    }
};

int main()
{
    int i = 100;
    char ch = static_cast< char >( i );
    std::cout << ch << std::endl;

    Derived1* d1 = new Derived1();
    Base* b = dynamic_cast< Base* >( d1 );
    Derived2* d2 = dynamic_cast< Derived2* >( b );
    Derived1* d3 = dynamic_cast< Derived1* >( b );

    if ( d2 == NULL )
    {
        std::cout << "d2 is null\n";
    }
    if ( d3 == NULL )
    {
        std::cout << "d3 is null\n";
    }
    else
    {
        d3->foo();
    }

    try
    {
        Derived1 d4;
        Base& b2 = dynamic_cast< Base& >( d4 );
        Derived1& d6 = dynamic_cast< Derived1& >( b2 );
        Derived2& d5 = dynamic_cast< Derived2& >( b2 );
    }
    catch( ... )
    {
        std::cout << "Catch\n";
    }

    int a = 18;
    const int* ptr = &a;
    // goo( ptr );
    goo( const_cast< int* >( ptr ) );

    const int& ref = a;
    // hoo( ref );
    hoo( const_cast< int& >( ref ) );
}
