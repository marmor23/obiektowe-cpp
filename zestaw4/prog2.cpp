#include <iostream>
#include <cstring>

template<typename t>
struct sum_traits;

template<>
struct sum_traits<char>
{
	typedef int sum_type;
	static sum_type getinit()
	{
		return 0;
	}
};

template<>
struct sum_traits<int>
{
	typedef long int sum_type;
	static sum_type getinit()
	{
		return 0;
	}
};

template<>
struct sum_traits<float>
{
	typedef double sum_type;
	static sum_type getinit()
	{
		return 0.0;
	}
};

template<>
struct sum_traits<double>
{
	typedef double sum_type;
	static sum_type getinit()
	{
		return 0.0;
	}
};

template<typename t> 
typename sum_traits<t>::sum_type sum(t *beg, t *end)
{ 
	typedef typename sum_traits<t>::sum_type sum_type;
	sum_type total = sum_traits<t>::getinit();
	while (beg != end)
	{ 
		total += *beg;
		beg++; 
	} 
	return total; 
}

int main()
{
	char * msg;
	int tab[5];
	float tab2[5];
	double tab3[5];
	msg = "test";
	tab[0] = 689;
	tab[1] = 45;
	tab[2] = -37;
	tab[3] = 289;
	tab[4] = 733;
	tab2[0] = 1.34;
	tab2[1] = 6.87;
	tab2[2] = -5.112;
	tab2[3] = 17.322;
	tab2[4] = 20.0005;
	tab3[0] = 99.45678;
	tab3[1] = 31.888;
	tab3[2] = 567.1098;
	tab3[3] = -1.99999;
	tab3[4] = 14.782;
	std::cout << sum(msg, msg + strlen(msg)) << std::endl;
	std::cout << sum(tab, tab + sizeof(tab) / sizeof(int)) << std::endl;
	std::cout << sum(tab2, tab2 + sizeof(tab2) / sizeof(float)) << std::endl;
	std::cout << sum(tab3, tab3 + sizeof(tab3) / sizeof(double)) << std::endl;
	return 0;
}