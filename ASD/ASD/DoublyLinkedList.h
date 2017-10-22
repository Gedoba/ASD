#pragma once

#include <iostream>
using namespace std;


class DoublyLinkedNode {
public:
	int info;
	DoublyLinkedNode *next, *prev;

	DoublyLinkedNode() {
		next = prev = 0;
	}

	DoublyLinkedNode(int info, DoublyLinkedNode *next = 0, DoublyLinkedNode *prev = 0) {
		this->info = info;
		this->next = next;
		this->prev = prev;
	}
};

class DoublyLinkedList {
private:
	DoublyLinkedNode *first, *last;
public:
	DoublyLinkedList() {
		first = last = 0;
	}

	~DoublyLinkedList();

	bool isEmpty() const {
		return first == 0;
	}

	void addFirst(int);
	void addLast(int);
	int removeFirst();
	int removeLast();
	void remove(int n); //removes 1st found instance of n
	bool contains(int) const;
	int length();
	void displayForward();
};
