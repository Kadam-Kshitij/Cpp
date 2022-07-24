// == Output ==
// Non - Const
// Const
// 23

// =====================================================
#include <iostream>

class Base
{
	int a;
public:
	Base() : a{ 23 }
	{
	}

	void foo() const
	{
		std::cout << "Const\n";
	}

	void foo()
	{
		std::cout << "Non - Const\n";
	}

	// CTE
	// int& goo() const
	const int& goo() const
	{
		return a;
	}
};

// =====================================================
int main()
{
	Base b;
	const Base b1;

	b.foo();
	b1.foo();

	// CTE
	// int& z = b.goo();
	const int& z = b.goo();
	std::cout << z << std::endl;
}
