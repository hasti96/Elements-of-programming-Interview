/*
	Find the first tree greater than a given value
*/

#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node(int data): data(data), left(nullptr), right(nullptr) {}
	Node(int data, Node* left, Node* right): data(data), left(left), right(right) {} 
};

Node* findNode(Node* root, int n)
{
	if(root)
	{
		if(n < root->data)
			return findNode(root->left, n);
		else if(n > root->data)
			return findNode(root->right, n);
		else
			return root->right;
	}

	return nullptr;
}

int findGreaterValue(Node* root, int n)
{	
	if(root)
	{
		Node* curr = findNode(root, n);
		
		if(curr)
		{
			int minNext = INT_MAX;

			while(curr)
			{
				if(curr->left)
				{
					curr = curr->left;
				}
				else if(curr->right)
				{
					curr = curr->right;
				}
				else
				{
					return minNext;
				}

				minNext = min(minNext, curr->data);
			}

			return minNext;	
		}
	}
	return INT_MAX;
}

int main()
{
	/*
			3
		   / \
		  2   7
		 /   / \
		1   5   8

	*/
	Node* left = new Node(2, new Node(1), nullptr);
	Node* right = new Node(7, new Node(5), new Node(8));
	// right->left->left = new Node(4);
	right->left->right = new Node(6);
	Node* root = new Node(3, left, right);

	cout<< findGreaterValue(root, 3) << endl;
	return 0;
}