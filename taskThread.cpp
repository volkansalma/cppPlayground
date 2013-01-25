#include "taskThread.h"
#include <iostream>


TaskThread::TaskThread(void* (*pTaskFunction)(void*), int priority)
{
    pthread_create(&mThreadObj, NULL, pTaskFunction, NULL);
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


void TaskSleepUS(unsigned int miliSecSleepTime)
{
    usleep(miliSecSleepTime);
}

void TaskSleepS(unsigned int secSleepTime)
{
    sleep(secSleepTime);
}
    
    
