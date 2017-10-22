#include <iostream>

using namespace std;
#include "StackArrays.h"

#define MAX 10

Stack::Stack() 
{
	top = -1;
}

Stack::~Stack()
{
	for (int i = 0; i < MAX; i++)
		{
			stack[i] = 0;
		}
	cout << "Array filled with 0s" << endl;
}

int Stack::peek() {
	if (this->isEmpty() == false)
		return stack[top];
	else {
		cout << "Stack is empty" << endl;
		return -1;
	}

}

bool Stack::isFull() {
	if (top >= MAX)
		return true;
	else
		return false;
}

bool Stack::isEmpty() {
	if (top <= -1)
		return true;
	else
		return false;

}

bool Stack::push(int data) {
	if (this->isFull() == true)
	{
		cout << "Stack overflow, couldn't insert the data" << endl;
		return false;
	}
	else
	{
		top++;
		stack[top] = data;
		return true;
		//cout << stack[top] << endl;

	}
	this->printAll();
}

int Stack::pop() {
	if (this->isEmpty() == true)
	{
		cout << "Stack underflow, couldn't retrieve the data" << endl;
		return 0;
	}
	else
	{
		int x = stack[top];
		top--;
		return x;
	}
}

void Stack::printAll() {
	int i = this->top;
	cout << "[ ";
	while (i>=0)
	{
		cout << stack[i] << " ";
		i--;
	}
	cout << "]" << endl;
}