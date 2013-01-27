#include "taskThread.h"

TaskThread::TaskThread(void* (*pTaskFunction)(void*), int taskPriority, 
                       void* pData)
{
    pthread_create(&mThreadObj, NULL, pTaskFunction, pData);
}

TaskThread::~TaskThread()
{
    pthread_exit(&mThreadObj);
}

TaskMutex::TaskMutex()
{
}

TaskMutex::~TaskMutex()
{
}

void TaskMutex::lock()
{
    pthread_mutex_lock (&mMutexObj);
}

void TaskMutex::unlock()
{
    pthread_mutex_unlock(&mMutexObj);
}


void TaskUtilities::TaskSleepUSec(unsigned int miliSecSleepTime)
{
    Sleep(miliSecSleepTime);
}

void TaskUtilities::TaskSleepSec(unsigned int secSleepTime)
{
    Sleep(secSleepTime * 1000);
}
    
    
