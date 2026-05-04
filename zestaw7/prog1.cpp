#include <iostream>

template<int x>
unsigned long long silnia()
{
  return x * silnia<x - 1>();
}

template<>
unsigned long long silnia<1>()
{
	return 1;
}

template<>
unsigned long long silnia<0>()
{
	return 1;
}

int main()
{
	std::cout << silnia<5>() << std::endl;
	std::cout << silnia<7>() << std::endl;
	return 0;
}