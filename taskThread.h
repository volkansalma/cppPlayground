#ifndef _TASK_THREAD_H
#define _TASK_THREAD_H

#ifdef WIN32
#include <windows.h> // needed for Sleep 
#else
#include <unistd.h>
#define Sleep(x) usleep((x)*1000)
#endif

#include <pthread.h>

class TaskThread
{
public:
    TaskThread(void* (*pTaskFunction)(void*), int taskPriority = 0, 
                       void* pData = NULL);
    ~TaskThread();
      
private:
    pthread_t mThreadObj;   
};

class TaskMutex
{
public:
      TaskMutex();
      ~TaskMutex();
      void lock(); 
      void unlock();
      
private:
    pthread_mutex_t mMutexObj;
};

class TaskUtilities
{
public:
    static void TaskSleepUSec(unsigned int miliSecSleepTime);
    static void TaskSleepSec(unsigned int secSleepTime);
};

#endif //_TASK_THREAD_CPP
