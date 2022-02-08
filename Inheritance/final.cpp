#include <iostream>

class Base
{
};

class Derived1 final : public Base
{
};

// CTE
//class Derived2 : public Derived1
//{
//};

int main()
{
	Base b;
	Derived1 d1;
}
