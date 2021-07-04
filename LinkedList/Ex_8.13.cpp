#include <bits/stdc++.h>
#include "LinkedList.hpp"

using namespace std;

class Solution
{
public:
	static Node* Add(Node* A, Node* B)
	{
		LinkList* result = new LinkList();

		int c = 0;
		int carry = 0;

		while(A and B)
		{
			c = A->value + B->value + carry;
			result->pushBack(c%10);
			carry = c/10;

			A = A->next,B = B->next;
		}

		if(carry > 0)
			result->pushBack(carry);
		return result->Head;
	}
	
};

int main(int argc, char* argv[])
{	
	array<int, 3> arr1 = {3,1,4};
	array<int, 3> arr2 = {7,0,9};

	LinkList* Obj1 = new LinkList();
	Obj1->AddElements(arr1);
	Obj1->display();

	LinkList* Obj2 = new LinkList();
	Obj2->AddElements(arr2);
	Obj2->display();

	Solution::Add(Obj1->Head, Obj2->Head)->display();
	return 0;
}