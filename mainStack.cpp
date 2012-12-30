#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
	Stack<double> myStack;
	
	myStack.push(12.3);
	myStack.push(12.7);
	myStack.push(12.9);
	myStack.push(12.12);
	myStack.push(12.6);
	
	cout<<myStack.pop()<<endl;
	cout<<myStack.pop()<<endl;
	cout<<myStack.pop()<<endl;
	cout<<myStack.pop()<<endl;
	cout<<myStack.pop()<<endl;
	cout<<myStack.pop()<<endl;
	
	return 0;
}