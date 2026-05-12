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
	AddExpr() {}
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

template<typename LHS, typename RHS>
class DivExpr
{
  LHS lhs;
  RHS rhs;
	public:
	DivExpr() {}
	DivExpr(LHS &l, RHS &r)
	{
		lhs=l;
		rhs=r;
	}
  double operator()(double x)
  {
    return lhs(x) / rhs(x);
  }
}; 

template<typename LHS, typename RHS> 
DivExpr<LHS,RHS> operator/(LHS l, RHS r)
{
  return DivExpr<LHS, RHS>(l, r);
}

template<typename LHS> 
DivExpr<LHS, constant> operator/(LHS &l, double r)
{
  return DivExpr<LHS, constant>(l, constant(r));
}

template<typename RHS> 
DivExpr<constant, RHS> operator/(double l, RHS &r)
{
  return DivExpr<constant, RHS>(constant(l), r);
}

template<typename func>
class SinExpr
{
	func f;
	public:
		SinExpr() {}
		SinExpr(func x)
		{
			f = x;
		}
		double operator()(double x)
		{
			return sin(f(x));
		}
};

template<typename func>
SinExpr<func> sin(func f)
{
	return SinExpr<func>(f);
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
	std::cout << integrate(c / sin(x + c), 0.0, 1.0, 0.0001) << std::endl;
	return 0;
}