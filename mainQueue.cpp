#include <iostream>

#include "queue.h"

using namespace std;

int main()
{
	Queue<double> myQueue;
	
	myQueue.enqueue(12.3);
	myQueue.enqueue(12.7);
	myQueue.enqueue(12.9);
	myQueue.enqueue(12.12);
	myQueue.enqueue(12.6);
	
	cout<<myQueue.dequeue()<<endl;
	cout<<myQueue.dequeue()<<endl;
	cout<<myQueue.dequeue()<<endl;
	cout<<myQueue.dequeue()<<endl;
	cout<<myQueue.dequeue()<<endl;
	cout<<myQueue.dequeue()<<endl;
	
	return 0;
}
