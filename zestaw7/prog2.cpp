#include <iostream>

template<int x, int y>
struct pow
{
	enum { val = x * pow<x, y - 1>::val };
};

template<int x>
struct pow<x, 0>
{
	enum { val = 1 };
};


int main()
{
	std::cout << pow<3, 5>::val << std::endl;
	std::cout << pow<8, 6>::val << std::endl;
	return 0;
}