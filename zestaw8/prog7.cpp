#include <iostream>
#include <vector>

class Vector : public std::vector<double>
{
public:
	Vector() : std::vector<double>() {}
	Vector(int n) : std::vector<double>(n) {}
	Vector(int n, double x) : std::vector<double>(n, x) {}
	Vector(Vector &v) : std::vector<double>(static_cast<std::vector<double>>(v)) {}
	Vector(std::vector<double> &v) : std::vector<double>(v) {}

	Vector &operator=(Vector &rhs)
	{
		std::vector<double>::operator=(static_cast<std::vector<double>>(rhs));
		return *this;
	}
	
	template<typename v>
	Vector &operator=(v &rhs)
	{
		size_t i;
		for (i = 0; i < std::vector<double>::size(); i++)
			(*this)[i] = rhs[i];
		return *this;
	}
};

class CVector
{
	double c;
	public:
	CVector(double x)
	{
		c = x;
	}
	
	double operator[](int i)
	{
		return c;
	}
};

template<typename LHS, typename RHS>
class AddVectors
{
	LHS lhs;
	RHS rhs;
public:
	AddVectors(LHS &l, RHS &r)
	{
		lhs=l;
		rhs=r;
	}
	double operator[](int i)
	{
		return lhs[i] + rhs[i];
	}
};

template<typename LHS,typename RHS>
inline AddVectors<LHS, RHS> operator+(LHS &lhs, RHS &rhs)
{
	return AddVectors<LHS,RHS>(lhs,rhs);
}

template<typename LHS>
inline AddVectors<LHS, CVector> operator+(LHS &lhs, double rhs)
{
	return AddVectors<LHS, CVector>(lhs, CVector(rhs));
}

template<typename RHS>
inline AddVectors<CVector, RHS> operator+(double lhs, RHS &rhs)
{
	return AddVectors<CVector, RHS>(CVector(lhs), rhs);
}

template<typename LHS, typename RHS>
class MulVectors
{
	LHS lhs;
	RHS rhs;
public:
	MulVectors(LHS &l, RHS &r)
	{
		lhs=l;
		rhs=r;
	}
	double operator[](int i)
	{
		return lhs[i] * rhs[i];
	}
};

template<typename LHS,typename RHS>
inline MulVectors<LHS, RHS> operator*(LHS &lhs, RHS &rhs)
{
	return MulVectors<LHS,RHS>(lhs,rhs);
}

template<typename LHS>
inline MulVectors<LHS, CVector> operator*(LHS &lhs, double rhs)
{
	return MulVectors<LHS, CVector>(lhs, CVector(rhs));
}

template<typename RHS>
inline MulVectors<CVector, RHS> operator*(double lhs, RHS &rhs)
{
	return MulVectors<CVector, RHS>(CVector(lhs), rhs);
}

int main()
{
	Vector v1(100, 1);
	Vector v2(100, 2);
	Vector res(100);
	res = 1.2 * v1 + v1 * v2 + v2 * 0.5;
	return 0;
}