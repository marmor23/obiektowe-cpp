#include <iostream>

template<size_t v, typename t>
struct inner
{
	t dot(t *x, t *y)
	{
		return x[v - 1] * y[v - 1] + inner<v - 1, t>().dot(x, y);
	}
};

template<typename t>
struct inner<1, t>
{
	t dot(t *x, t *y)
	{
		return x[0] * y[0];
	}
};

int main()
{
	double x[5];
	double y[5];
	int v1[3];
	int v2[3];
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
	v1[0] = 45;
	v1[1] = 6;
	v1[2] = 93;
	v2[0] = 35;
	v2[1] = -55;
	v2[2] = 23;
	std::cout << inner<5, double>().dot(x, y) << std::endl;
	std::cout << inner<3, int>().dot(v1, v2) << std::endl;
	return 0;
}