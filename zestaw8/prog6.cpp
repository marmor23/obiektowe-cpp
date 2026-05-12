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
  double operator()(double x, double y)
  {
    return lhs(x, y) + rhs(x, y);
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

class First
{
	public:
    double operator()(double x)
	{
        return x;
    }
    double operator()(double x, double y)
	{
        return x;
    }
};

class Second
{
	public:
    double operator()(double x, double y)
	{
        return y;
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

template<typename func>
double integrate(func f, double min, double max, double miny, double maxy, double ds)
{
	double res;
	double x, y;
	res = 0.0;
	for (x = min; x < max; x += ds)
		for (y = miny; y < maxy; y += ds)
			res += f(x, y);
	return res * ds * ds;
}

int main()
{
	First x;
	Second y;
	std::cout << integrate(x + y, 0.0, 1.0, 0.0, 1.0, 0.0001) << std::endl;
	return 0;
}