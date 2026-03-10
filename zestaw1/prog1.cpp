#include <iostream>

template<typename t>
t maksimum(t a, t b)
{
	return a < b ? b : a;
}

int main()
{
	std::cout << maksimum(23, 45) << std::endl;
	std::cout << maksimum(17.89, 16.9999) << std::endl;
	std::cout << maksimum("Ania", "Basia") << std::endl;
	std::cout << maksimum(std::string("Ania"), std::string("Basia")) << std::endl;
	return 0;
}