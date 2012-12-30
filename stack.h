#ifndef _STACK_H_
#define _STACK_H_

#include <assert.h>

template<class Elem>
class Stack
{
public:
	~Stack();
	Stack(int maxSize = 100);
	void push(const Elem &newElement);
	Elem pop(void);

private:
	Elem* pData;
	unsigned int currentElemCnt;
	const unsigned int MAX_SIZE;
};

template<class Elem>
Stack<Elem>::~Stack()
{
	delete[] pData ;
}

template<class Elem>
Stack<Elem>::Stack(int maxSize) : MAX_SIZE(maxSize)
{
	pData = new Elem[MAX_SIZE];
	currentElemCnt = 0;
}

template<class Elem>
void Stack<Elem>::push(const Elem &newElement)
{
	assert(currentElemCnt < MAX_SIZE);
	pData[currentElemCnt] = newElement;
	currentElemCnt++;
}

template<class Elem>
Elem Stack<Elem>::pop(void)
{
	assert(currentElemCnt > 0);
	currentElemCnt--;
	return pData[currentElemCnt];
}


#endif