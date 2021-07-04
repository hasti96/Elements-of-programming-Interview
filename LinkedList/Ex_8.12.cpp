#include <bits/stdc++.h>
#include "LinkedList.hpp"

using namespace std;

class ListPivot
{
public:
	static Node* pivot(Node*& input, int k)
	{
		Node* less_head = new Node(); 
		Node* equal_head = new Node();
		Node* greater_head = new Node();

		Node* less_iter = less_head; 
		Node* equal_iter = equal_head;
		Node* greater_iter = greater_head;
		
		while(input)
		{
			append(input->value < k ? less_iter : input->value == k ? equal_iter : greater_iter, input);
			input = input->next;
		}

		less_iter->next = equal_head->next;
		equal_iter->next = greater_head->next;
		greater_iter->next = nullptr;

		return less_head->next;
	}

	static void append(Node*& append, Node*& node)
	{
		append->next = node;
		append = append->next;
	}
};

int main(int argc, char const *argv[])
{
	
	array<int, 9> arr1 = {9,8,7,6,5,4,3,2,1};

	LinkList* Obj1 = new LinkList();
	Obj1->AddElements(arr1);
	Obj1->display();

	ListPivot::pivot(Obj1->Head, 5)->display();
	return 0;
}