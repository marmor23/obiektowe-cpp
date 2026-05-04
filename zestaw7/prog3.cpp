#include <iostream>
#include <iomanip>

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

int main()
{
	std::cout << std::setprecision(13);
	std::cout << pow<5>(3) << std::endl;
	std::cout << pow<8>(13) << std::endl;
	std::cout << pow<7>(7) << std::endl;
	return 0;
}