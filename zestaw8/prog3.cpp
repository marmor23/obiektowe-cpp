#include <iostream>

template <typename t>
class variable
{
	public:
		t operator()(t x)
		{
			return x;
		}
};

class constant
{
	double c;
	public:
		constant() {}
		constant(double x)
		{
			c = x;
		}
		void operator=(double x)
		{
			c = x;
		}
		double operator()(double x)
		{
			return c;
		}
};

template<typename LHS, typename RHS>
class AddExpr
{
  LHS lhs;
  RHS rhs;
	public:
	AddExpr(LHS &l, RHS &r)
	{
		lhs=l;
		rhs=r;
	}
  double operator()(double x)
  {
    return lhs(x) + rhs(x);
  }
}; 

template<typename LHS, typename RHS> 
AddExpr<LHS,RHS> operator+(LHS &l, RHS &r)
{
  return AddExpr<LHS, RHS>(l, r);
}

template<typename LHS> 
AddExpr<LHS, constant> operator+(LHS &l, double r)
{
  return AddExpr<LHS, constant>(l, constant(r));
}

template<typename RHS> 
AddExpr<constant, RHS> operator+(double l, RHS &r)
{
  return AddExpr<constant, RHS>(constant(l), r);
}

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
	constant c;
	c = 1.0;
	std::cout << integrate(x + c, 0.0, 1.0, 0.0001) << std::endl;
	return 0;
}