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
    pthread_mutex_init(&mMutexObj, NULL);
}

TaskMutex::~TaskMutex()
{
    pthread_mutex_destroy(&mMutexObj);
}

void TaskMutex::lock()
{
    pthread_mutex_lock (&mMutexObj);
}

void TaskMutex::unlock()
{
    pthread_mutex_unlock(&mMutexObj);
}

TaskSemaphore::TaskSemaphore(unsigned int initialCount)
{
     sem_init(&mSemObj, 0, initialCount);
}

TaskSemaphore::~TaskSemaphore()
{
    sem_destroy(&mSemObj);
}

void TaskSemaphore::post()
{
    sem_post(&mSemObj); 
}

int TaskSemaphore::wait()
{
    return sem_wait(&mSemObj);
}

int TaskSemaphore::getCnt()
{
    int result; 
    sem_getvalue(&mSemObj, &result); 
    
    return result;
}


void TaskUtilities::TaskSleepUSec(unsigned int miliSecSleepTime)
{
    Sleep(miliSecSleepTime);
}

void TaskUtilities::TaskSleepSec(unsigned int secSleepTime)
{
    Sleep(secSleepTime * 1000);
}
    
    
