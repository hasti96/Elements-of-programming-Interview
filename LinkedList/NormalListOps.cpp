#include <bits/stdc++.h>
#include "LinkedList.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	LinkList* Obj1 = new LinkList();

	printf("============= Push Back Result ==========\n");
    Obj1->pushFront(1);Obj1->pushBack(9);Obj1->pushBack(5);
    Obj1->display();
    
    printf("============= Reverse Result ==========\n");
    Obj1->reverse();
    Obj1->display();
    
    printf("============= Insert After Result ==========\n");
    Node* inputNode = Obj1->search(9);
    Node* newNode = new Node(4);
    Obj1->insertAfter(inputNode, newNode);
    Obj1->display();

    printf("============= Delete After Result ==========\n");
    Node* inputNode2 = Obj1->search(9);
    Obj1->deleteAfter(inputNode2);
    Obj1->display();

    
	return 0;
}