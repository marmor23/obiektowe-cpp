#include <iostream>

template<size_t v>
inline double inner(double *x, double *y)
{
	return x[v - 1] * y[v - 1] + inner<v - 1>(x, y);
}

template<>
inline double inner<1>(double *x, double *y)
{
	return x[0] * y[0];
}

int main()
{
	double x[5];
	double y[5];
	x[0] = 9.0;
	x[1] = 4.56;
	x[2] = 8.332;
	x[3] = 7.335;
	x[4] = -1.468;
	y[0] = -2.31;
	y[1] = 5.67;
	y[2] = 6.66;
	y[3] = -9.31;
	y[4] = -4.55;
	std::cout << inner<5>(x, y) << std::endl;
	return 0;
}