//  this is the
//  FIFOQueueClass.inl file in
//  project5
//
//  Created by xiaoxue xin on 12/1/18.
//

#include <iostream>
#include "FIFOQueueClass.h"

using namespace std;

template<class T>
FIFOQueueClass<T>:: FIFOQueueClass()
{
 head = 0;
 tail = 0;
}//constructor

template<class T>
FIFOQueueClass<T>:: ~FIFOQueueClass()
{
 clear();
}//destructor

template<class T>
void FIFOQueueClass<T>:: enqueue(const T &newItem)
{
 if (head == 0)
 {
  LinkedNodeClass<T> *temp;
  temp = new LinkedNodeClass<T>(0, newItem, 0);
  head = temp;
  tail = temp;
 }
 else
 {
  LinkedNodeClass<T> *addedNode;
  addedNode = new LinkedNodeClass<T>(tail, newItem, 0);
  addedNode -> setBeforeAndAfterPointers();
  tail = addedNode;
 }
}//add element at tail

template<class T>
bool FIFOQueueClass<T>:: dequeue(T &outItem)
{
 if (head == 0)
 {
  return 0;
 }
 else
 {
  outItem = head -> getValue();
  if (head == tail)
  {
   delete head;
   head = 0;
   tail = 0;
   return 1;
  }
  head = head -> getNext();
  delete head -> getPrev();
  head -> setPreviousPointerToNull();
  return 1;
 }
}//delete fist element in queue

template<class T>
void FIFOQueueClass<T>:: print()const
{
 LinkedNodeClass<T> *currNode;
 currNode = head;
 cout << "The customers in the waiting line: " << endl;
 while (currNode != 0)
 {
  cout << currNode -> getValue() << " ";
  currNode = currNode -> getNext();
 }
 cout << '\n';
}//print queue

template<class T>
int FIFOQueueClass<T>:: getNumElems()const
{
 LinkedNodeClass<T> *currNode;
 currNode = head;
 int count = 0;
 while (currNode != 0)
 {
  count = count + 1;
  currNode = currNode -> getNext();
 }
 return count;
}//get elements number

template<class T>
void FIFOQueueClass<T>:: clear()
{
 if (head != 0)
 {
  LinkedNodeClass<T> *todeleteNode;
  LinkedNodeClass<T> *currentNode;
  todeleteNode = head;
  currentNode = head;
  while (todeleteNode != 0)
  {
   currentNode = todeleteNode -> getNext();
   delete todeleteNode;
   todeleteNode = currentNode;
  }
  todeleteNode = 0;
  currentNode = 0;
  head = 0;
  tail = 0;
 }
}//clear dynamic allocation
