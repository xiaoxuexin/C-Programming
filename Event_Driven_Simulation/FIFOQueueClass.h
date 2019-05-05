//  this is the
//  FIFOQueueClass.h file in
//  project5
//
//  Created by xiaoxue xin on 12/1/18.
//

#ifndef FIFOQueueClass_h
#define FIFOQueueClass_h

#include "LinkedNodeClass.h"

template <class T>
class FIFOQueueClass
{
private:
 LinkedNodeClass<T> *head;
 LinkedNodeClass<T> *tail;
public:
 FIFOQueueClass();
 ~FIFOQueueClass();
 void enqueue(const T &newItem);
 bool dequeue(T &outItem);
 void print()const;
 int getNumElems()const;
 void clear();
};

#include "FIFOQueueClass.inl"
#endif

