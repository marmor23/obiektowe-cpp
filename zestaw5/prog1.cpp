#include <iostream>
#include <vector>

template<typename t>
class is_class
{
	template<typename x> static short test(int x::*); 
	template<typename x> static unsigned long long test(...);
	
	public:
		bool check()
		{
			return sizeof(test<t>(0)) == sizeof(short);
		}
};

struct a {};

class b {};

int main()
{
	std::cout << is_class<int>().check() << std::endl;
	std::cout << is_class<a>().check() << std::endl;
	std::cout << is_class<b>().check() << std::endl;
	std::cout << is_class<std::vector<int>>().check() << std::endl;
	return 0;
}