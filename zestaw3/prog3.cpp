#include <iostream>

template<typename T, size_t N>
class Stack
{
	T buf[N];
	size_t s;
	public:
		Stack(): s(0) {};
		void push(T val)
		{
			buf[s++] = val;
		}
		T pop()
		{
			return buf[--s];
		}
		bool is_empty()
		{
			return s == 0;
		} 
};

template<typename T>
class Stack<T, 666>
{
	public:
		Stack()
		{
			std::cout << "Stack<T, 666>" << std::endl;
		}
};

template<typename T, size_t N>
class Stack<T*, N>
{
	public:
		Stack()
		{
			std::cout << "Stack<T*, N>" << std::endl;
		}
};

template<size_t N>
class Stack<double, N>
{
	public:
		Stack()
		{
			std::cout << "Stack<double, N>" << std::endl;
		}
};

template<size_t N>
class Stack<int*, N>
{
	public:
		Stack()
		{
			std::cout << "Stack<int*, N>" << std::endl;
		}
};

template<>
class Stack<double, 666>
{
	public:
		Stack()
		{
			std::cout << "Stack<double, 666>" << std::endl;
		}
};

template<>
class Stack<double*, 44>
{
	public:
		Stack()
		{
			std::cout << "Stack<double*, 44>" << std::endl;
		}
};

int main()
{
	Stack<int, 100> st;
	Stack<int, 666> st2;
	Stack<double *, 101> st3;
	Stack<double, 102> st4;
	Stack<int *, 103> st5;
	Stack<double, 666> st6;
	Stack<double *, 44> st7;
	st.push(99);
	st.push(98);
	st.push(97);
	std::cout << st.pop() << std::endl;
	return 0;
}