#include <iostream>

template<typename t, typename x>
class Is_convertible
{
	static short test(x) ;
	static unsigned long long test(...);
	static t maket();
	
	public:
		enum
		{
			yes = sizeof(test(maket())) == sizeof(short),
			same_type = false
		};
};

template<typename t>
class Is_convertible<t, t>
{
	public:
		enum
		{
			yes = true,
			same_type = true
		}; 
};

int main()
{
	std::cout << Is_convertible<int, double>::yes << std::endl;
	std::cout << Is_convertible<int, double>::same_type << std::endl;
	std::cout << Is_convertible<float, double>::yes << std::endl;
	std::cout << Is_convertible<float, double>::same_type << std::endl;
	std::cout << Is_convertible<int *, unsigned int *>::yes << std::endl;
	std::cout << Is_convertible<int *, unsigned int *>::same_type << std::endl;
	return 0;
}