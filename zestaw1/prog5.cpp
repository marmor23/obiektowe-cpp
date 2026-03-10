#include <iostream>
#include <vector>

template<typename t>
class Stack
{
	std::vector<t> vec;
	public:
		typedef t value_type;
		void push(t x)
		{
			vec.push_back(x);
		}
		t pop()
		{
			t res;
			res = vec[vec.size() - 1];
			vec.pop_back();
			return res;
		}
		bool is_empty()
		{
			return vec.empty();
		}
};

template<typename s>
typename s::value_type suma(s arg)
{
	typename s::value_type res;
	res = 0.0;
	while (!arg.is_empty())
	{
		res += arg.pop();
	}
	return res;
}

int main()
{
	Stack<int> st;
	Stack<double> st2;
	st.push(9);
	st.push(-1);
	st.push(8);
	st.push(55);
	st.push(13);
	st2.push(7.32);
	st2.push(81.93);
	st2.push(17.472);
	st2.push(-11.2228);
	st2.push(-19.995);
	std::cout << suma(st) << std::endl;
	std::cout << suma(st2) << std::endl;
	return 0;
}