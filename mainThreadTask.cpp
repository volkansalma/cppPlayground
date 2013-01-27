#include <iostream>

#include "taskThread.h"

using namespace std;

TaskMutex myMutex;

void* myTaskFunction1(void* pData)
{
    unsigned int cnt = 0;
    int* param;
    param = (int*)pData;
    
    while(1)
    {
        myMutex.lock();
        cout<<"Task"<<*param<<":"<<cnt<<endl;
        cnt++;
        myMutex.unlock();
        TaskUtilities::TaskSleepUSec(100); 
    }
}

void* myTaskFunction2(void* pData)
{
    unsigned int cnt = 888;
    int* param;
    param = (int*)pData;
    
    while(1)
    {
        myMutex.lock();
        cout<<"Task"<<*param<<":"<<cnt<<endl;
        cnt++; 
        myMutex.unlock();
        TaskUtilities::TaskSleepSec(1);
    }
}


int main()
{
    int param1 = 1;
    int param2 = 2;
    
    TaskThread task1(&myTaskFunction1, 1, (void*)&param1);
    TaskThread task2(&myTaskFunction2, 1, (void*)&param2);
    
    
    while(1){}
}
