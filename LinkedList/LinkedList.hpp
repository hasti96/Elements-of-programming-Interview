#include <bits/stdc++.h>

using namespace std;

class Node 
{
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

    void display() 
	{
		Node* ptr = this;
		while (ptr != nullptr) 
		{
			if(ptr->next != nullptr)
		    	printf("[%d]->", ptr->value);
		    else
		    	printf("[%d]\n", ptr->value);

		    ptr = ptr->next;
		}
	}

	int length()
	{
		Node* ptr = this;
		int length = 1;
		while (ptr->next != nullptr) 
		{
		    length++;
		    ptr = ptr->next;
		}

		return length;
	}

	Node* getTailNode() 
    {
    	Node* ptr = this;
    	while(ptr->next != nullptr)
    	{
    		ptr = ptr->next;
    	}

    	return ptr;
    }
};


class LinkList
{

public:

	Node* Head;

    LinkList():Head(nullptr){};
    LinkList(Node* node):Head(node) {}
    ~LinkList();

    void pushFront(const int&);
    void pushBack(const int&);
    void display();
    Node* search(const int&);
    void reverse();
    void insertAfter(Node* node, Node* new_node);
    void deleteAfter(Node* node);

    template <size_t N>
    void AddElements(array<int, N> input);
    
    Node* getTailNode() 
    {
    	Node* ptr = Head;
    	while(ptr->next != nullptr)
    	{
    		ptr = ptr->next;
    	}

    	return ptr;
    }
};

void LinkList::pushFront(const int& value) 
{
	    Node* new_node = new Node(value);
	    new_node->next = Head;
	    Head = new_node;    
}

void LinkList::pushBack(const int& value) 
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

void LinkList::display() 
{
	Node* ptr = Head;
	while (ptr != nullptr) 
	{
		if(ptr->next != nullptr)
	    	printf("[%d]->", ptr->value);
	    else
	    	printf("[%d]\n", ptr->value);

	    ptr = ptr->next;
	}
}

void LinkList::reverse()
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

Node* LinkList::search(const int& key)
{
	Node* retVal = Head;

	while(retVal and retVal->value != key)
	{
		retVal = retVal->next;
	}

	return retVal;
} 

void LinkList::insertAfter(Node* node, Node* new_node)
{
	new_node->next = node->next;
	node->next = new_node;
}

void LinkList::deleteAfter(Node* node)
{
	Node* unused_node = node->next;
	node->next = node->next->next;

	delete unused_node;
}

template <size_t N>
void LinkList::AddElements(array<int, N> input)
{
	for(auto i: input)
		pushBack(i);
}