#include <iostream>

#define tst TypeList<double, TypeList<int, TypeList<std::string, Null_type>>>

template<typename H, typename T>
struct TypeList
{
  typedef H Head;
  typedef T Tail;
};

class  Null_type {};
struct Empty_type {};

template<typename T>
struct size;

template<>
struct size<Null_type>
{
	enum {value = 0};
};

template<typename H, typename T>
struct size<TypeList<H, T>>
{
	enum {value = 1 + size<T>::value};
};

template<int N, typename T>
struct index
{
	typedef typename index<N - 1, typename T::Tail>::value value;
};

template<typename H, typename T>
struct index<1, TypeList<H, T>>
{
	typedef H value;
};

template<int N>
struct index<N, Null_type>
{
	typedef Empty_type value;
};

template<typename T, typename TL>
struct contains
{
	enum { value = contains<T, typename TL::Tail>::value };
};

template<typename T,typename Tail>
struct contains<T, TypeList<T, Tail>>
{
	enum {value = 1};
};

template<typename T>
struct contains<T, Null_type>
{
	enum {value = 0};
};

int main()
{
	std::cout << size<tst>::value << std::endl;
	std::cout << std::is_same<index<2, tst>::value, int>::value << std::endl;
	std::cout << contains<double, tst>::value << std::endl;
	std::cout << contains<unsigned int, tst>::value << std::endl;
	return 0;
}