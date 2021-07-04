#include <bits/stdc++.h>
#include "LinkedList.hpp"

using namespace std;

class MergeSort
{
public:
	static Node* twoSortedList(Node* L1, Node* L2)
	{
		Node* retVal = new Node();

		auto tail = retVal;

		int i = 0;
		while(L1 and L2)
		{
			appendNode(L1->value <= L2->value ? L1 : L2, tail);	
		}

		tail->next = L1 ? L1 : L2;
		
		return retVal->next;
	}

	static void appendNode(Node*& inputNode, Node*& result)
	{			
		result->next = inputNode;
		inputNode = inputNode->next;
		result = result->next;
	}
};

int main(int argc, char const *argv[])
{
	array<int, 5> arr1 = {1,3,5,7,9};
	array<int, 10> arr2 = {0,2,4,6,8,10,11,12, 13,14};

	LinkList* Obj1 = new LinkList();
	Obj1->AddElements(arr1);
	Obj1->display();

	LinkList* Obj2 = new LinkList();
	Obj2->AddElements(arr2);
	Obj2->display();

	Node* Obj3 = MergeSort::twoSortedList(Obj1->Head, Obj2->Head);
	Obj3->display();

	return 0;
}