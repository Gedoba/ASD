#include <iostream>
#include "StackArrays.h"
#include "StackLists.h"

using namespace std;

int main() {
	Stack s; //array stack
	int i = 0;
	while (i < 10)
	{
		s.push(i);
		i++;
	}

	cout << s.pop() << " popped" << endl;

	StackLists s1;
	i = 0;
	while (i < 10)
	{
		s1.push(i);
		i++;
	}

	cout << s1.pop() << " popped" << endl;


	return 0;
}