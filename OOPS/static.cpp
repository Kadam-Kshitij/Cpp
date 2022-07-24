// == Output ==
// 23
// 34
// 19

#include <iostream>

class Base
{
public:
	static const int x = 23;
	static constexpr int y = 34;
	static inline int z = 19;	// Available with c++17 and above
};

int main()
{
	Base b;
	std::cout << Base::x << std::endl;
	std::cout << Base::y << std::endl;
	std::cout << Base::z << std::endl;
}
