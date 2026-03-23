#include <iostream>
#include <vector>

template<typename T,int N = 100, typename R = T*> class Stack;

template<typename T,int N>
class Stack<T,N,T*>
{
	T buf[N];
	unsigned int s;
	public:
		Stack(): s(0) {};
		void push(T e)
		{
			buf[s++] = e;
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

template<typename T,int N,template<typename E> class Sequence >
class Stack<T,N,Sequence<T> >
{
	Sequence<T> buf;
	public:
		void push(T e)
		{
			buf.push_back(e);
		};
		T pop()
		{
			T top = buf.back();
			buf.pop_back();
			return top;
		}
		bool is_empty()
		{
			return buf.empty();
		}
};

int main()
{
	Stack<int, 100> st;
	Stack<int, 0, std::vector<int>> st2;
	st.push(99);
	st.push(98);
	st.push(97);
	st2.push(54);
	st2.push(55);
	st2.push(56);
	std::cout << st.pop() << std::endl;
	std::cout << st2.pop() << std::endl;
	return 0;
}