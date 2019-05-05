//  this is the file
//  LinkedNodeClass.inl in
//  project5
//
//  Created by xiaoxue xin on 12/1/18.
//

#include "LinkedNodeClass.h"
#include <iostream>

using namespace std;

template<class T>
LinkedNodeClass<T>:: LinkedNodeClass(LinkedNodeClass<T> *inPrev,
                                     const T &inVal,
                                     LinkedNodeClass<T> *InNext)
{
 prevNode = inPrev;
 nodeVal = inVal;
 nextNode = InNext;
}//constructor

template<class T>
T LinkedNodeClass<T>:: getValue()const
{
 return nodeVal;
}//get node value

template<class T>
LinkedNodeClass<T> *LinkedNodeClass<T>:: getNext()const
{
 return nextNode;
}//get next pointer

template<class T>
LinkedNodeClass<T> *LinkedNodeClass<T>:: getPrev()const
{
 return this -> prevNode;
}//get previous pointer

template<class T>
void LinkedNodeClass<T>:: setNextPointerToNull()
{
 nextNode = 0;
}//set next pointer to null

template<class T>
void LinkedNodeClass<T>:: setPreviousPointerToNull()
{
 prevNode = 0;
}//set previous pointer to null

template<class T>
void LinkedNodeClass<T>:: setBeforeAndAfterPointers()
{
 if (nextNode != 0)
 {
  nextNode -> prevNode = this;
 }
 if (prevNode != 0)
 {
  prevNode -> nextNode = this;
 }
}//set the double linked list well
