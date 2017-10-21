#pragma once
#include <iostream>

using namespace std;

#define MAX 100

class Stack {
	int top;
public:
	int stack[MAX]; //max size of stack

	Stack();
	~Stack();


	int peek();
	bool isFull();
	bool isEmpty();
	bool push(int x);
	int pop();
	void printAll();

};