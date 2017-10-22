#include <iostream>
#include  "QueueArrays.h"
#include "QueueLists.h"

using namespace std;

int main()
{
	QueueArrays Q;
	int i = 0;

	while (i < 5) {
		Q.enqueue(i);
		i++;
	}
	for (i = 0; i < 8; i++)
	{
		Q.dequeue();
	}
	cout << endl << endl << endl << endl;

	Queue Q1;
	i = 0;

	while (i < 5) {
		Q1.enqueue(i);
		i++;
	}
	for (i = 0; i < 8; i++)
	{
		Q1.dequeue();
	}
	cout << endl << endl << endl << endl;
	


	return 0;
}