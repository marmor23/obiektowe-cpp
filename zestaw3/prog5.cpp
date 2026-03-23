#include <iostream>
#include <set>

template<typename t>
void browseset(std::set<t, std::greater<>> s)
{
	std::cout << "std::set{";
	for (auto it = s.begin(); it != s.end(); it++)
		std::cout << *it << (it == --s.end() ? "}" : ", ");
	std::cout << std::endl;
}

int main()
{
	std::set<int, std::greater<>> s;
	srand(time(NULL));
	while (s.size() < 6)
		s.insert(rand() % 49 + 1);
	browseset(s);
	return 0;
}