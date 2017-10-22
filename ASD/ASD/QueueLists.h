#pragma once
#include <iostream>

using namespace std;

#define MAX 10
struct Node{
	int data;
	Node *next;
};
class Queue {
	Node* front;
	Node* rear;
public:
	Queue();
	~Queue();


	int peek(); //returns element from the front
	bool isEmpty();
	void enqueue(int data);
	int dequeue();
	void printAll();

};