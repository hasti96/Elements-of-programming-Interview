#include <bits/stdc++.h>
#include "LinkedList.hpp"

using namespace std;

class CyclicShift
{
public:
	static Node* Right(LinkList*& inputList, int k)
	{
		int length = inputList->Head->length(); 
		int shift =  k % length;

		auto tailNode = inputList->getTailNode();
		
		tailNode->next = inputList->Head;

		int step_to_new_head = length - shift;

		auto new_tail = tailNode;
		// printf("length:[%d], shift : [%d], steptoHead : [%d]\n", length, shift, step_to_new_head);
		while(step_to_new_head--)
		{
			new_tail = new_tail->next;	
		}

		inputList->Head = new_tail->next;
		// printf("%d [%d]\n", __LINE__, inputList->Head->value);
		new_tail->next = nullptr;

		return inputList->Head;
	}
};

int main(int argc, char const *argv[])
{
	array<int, 9> arr1 = {1,2,3,4,5,6,7,8,9};

	LinkList* Obj1 = new LinkList();
	Obj1->AddElements(arr1);
	Obj1->display();

	CyclicShift::Right(Obj1, 2)->display();

	return 0;
}