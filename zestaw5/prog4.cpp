#include <iostream>

template<typename T>
struct Strip
{
	typedef T base;
};

template<typename T>
struct Strip<T const>
{
	typedef typename Strip<T>::base base;
};

template<typename T>
struct Strip<T&>
{
	typedef typename Strip<T>::base base;
};

int main()
{
	std::cout << std::is_same<Strip<const int>::base, int>::value << std::endl;
	std::cout << std::is_same<Strip<int &>::base, int>::value << std::endl;
	std::cout << std::is_same<Strip<const int &>::base, int>::value << std::endl;
	return 0;
}