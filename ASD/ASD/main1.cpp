#include <iostream>
#include  "QueueArrays.h"

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




	return 0;
}