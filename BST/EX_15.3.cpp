/*
	Find Kth Largest Element in BST
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

void findKthLargest(Node* root, vector<int>& k_element)
{
	if(root == nullptr or k_element.size() > 2)
		return;

	findKthLargest(root->right, k_element);
	k_element.emplace_back(root->data);
	findKthLargest(root->left, k_element);
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

	vector<int> element = {};

	findKthLargest(root, element);

	for(auto i: element)
		cout<< i << endl;

	return 0;
}