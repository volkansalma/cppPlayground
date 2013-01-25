#ifndef _TASK_THREAD_H
#define _TASK_THREAD_H

#include <cstdlib>
#include <pthread.h>

class TaskThread
{
public:
    TaskThread(void* (*pTaskFunction)(void*), int priority);
    ~TaskThread();
      
private:
    void* (*pmTaskFunction)(void*); 
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

void TaskSleepUS(unsigned int miliSecSleepTime);

void TaskSleepS(unsigned int secSleepTime);

#endif //_TASK_THREAD_CPP
