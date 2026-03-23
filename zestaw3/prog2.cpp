#include <iostream>

template<typename y, typename x>
y convert(x arg)
{
	return static_cast<y>(arg);
}

template<>
std::string convert(int x)
{
	return std::to_string(x);
}

int main()
{
	std::cout << convert<float>(97) << std::endl;
	std::cout << convert<double>(77789) << std::endl;
	std::cout << convert<std::string>(456) << std::endl;
	return 0;
}