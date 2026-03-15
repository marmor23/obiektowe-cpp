#include <algorithm>
#include <iostream>

template<typename t>
class SequenceGen
{
	t start;
	t step;
	public:
		SequenceGen(t startx, t stepx) : start(startx), step(stepx) {}
		t operator()()
		{
			t res;
			res = start;
			start += step;
			return res;
		}
};

int main()
{
	std::vector<int> vec;
	int num;
	int i;
	num = 20;
	vec.resize(num);
	generate_n(vec.begin(), num, SequenceGen<int>(1, 2));
	std::cout << "Zawartosc wektora:" << std::endl;
	for (i = 0; i < vec.size(); i++)
		std::cout << vec[i] << (i < vec.size() - 1 ? " " : "\n\n");
	// auto it = find_if(vec.begin(), vec.end(), [](int x) {return x > 4;});
	auto it = find_if(vec.begin(), vec.end(), bind(std::greater<int>(), std::placeholders::_1, 4));
	std::cout << "Element wiekszy od 4 wynosi: " << *it << std::endl;
	return 0;
}