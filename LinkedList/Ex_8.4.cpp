#include <bits/stdc++.h>
#include "LinkedList.hpp"

using namespace std;

class OverlappingNoCycleLists
{
public:
	static Node* findFirstCommonNode(Node* L1, Node* L2)
	{
		int diff = abs(L1->length() - L2->length());
		
		advanceListbyK(L1->length() > L2->length() ? L1 : L2, diff);

		while(L1 and L2 and L1 != L2)
		{
			L1 = L1->next; L2 = L2->next;
		}

		return L1;
	}

	static void advanceListbyK(Node*& node, int k)
	{
		while(k--)
		{
			node = node->next;
		}
	}

};

int main(int argc, char const *argv[])
{
	array<int, 5> arr1 = {1,2,3,4,5};
	array<int, 10> arr2 = {6,7,8,9,10,11,22,33,44,55};

	LinkList* Obj1 = new LinkList();
	Obj1->AddElements(arr1);
	Obj1->display();

	LinkList* Obj2 = new LinkList();
	Obj2->AddElements(arr2);
	Obj2->display();

	Obj1->search(5)->next = Obj2->search(10);
	Obj1->display();

	Node* retVal = OverlappingNoCycleLists::findFirstCommonNode(Obj1->Head, Obj2->Head);
	printf("common Node is : [%d]\n", retVal->value);
	
	return 0;
}