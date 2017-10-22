#include "DoublyLinkedList.h"

int main()
{
	DoublyLinkedList list;
	
	for (int i = 0; i < 10; i++)
	{
		list.addLast(i);
	}
	for (int i = 1; i < 10; i++)
	{
		list.addLast(i);
	}
	cout << list.length() << endl;
	list.displayForward();
	list.remove(1);
	list.displayForward();
	return 0;
}