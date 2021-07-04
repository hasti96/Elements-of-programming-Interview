/*
	FIND LCA of two node...
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

// Assume n1 < n2 [n1, n2] 
Node* findLCAinBST(Node* root, int n1, int n2)
{
	while(root->data < n1 or root->data > n2)
	{
		while(root->data < n1)
			root = root->right;
		
		while(root->data > n2)
			root = root->left;
	}
	return root;
}


int main()	
{
	/*
			3
		   / \
		  2   7
		 /   / \
		1   4   8
	*/
	Node* left = new Node(2, new Node(1), nullptr);
	Node* right = new Node(7, new Node(4), new Node(8));
	Node* root = new Node(3, left, right);

	cout<< findLCAinBST(root, 4, 8)->data << endl;


	return 0;
}