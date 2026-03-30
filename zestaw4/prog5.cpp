#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
#include <iterator>

template <typename Iter>
int operacja_impl(Iter beg, Iter end, std::forward_iterator_tag x)
{
    std::cout << "Iterator jednokierunkowy:" << std::endl;
	for (; beg != end; beg++)
		std::cout << *beg << " ";
	std::cout << std::endl;
    return 1;
}

template <typename Iter>
int operacja_impl(Iter beg, Iter end, std::bidirectional_iterator_tag x)
{
    std::cout << "Iterator dwukierunkowy:" << std::endl;
	for (; beg != end; end--)
		std::cout << *end << " ";
	std::cout << std::endl;
    return 2;
}

template <typename Iter>
int operacja_impl(Iter beg, Iter end, std::random_access_iterator_tag x)
{
	std::cout << "Iterator o swobodnym dostepie:" << std::endl;
	srand(time(NULL));
	while (beg < end)
	{
		std::cout << *beg << " ";
		beg += rand() % 2 + 1;
	}
    return 3;
}

template <typename Iter>
int operacja(Iter beg, Iter end)
{
    return operacja_impl(beg, end, typename std::iterator_traits<Iter>::iterator_category());
}

int main()
{
    std::vector<int> v;
	std::list<int> l;
	std::unordered_set<std::string> s;
	int i;
	for (i = 0; i < 20; i++)
		l.push_back(i);
	for (i = 0; i < 20; i++)
		v.push_back(i * 3 + 5);
	s.insert("poniedzialek");
	s.insert("wtorek");
	s.insert("sroda");
	s.insert("czwartek");
	s.insert("piatek");
	s.insert("sobota");
	s.insert("niedziela");
	operacja(s.begin(), s.end());
	std::cout << std::endl;
	operacja(l.begin(), l.end());
	std::cout << std::endl;
	operacja(v.begin(), v.end());
    return 0;
}