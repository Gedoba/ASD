#pragma once
#include <iostream>

using namespace std;

#define MAX 100


class StackLists {
	struct Node {
		int data;
		Node *next;
	};
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

