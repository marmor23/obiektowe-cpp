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

template<typename t, typename v = variable<t>>
class expr
{
    v val;
	public:
		expr() {}
		expr(v x)
		{
			val = x;
		}
		t operator()(t x)
		{
			return val(x);
		}
		v get()
		{
			return val;
		}
};

template<typename t, typename v = variable<t>>
class thirdroot : public expr<t, v>
{
	public:
		t operator()(t x)
		{
			return x * x * x;
		}
};

template<typename t, typename LHS, typename RHS>
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
  t operator()(t x)
  {
    return lhs(x) + rhs(x);
  }
}; 

template<typename t, typename LHS, typename RHS> 
AddExpr<t, LHS, RHS> operator+(LHS &l, RHS &r)
{
  return AddExpr<t, LHS, RHS>(l, r);
} 

template<typename t, typename LHS> 
AddExpr<t, LHS, constant> operator+(LHS &l, t r)
{
  return AddExpr<t, LHS, constant>(l, constant(r));
} 

template<typename t, typename RHS> 
AddExpr<t, constant, RHS> operator+(t l, RHS &r)
{
  return AddExpr<t, constant, RHS>(constant(l), r);
}

template<typename t,typename LHS, typename RHS>
expr<t, AddExpr<t, LHS, RHS>> operator+(expr<t, LHS> &l, expr<t, RHS> &r)
{
    return expr<t, AddExpr<t, LHS, RHS>>(AddExpr<t, LHS, RHS>(l.get(), r.get()));
}

template<typename t, typename LHS>
expr<t, AddExpr<t, LHS, constant>> operator+(expr<t, LHS> &l, t r)
{
    return expr<t, AddExpr<t, LHS, constant>>(AddExpr<t, LHS, constant>(l.get(), constant(r)));
}

template<typename t, typename LHS>
expr<t, AddExpr<t, constant, LHS>> operator+(t r, expr<t, LHS> &l)
{
    return expr<t, AddExpr<t, constant, LHS>>(AddExpr<t, constant, LHS>(constant(r), l.get()));
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
	thirdroot<int> x;
	std::cout << integrate(x, 0, 5, 1) << std::endl;
	return 0;
}