#include  "QueueArrays.h"


QueueArrays::QueueArrays() 
{
	this->front = -1;
	this->rear = -1;
}

QueueArrays::~QueueArrays()
{
	cout << "Array queue is getting deleted" << endl;
	while(front!=-1)
		dequeue();
	cout << "Whole array queue dequeued" << endl << endl;
}


int QueueArrays::peek()
{
	return queue[front];
}

bool QueueArrays::isFull()
{
	if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
		return true;
	else
		return false;
}

bool QueueArrays::isEmpty()
{
	if (front < 0 || rear < 0)
		return true;
	else
		return false;
}

bool QueueArrays::enqueue(int data)
{
	if (isFull())
	{
		cout << "Queue Overflow" << endl;
		return false;
	}
	if (front == -1)
	{
		front = 0;
		rear = 0;
	}
	else
	{
		if (rear == MAX - 1)
			rear = 0;
		else
			rear++;
	}
	queue[rear] = data;
	printAll();
	return true;

}

int QueueArrays::dequeue()
{
	if (this->isEmpty())
	{
		cout << "Queue Underflow" << endl;
		return 0;
	}
	cout << "Element deleted from queue is: " << queue[front] << endl;
	int deletedData = queue[front];
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
	{
		if (front == MAX - 1)
			front = 0;
		else
			front++;
	}
	printAll();
	return deletedData;
	
}

void QueueArrays::printAll() 
{
	int front_pos = front;
	int rear_pos = rear;
            if (front == -1)
            {
                cout<<"Queue is empty\n";
                return;
            }
            cout<<"Array Queue elements :" << endl << "Front -> [ ";
            if (front_pos <= rear_pos)
            {
                while (front_pos <= rear_pos)
                {
                    cout<<queue[front_pos]<<" ";
                    front_pos++;
                }
            }
            else
            {
                while (front_pos <= MAX - 1)
                {
                    cout<<queue[front_pos]<<" ";
                    front_pos++;
                }
                front_pos = 0;
                while (front_pos <= rear_pos)
                {
                    cout<<queue[front_pos]<<" ";
                    front_pos++;
                }
            }
			cout << "] <- Rear" << endl;
}

