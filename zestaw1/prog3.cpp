#include <iostream>
#include <vector>

template<unsigned long long N, typename t>
t dot_product(t *a, t *b)
{
	t res;
	unsigned long long i;
	res = 0.0;
	for (i = 0; i < N; i++)
		res += a[i] * b[i];
	return res;
}

template<unsigned long long N, typename t>
t dot_product(std::vector<t> a, std::vector<t> b)
{
	t res;
	unsigned long long i;
	res = 0.0;
	for (i = 0; i < N; i++)
		res += a[i] * b[i];
	return res;
}

int main()
{
	std::vector<double> x;
	std::vector<double> y;
	int a[3];
	int b[3];
	x.assign({3.45, 1.11, 7.89, -1.557, -9.30323});
	y.assign({0.01, 3.31, 23.64, -12.54, 10.002});
	a[0] = 8;
	a[1] = 9;
	a[2] = -1;
	b[0] = 7;
	b[1] = 3;
	b[2] = 5;
	std::cout << dot_product<5>(x, y) << std::endl;
	std::cout << dot_product<3>(a, b) << std::endl;
	return 0;
}