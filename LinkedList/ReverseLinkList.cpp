#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int value;
        Node* next;

        Node():value(0),next(nullptr){}
        Node(const int& value):value(value), next(nullptr){}
        Node(const int& value, Node* next):value(value), next(next){}

        Node* operator=(Node* input) 
        {
        	this->value = input->value;
        	this->next = input->next;

        	return this;
        }
};


class LinkList
{

public:

	Node* Head;

    LinkList():Head(nullptr){};
    ~LinkList();

	void pushFront(const int& value) 
	{
	    Node* new_node = new Node(value);
	    new_node->next = Head;
	    Head = new_node;    
	}

	void pushBack(const int& value) 
	{
	    if(Head == nullptr) 
	    {
	        pushFront(value);
	    }
	    else 
	    {
	        Node* node = Head;
	        while (node->next != nullptr) 
	        {
	            node = node->next;
	        }
	        node->next = new Node(value);
	    }
	}

	void display() 
	{
	    Node* ptr = Head;
	    while (ptr != nullptr) 
	    {
	        cout << ptr->value << endl;
	        ptr = ptr->next;
	    }
	}

	void reverse()
	{
		Node* prevNode;
		Node* currNode;
		Node* nextNode;

		prevNode = nullptr;
		currNode = Head;
		

		while(currNode != nullptr)
		{
			nextNode = currNode->next;
			currNode->next = prevNode;

			prevNode = currNode;
			currNode = nextNode;
		}

		this->Head = prevNode;
	}
};

int main(int argc, char* argv[])
{
	LinkList* Obj1 = new LinkList();
    Obj1->pushFront(1);Obj1->pushBack(9);Obj1->pushBack(5);
    Obj1->display();
    printf("==========================================\n");
    Obj1->reverse();
    Obj1->display();
    
	return 0;
}