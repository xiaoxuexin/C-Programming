//  this is the
//  LinkedNodeClass.h file in
//  project5
//
//  Created by xioaxue xin on 12/1/18.
//

#ifndef LinkedNodeClass_h
#define LinkedNodeClass_h

template<class T>
class LinkedNodeClass
{
private:
 LinkedNodeClass<T> *prevNode;
 T nodeVal;
 LinkedNodeClass<T> *nextNode;
public:
 LinkedNodeClass(LinkedNodeClass<T> *inPrev,
                 const T &inVal,
                 LinkedNodeClass<T> *inNext);//constructor
 T getValue()const;
 LinkedNodeClass<T>* getNext()const;
 LinkedNodeClass<T>* getPrev()const;
 void setNextPointerToNull();
 void setPreviousPointerToNull();
 void setBeforeAndAfterPointers();
};

#include "LinkedNodeClass.inl"
#endif

