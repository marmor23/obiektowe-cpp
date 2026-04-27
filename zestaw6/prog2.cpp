#include <exception>
#include <iostream>

struct polnocheck
{
  static void check_push(size_t tp, size_t mx) {}
  static void check_pop(size_t tp) {}
  static void check_top(size_t tp) {}
};

struct abortonerr
{
	static void check_push(size_t top, size_t size)
	{
		if(top >= size)
		{
			std::cerr << "Proba wrzucenia elementu na pelny stos: przerywam" << std::endl;
			abort();
		}
	}
  
	static void check_pop(size_t top)
	{
		if (top == 0)
		{
			std::cerr << "Proba zabrania elementu z pustego stosu: przerywam" << std::endl;
			abort();
		}
	}
	
	static void check_top(size_t top)
	{
		if (top == 0)
		{
			std::cerr << "Proba czytania elementu z pustego stosu: przerywam" << std::endl;
			abort();
		}
	}
};

struct exconerr
{
	static void check_push(size_t top, size_t size)
	{
		if (top >= size)
			throw std::range_error("Stos jest pelny!");
	}
	
	static void check_pop(size_t top)
	{
		if(top == 0)
			throw std::range_error("Stos jest pusty!");
	}
	
	static void check_top(size_t top)
	{
		if (top == 0)
			throw std::range_error("Stos jest pusty!");
	}
};

template<typename T = int, size_t N = 100, typename checkpol = polnocheck>  
class Stack
{
	T buf[N];
	size_t tp;
public:
	Stack(size_t n = N) : tp(0) {}
	void push(T val)
	{
		checkpol::check_push(tp, N);
		buf[tp++] = val;
	}

	void pop()
	{
		checkpol::check_pop(tp);
		--tp;
	}
  
	T top()
	{
		checkpol::check_top(tp);
		return buf[tp - 1];
	}

	bool is_empty()
	{
		return tp == 0;
	}
};

int main()
{
	Stack s;
	Stack<int, 100, abortonerr> s2;
	Stack<int, 100, exconerr> s3;
	int i;
	s.push(4);
	s.push(5);
	for (i = 0; i < 3; i++)
		s.pop();
	s3.push(11);
	s3.push(22);
	for (i = 0; i < 3; i++)
	{
		try
		{
			s3.pop();
		}
		catch (std::range_error e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	s2.push(77);
	s2.push(88);
	for (i = 0; i < 2; i++)
		s2.pop();
	s2.top();
	return 0;
}