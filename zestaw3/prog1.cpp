#include <iostream>
#include <cstring>

template<typename t>
t max(t a, t b)
{
	return a > b ? a : b;
}

template<typename t>
t * max(t *a, t *b)
{
	return *a > *b ? a : b;
}

template<typename t>
t max(t *data, size_t n)
{
	t res;
	size_t i;
	res = data[0];
	for (i = 1; i < n; i++)
		if (data[i] > res)
			res = data[i];
	return res;
}

template<>
char * max(char *a, char *b)
{
	return strcmp(a, b) > 0 ? a : b;
}

template<>
const char * max(const char *a, const char *b)
{
	return strcmp(a, b) > 0 ? a : b;
}

const char * max(char *a, const char *b)
{
	return strcmp(a, b) > 0 ? a : b;
}

int main()
{
	double liczby[5];
	char *x;
	char *y;
	int a, b;
	a = 67;
	b = 89;
	liczby[0] = 1.0;
	liczby[1] = -2.56;
	liczby[2] = 3.1415;
	liczby[3] = 2.1718;
	liczby[4] = 2.2567;
	x = "Ania";
	y = "Basia";
	std::cout << max(23, 45) << std::endl;
	std::cout << *max(&a, &b) << std::endl;
	std::cout << max(liczby, 5) << std::endl;
	std::cout << max(x, y) << std::endl;
	std::cout << max("Celina", "Daria") << std::endl;
	std::cout << max(x, "Daria") << std::endl;
	return 0;
}