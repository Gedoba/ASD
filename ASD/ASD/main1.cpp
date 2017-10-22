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
	Q.dequeue(); Q.dequeue();
	cout << endl << endl;
	cout << endl << endl;

	Queue Q1;
	i = 0;

	while (i < 5) {
		Q1.enqueue(i);
		i++;
	}
	Q1.dequeue(); Q1.dequeue();
	cout << endl << endl;
	cout << endl << endl;


	return 0;
}