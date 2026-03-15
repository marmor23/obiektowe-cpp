#include <iostream>
#include <vector>

template<typename t, typename i>
t accumulate(i begin, i end)
{
	t res;
	res = 0;
	while (begin != end)
	{
		res += *begin;
		begin++;
	}
	return res;
}

int main()
{
	std::vector<int> vec;
	vec.assign({2, 3, 4, 5, 2, 1});
	std::cout << accumulate<int>(vec.begin(), vec.end()) << std::endl;
	return 0;
}