#include <iostream>

using namespace std;

#include "StackLists.h"

StackLists::StackLists()
{
	top = nullptr;
}

StackLists::~StackLists()
{
	while (top != nullptr)
	{
		//cout << "Deleted item from stack ";
		this->pop();
		
	}
}

bool StackLists::isEmpty() {
	if (top == nullptr)
		return true;
	else if (top != NULL)
		return false;
}

int StackLists::pop() {
	if (this->isEmpty() == true)
	{
		cout << "Stack underflow, can't retrieve data" << endl;
		this->printAll();
	}
	else
	{
		Node * toDelete = top;
		top = top->next;
		int x = toDelete->data;
		//cout << toDelete->data << endl;
		delete(toDelete);
		this->printAll();
		return x;
	}
}

void StackLists::push(int x) {
	Node *a = new Node();
	a->data = x;
	a->next = top;
	top = a;
	//cout << x << " added to stack" << endl;
	this->printAll();
}
int StackLists::peek() {
	if (this->isEmpty() == false)
		return this->top->data;
	else {
		cout << "Stack is empty" << endl;
		return -1;
	}
}

//
void StackLists::printAll() {
	if (top == nullptr)
		cout << "\nStack is Empty!!!\n";
	else {
		struct Node *temp = top;
		cout << "[";
		while (temp->next != nullptr) {
			cout << " " << temp->data;
			temp = temp->next;
		}
		cout << " " << temp->data << "] --->NULL " << endl;
	}
}