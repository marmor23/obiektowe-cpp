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

template<typename T, size_t N = 100>
struct statalloc
{
	typedef T elemtype[N];
	elemtype buf;
	void init(size_t s) {}
	void expand(size_t s) {}
	void shrink(size_t s) {}
	void deallocate() {}
	size_t size() { return N; }
};

template<typename T, size_t N >
struct dynalloc
{
	typedef T * elemtype;
	elemtype buf;
	size_t siz;
	void init(size_t n)
	{
		siz = n;
		buf = new T[siz];
	}
	void expand(size_t s) {}
	void shrink(size_t s) {}
	
	void deallocate()
	{
		delete[] buf;
	}
	
	size_t size() { return siz; }
	
	public:
		void resize(size_t n)
		{
			T *tmp;
			tmp = new T[n];
			std::copy(buf, buf + std::min(siz, n), tmp);
			delete[] buf;
			buf = tmp;
			siz = n;
		}
};

template<typename T, size_t N>
struct expalloc
{
	typedef T * elemtype;
	elemtype buf;
	size_t siz;
	void init(size_t n)
	{
		siz = n;
		buf = new T[siz];
	}
	
	void expand(size_t top)
	{
		if (top == siz)
		{
			T *tmp;
			siz = siz * 2;
			tmp = new T[siz];
			std::copy(buf, buf + top, tmp);
			delete[] buf;
			buf = tmp;
		}
	}
	
	void shrink(size_t top)
	{
		if (top > 2 * siz)
		{
			T *tmp;
			tmp = new T[siz];
			std::copy(buf, buf + top, tmp);
			delete[] buf;
			buf = tmp;
		}
	}
	
	void deallocate()
	{
		delete[] buf;
	}

	size_t size() { return siz; }
};

template<typename T = int, size_t N = 100, typename checkpol = polnocheck, template<typename U, size_t M> class allocpol = statalloc>  
class Stack : private checkpol, private allocpol<T, N>
{
	typedef typename allocpol<T, N>::elemtype elemtype;
	elemtype buf;
	size_t tp;
public:
	Stack(size_t n = N)
	{
		tp = 0;
		this->init(n);
	}
	
	~Stack()
	{
		this->deallocate();
	}
	
	void push(T val)
	{
		this->expand(tp);
		checkpol::check_push(tp, this->size());
		buf[tp++] = val;
	}

	void pop()
	{
		checkpol::check_pop(tp);
		--tp;
		this->shrink(tp);
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
	Stack<int, 100, exconerr, dynalloc> s2;
	Stack<int, 5, exconerr, expalloc> s3;
	int i;
	s.push(20);
	s.push(33);
	s2.push(7);
	s2.push(11);
	s2.push(13);
	s2.push(17);
	s3.push(79);
	s3.push(331);
	s3.push(1717);
	s3.push(888);
	s3.push(976);
	s3.push(223);
	std::cout << s.top() << std::endl;
	std::cout << std::endl;
	for (i = 0; i < 5; i++)
	{
		try
		{
			std::cout << s2.top() << std::endl;
			s2.pop();
		}
		catch (std::range_error e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	for (i = 0; i < 6; i++)
	{
		std::cout << s3.top() << std::endl;
		s3.pop();
	}
	return 0;
}