#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <assert.h>

template <class Elem>
class Queue
{
  public:
    Queue(int maxSize = 50);
    ~Queue();
    
    void enqueue(const Elem &item);
    Elem dequeue(void);
    unsigned int elemCnt(void);
    
  private:
    Elem* pData;
    unsigned int mCurrentElemCnt;
	const unsigned int MAX_SIZE;
	unsigned int mBeginning;
	unsigned int mEnd; 
};

template <class Elem>
Queue<Elem>::Queue(int maxSize): MAX_SIZE(maxSize)
{
    // This extra space added will allow us to distinguish between
    // the Beginning and the End locations.
    pData      = new Elem[MAX_SIZE + 1];
    mBeginning = 0;
    mEnd = 0;
    mCurrentElemCnt = 0;
}

template <class Elem>
Queue<Elem>::~Queue()
{
    delete[] pData; 
}

template <class Elem>
void Queue<Elem>::enqueue(const Elem &item)
{
      assert(mCurrentElemCnt < MAX_SIZE);
      
      pData[mEnd] = item;
      
      mEnd ++;
      mCurrentElemCnt ++;
      
      if(mEnd > MAX_SIZE)
      {
        mEnd -= (MAX_SIZE + 1);
      }
      
      
}

template <class Elem>
Elem Queue<Elem>::dequeue(void)
{
    assert(mCurrentElemCnt > 0);
    
    Elem returnValue = pData[mBeginning];
    
    mBeginning ++;
    
    mCurrentElemCnt --;
    
    if(mBeginning > MAX_SIZE)
    {
        mBeginning -= (MAX_SIZE + 1);
    }
    
    return returnValue;
}

template <class Elem>
unsigned int Queue<Elem>::elemCnt(void)
{
    return mCurrentElemCnt;
}


#endif
