#pragma once
#define MAX 100

struct Node {
	int data;
	Node *next;
};
class StackLists {
	Node *top;
public:
	StackLists();
	~StackLists();

	int peek();
	bool isEmpty();
	void push(int x);
	int pop();
	void printAll();

};

