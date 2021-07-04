#include <bits/stdc++.h>
#include "LinkedList.hpp"

using namespace std;

class TestForCyclic
{

public:
	/*
	find cycle by calculating the length of the cycle.
	*/
	static Node* find(Node* node)
	{
		Node* retVal = nullptr;

		Node* p1 = node;
		Node* p2 = node;

		while(p2 != nullptr)
		{
			p1 = p1->next;
			p2 = p2->next->next;

			if(p1 == p2)
				break;
		}

		int loopNodeCount = 0;
		if(p1 == p2)
		{	
			p2 = p2->next;
			while(p1 != p2)
			{
				p2 = p2->next;
				loopNodeCount++;	
			}

			p1 = node;
			p2 = node;

			for(int i=0; i <= loopNodeCount; i++)
				p2 = p2->next;

			// printf("p1:[%d], p2:[%d]", p1->value, p2->value);
			while(p1 != p2)
			{
				p1 = p1->next;
				p2 = p2->next;
			}

			retVal = p1;
		}

		return retVal;
	}

	/*
	find cycle without knowing the length of the cycle
	*/

	static Node* findwithoutCycleLength(Node* node)
	{
		Node* retVal = nullptr;
		Node* p1 = node;
		Node* p2 = node;

		while(p2 and p2->next->next)
		{
			p1 = p1->next, p2 = p2->next->next;

			if(p1 == p2)
			{	
				p1 = node;
				while(p1 != p2) {
					p1 = p1->next, p2 = p2->next;
				}
				retVal = p1;
				break;
			}
		}

		return retVal;
	}
};

int main(int argc, char* argv[])
{
	array<int, 10> arr1 = {1,2,3,4,5,6,7,8,9,10};
	

	LinkList* Obj1 = new LinkList();
	Obj1->AddElements(arr1);
	Obj1->display();
	Obj1->search(10)->next = Obj1->search(6);

	Node* Retval = TestForCyclic::find(Obj1->Head);

	if(Retval != nullptr)
		printf("[%d]\n", Retval->value);



	Node* Retval1 = TestForCyclic::findwithoutCycleLength(Obj1->Head);

	if(Retval1 != nullptr)
		printf("[%d]\n", Retval1->value);

	return 0;
}