#include <iostream>
#include <vector>

#define MK_PROMOTE(t1,t2,tr)             \
    template<> class Promote<t1, t2> {   \
      public:                              \
        typedef tr restype;                \
    };                                     \
                                           \
    template<> class Promote<t2, t1> {   \
      public:                              \
        typedef tr restype;                \
    };

template<bool flag, typename t1, typename t2>
struct choosetyp
{
	typedef t1 restype; 
};

template<typename t1, typename t2> 
struct choosetyp<false, t1, t2>
{
	typedef t2 restype; 
};

template<typename t1, typename t2>
struct Promote
{
	typedef typename choosetyp<(sizeof(t1) > sizeof(t2)), t1, typename choosetyp<(sizeof(t1) < sizeof(t2)), t2, void>::restype >::restype restype;
};

template<typename t>
struct Promote<t, t>
{
	typedef t restype;
};

MK_PROMOTE(int, double, double)
MK_PROMOTE(int, float, float)
MK_PROMOTE(int, long long, long long)

template<typename t>
std::vector<t> operator+(const std::vector<t> &a, const std::vector<t> &b)
{
	std::vector<t> res;
	int i;
	for (i = 0; i < std::min(a.size(), b.size()); i++)
		res.push_back(a[i] + b[i]);
	return res;
}

template<typename t,typename x> 
std::vector<typename Promote<t, x>::restype> operator+(const std::vector<t> &a, const std::vector<x> &b)
{
	std::vector<typename Promote<t, x>::restype> res;
	int i;
	for (i = 0; i < std::min(a.size(), b.size()); i++)
		res.push_back(a[i] + b[i]);
	return res;
}

template<typename t>
void dispvector(std::vector<t> vec)
{
	int i;
	std::cout << "[";
	for (i = 0; i < vec.size() - 1; i++)
		std::cout << vec[i] << ", ";
	std::cout << vec[i] << "]";
}

int main()
{
	std::vector<int> v1;
	std::vector<float> v2;
	std::vector<float> res;
	v1.assign({4, 6, 7});
	v2.assign({7.8, 9.92, 4.5});
	res = v1 + v2;
	dispvector(res);
	return 0;
}