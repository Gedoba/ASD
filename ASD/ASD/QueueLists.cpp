#include "QueueLists.h"

Queue::Queue() {
	front = nullptr;
	rear = nullptr;
}

Queue::~Queue() {
	cout << "List queue is getting deleted" << endl;
	while (!isEmpty())
		dequeue();
	cout << "Whole list queue dequeued" << endl << endl;
}

void Queue::enqueue(int data) {
	Node* a = new Node();
	a->data = data;
	a->next = nullptr;
	
	if (front == nullptr)
	{
		front = rear = a;
		rear->next = nullptr;
	}
	else
	{
		rear->next = a;
		rear = a;
		rear->next = nullptr;
	}
	printAll();
}

int Queue::dequeue() {
	if (front == nullptr)
	{
		cout << "Queue underflow" << endl;
		return 0;
	}
	else
	{
		if (front->next != nullptr)
		{
			Node* toDelete = new Node();
			toDelete = front;
			int x = toDelete->data;
			front = front->next;
			cout << "Element deleted from queue is: " << x << endl;
			delete(toDelete);
			printAll();
			return x;
		}
		else
		{
			Node* toDelete = new Node();
			toDelete = front;
			int x = toDelete->data;
			cout << "Element deleted from queue is: " << x << endl;
			delete(toDelete);
			front = nullptr;
			rear = nullptr;
			printAll();
			return x;
		}
	}
	
}

void Queue::printAll() {
	if (isEmpty())
	{
		cout << "Queue is empty" << endl;
		return;
	}
	cout << "List Queue elements :" << endl << "Front -> [ ";
	Node* a = new Node();
	a = front;
	while (a != nullptr)
	{
		cout << a->data << " ";
		a = a->next;
	}
	cout << "] <- Rear" << endl;
}

bool Queue::isEmpty() {
	if (rear == nullptr && front == nullptr)
		return true;
	else
		return false;
}

int Queue::peek() {
	return front->data;
}