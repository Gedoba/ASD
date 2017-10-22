#include "DoublyLinkedList.h"


DoublyLinkedList::~DoublyLinkedList() {
	for(DoublyLinkedNode * node = first; node != nullptr;) {
		DoublyLinkedNode * toDelete = node;
		node = node->next;
		cout << "deleting: " << toDelete->info << endl;
		delete toDelete;
	}
}

void DoublyLinkedList::addFirst(int n) {
	if (first == 0) {
		first = new DoublyLinkedNode(n);
		last = first;
		return;
	}

	DoublyLinkedNode *tmp = new DoublyLinkedNode(n, first);
	first->prev = tmp;
	first = tmp;

}

void DoublyLinkedList::addLast(int n) {
	if (last != 0) {
		last = new DoublyLinkedNode(n, 0, last);
		last->prev->next = last;
	}
	else {
		first = last = new DoublyLinkedNode(n);
	}
}

int DoublyLinkedList::removeFirst() {
	int el = first->info;
	if (first == last) {
		delete first;
		first = last = 0;
	}
	else {
		first = first->next;
		delete first->prev;
		first->prev = 0;
	}
	return el;
}

int DoublyLinkedList::removeLast() {
	int el = last->info;
	if (first == last) {
		delete last;
		first = last = 0;
	}
	else {
		last = last->prev;
		delete last->next;
		last->next = 0;
	}
	return el;
}

void DoublyLinkedList::remove(int n) {
	if (first != 0) {

		if (first == last) {
			delete first;
			first = last = 0;
		}

		if (first->info == n) {
			removeFirst();
			return;
		}

		if (last->info == n) {
			removeLast();
			return;
		}

		DoublyLinkedNode *tmp;
		tmp = first;
		while (tmp != 0) {
			if (tmp->info != n) {
				tmp = tmp->next;
			}
			else {
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				delete tmp;
				tmp = 0;
				//return;
			}
		}
	}
}

bool DoublyLinkedList::contains(int el) const {
	for (DoublyLinkedNode * node = first; node != nullptr; node = node->next) {
		if (node->info == el) {
			return true;
		}
	}
	return false;
}

int DoublyLinkedList::length() {
	int length = 0;
	struct DoublyLinkedNode *current;

	for (current = first; current != nullptr; current = current->next) {
		length++;
	}

	return length;
}

void DoublyLinkedList::displayForward() {

	//start from the beginning
	struct DoublyLinkedNode *ptr = first;

	//navigate till the end of the list
	printf("\n[ ");

	while (ptr != nullptr) {
		cout << ptr->info << " ";
		ptr = ptr->next;
	}

	cout << "]" << endl;
}