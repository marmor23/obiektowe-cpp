#include <iostream>
#include <vector>

template<typename t>
class has_value_type
{
	template<typename x> static short test(typename x::value_type); 
	template<typename x> static unsigned long long test(...);
	
	public:
		enum
		{
			yes = sizeof(test<t>(0)) == sizeof(short)
		};
};

int main()
{
	std::cout << has_value_type<int>::yes << std::endl;
	std::cout << has_value_type<std::vector<int>>::yes << std::endl;
	std::cout << has_value_type<std::vector<double>>::yes << std::endl;
	return 0;
}