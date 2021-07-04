#include <bits/stdc++.h>

using namespace std;

class Stack
{

public:

	bool empty() const { return element_with_cache_max_stack.empty();}
	int Max();
	int pop();
	void push(int x);

	template<size_t N>
	void AddElements(array<int, N> input);

private:
	
	class ElementWithCachedMax {
	public:
		int element;
		int max;
	};

	stack<ElementWithCachedMax> element_with_cache_max_stack;
};

int Stack::Max() 
{
	if(empty())
		throw length_error("max() : empty stack");

	return element_with_cache_max_stack.top().max;
}

int Stack::pop()
{
	if(empty())
		throw length_error("max() : empty stack");

	int pop_element = element_with_cache_max_stack.top().element;
	element_with_cache_max_stack.pop();

	return pop_element; 		
}

void Stack::push(int x)
{
	element_with_cache_max_stack.emplace( 
		ElementWithCachedMax{x, max(x, empty() ? x : Max())});
}

template <size_t N>
void Stack::AddElements(array<int, N> input)
{
	for(auto i: input)
		push(i);
}