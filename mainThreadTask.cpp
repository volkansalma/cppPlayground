#include <iostream>

#include "taskThread.h"

using namespace std;

TaskMutex myMutex;

void* myTaskFunction1(void* p)
{
    unsigned int cnt = 0;
    
    while(1)
    {
        myMutex.lock();
        cout<<"Task1 :"<<cnt<<endl;
        cnt++;
        myMutex.unlock();
        TaskSleepS(2); 
    }
}

void* myTaskFunction2(void* p)
{
    unsigned int cnt = 888;
    
    while(1)
    {
        myMutex.lock();
        cout<<"Task2 :"<<cnt<<endl;
        cnt++; 
        myMutex.unlock();
        TaskSleepS(1);
    }
}


int main()
{
    TaskThread task1(&myTaskFunction1, 1);
    TaskThread task2(&myTaskFunction2, 1);
    
    
    while(1){}
}
