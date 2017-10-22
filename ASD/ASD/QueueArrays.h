#pragma once
#include <iostream>

using namespace std;

#define MAX 10

class QueueArrays {
	int rear;
	int front;
public:
	int queue[MAX]; //max size of queue

	QueueArrays();
	~QueueArrays();


	int peek();
	bool isFull();
	bool isEmpty();
	bool enqueue(int x);
	int dequeue();
	void printAll();

};