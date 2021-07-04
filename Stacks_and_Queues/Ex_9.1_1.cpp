#include <bits/stdc++.h>

using namespace std;

class MaxCacheWithCount
{
public:

    int max_element;
    int count;
};

class Stack
{
public:

    bool Empty() {return elementStack.empty();}
    int Max();    
    void Push(int x);
    int Pop();

    template<size_t N>
    void AddElements(array<int, N> input);

private:

    stack<int> elementStack;
    stack<MaxCacheWithCount> max_elements_count;

};

int main(int argc, char* argv[])
{
    array<int, 9> arr1 = {1,2,3,4,5,6,7,9,9};

    Stack Obj1;
    Obj1.AddElements(arr1);
    cout<< Obj1.Pop() <<endl;
    cout<< Obj1.Max() <<endl;

    return 0;
}



int Stack::Max()
{
    if(Empty())
        throw length_error("Max() : Stack is empty\n");
    
    return max_elements_count.top().max_element;
}

void Stack::Push(int x)
{
    elementStack.emplace(x);

    if(max_elements_count.empty())
    {
        max_elements_count.emplace(MaxCacheWithCount{x,1});
    }
    else 
    {
        const int current_max = max_elements_count.top().max_element;

        if(x == current_max)
        {
            int& max_frequency = max_elements_count.top().count;
            max_frequency++;
        }
        else if(x > current_max)
        {
            max_elements_count.emplace(MaxCacheWithCount{x,1});
        }
             
    }
}

int Stack::Pop()
{
    if(Empty())
        throw length_error("Max() : Stack is empty\n");

    int pop_element = elementStack.top();
    elementStack.pop();
    MaxCacheWithCount& Obj1 = max_elements_count.top();

    if(Obj1.max_element == pop_element)
    {
        if(Obj1.count == 1)
        {
            max_elements_count.pop();
        }
        else
            Obj1.count--;
    }
    return pop_element;   
}

template <size_t N>
void Stack::AddElements(array<int, N> input)
{
    for(auto i: input)
        Push(i);
}