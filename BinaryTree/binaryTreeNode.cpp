#include <bits/stdc++.h>

using namespace std;

class BinaryTreeNode
{
public:
	int data;
	
	BinaryTreeNode* left;
	BinaryTreeNode* right;


	BinaryTreeNode(int data, BinaryTreeNode* left, BinaryTreeNode* right) :data(data), left(left), right(right) {};

	BinaryTreeNode(int data):data(data), right(nullptr), left(nullptr) {};


	void static TreeTraversal(BinaryTreeNode* root)
	{
		if(root)
		{
			// printf("%d",root->data); // pre-order traversal..
			TreeTraversal(root->left);

			printf("%d",root->data); // In-order traversal...
			TreeTraversal(root->right);

			//printf("%d",root->data); // Post-order traversal....

		}
	}

	void static preOrder(BinaryTreeNode* root)
	{
		printf("%d",root->data); // pre-order traversal..
		TreeTraversal(root->left);
		TreeTraversal(root->right);
	}

	void static inOrder(BinaryTreeNode* root)
	{
		TreeTraversal(root->left);
		printf("%d",root->data); // In-order traversal..
		TreeTraversal(root->right);
	}

	void static postOrder(BinaryTreeNode* root)
	{
		TreeTraversal(root->left);
		TreeTraversal(root->right);
		printf("%d",root->data); // post-order traversal..
	}
};

int main(int argc, char const *argv[])
{
	BinaryTreeNode* left 	= new BinaryTreeNode(2, new BinaryTreeNode(4), new BinaryTreeNode(5));
	BinaryTreeNode* right 	= new BinaryTreeNode(3, new BinaryTreeNode(6), new BinaryTreeNode(7));
	BinaryTreeNode* root	= new BinaryTreeNode(1, left, right);

	BinaryTreeNode::TreeTraversal(root);

	return 0;
}