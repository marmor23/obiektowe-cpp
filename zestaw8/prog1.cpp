#include <iostream>
#include <math.h>

class sina
{
	double a;
	public:
		sina(double x)
		{
			a = x;
		}
		double operator()(double x)
		{
			return sin(a * x);
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
	std::cout << integrate(sina(0), 0, M_PI, 0.01) << std::endl;
	std::cout << integrate(sina(1), 0, M_PI, 0.01) << std::endl;
	std::cout << integrate(sina(2), 0, M_PI, 0.01) << std::endl;
	return 0;
}