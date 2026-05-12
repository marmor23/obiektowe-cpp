#include <iostream>
#include <math.h>

template <typename t>
class variable
{
	public:
		t operator()(t x)
		{
			return x;
		}
};

template <typename t>
class constant
{
	double c;
	public:
		constant(t x)
		{
			c = x;
		}
		t operator()(t x)
		{
			return c;
		}
};

template<typename func>
double integrate(func f, double min, double max, double ds)
{
	double res;
	double x;
	res = 0.0;
	for (x = min; x < max; x += ds)
		res += f(x);
	return res * ds;
}

int main()
{
	variable<double> x;
	std::cout << integrate(x, 0.0, 1.0, 0.001) << std::endl;
	std::cout << integrate(constant(1.0), 0.0, 1.0, 0.001) << std::endl;
	return 0;
}