//  this is the
//  SortedListClass.h file in
//  project5
//
//  Created by xiaoxue xin on 12/1/18.
//

#ifndef SortedListClass_h
#define SortedListClass_h

#include "LinkedNodeClass.h"

template <class T>
class SortedListClass
{
private:
 LinkedNodeClass<T> *head;
 LinkedNodeClass<T> *tail;
public:
 SortedListClass();//constructor
 SortedListClass(const SortedListClass &rhs);
 ~SortedListClass();
 void clear();
 void insertValue(const T &valToInsert);
 void printForward()const;
 void printBackward()const;
 bool removeFront(T &theVal);
 bool removeLast(T &theVal);
 int getNumElems()const;
 bool getElemAtIndex(const int index,
                     T &outVal)const;
};

#include "SortedListClass.inl"
#endif 
