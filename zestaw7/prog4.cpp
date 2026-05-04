#include <iostream>
#include <math.h>

template<int x>
inline double silnia()
{
  return x * silnia<x - 1>();
}

template<>
inline double silnia<1>()
{
	return 1;
}

template<>
inline double silnia<0>()
{
	return 1;
}

template<int y>
inline double pow(double x)
{
	return x * pow<y - 1>(x);
}

template<>
inline double pow<0>(double x)
{
	return 1.0;
}

template<int v>
inline double sin(double x)
{
	return sin<v - 1>(x) + (v & 1 ? 1.0 : -1.0) * pow<2 * v - 1>(x) / silnia<2 * v - 1>();
}

template<>
inline double sin<0>(double x)
{
	return 0.0;
}

int main()
{
	std::cout << sin<3>(3 * M_PI / 4) << std::endl;
	std::cout << sin<6>(M_PI / 2) << std::endl;
	std::cout << sin<9>(M_PI / 4) << std::endl;
	return 0;
}