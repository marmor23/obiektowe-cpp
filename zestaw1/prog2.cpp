#include <iostream>

template<typename y, typename x>
y convert(x arg)
{
	return static_cast<y>(arg);
}

int main()
{
	std::cout << convert<float>(97) << std::endl;
	std::cout << convert<double>(77789) << std::endl;
	std::cout << convert<std::string>("test") << std::endl;
	return 0;
}