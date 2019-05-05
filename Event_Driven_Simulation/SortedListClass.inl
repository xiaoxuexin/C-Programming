//  this is the
//  SortedListClass.inl file in
//  project5
//
//  Created by xiaoxue xin on 12/1/18.
//

#include "SortedListClass.h"
#include <iostream>

using namespace std;

template<class T>
SortedListClass<T>:: SortedListClass()
{
 head = 0;
 tail = 0;
}//default constructor

template<class T>
SortedListClass<T>:: SortedListClass(const SortedListClass &rhs)
{
 head = 0;
 LinkedNodeClass<T> *currNode;
 currNode = rhs.head;
 while (currNode != 0)
 {
  this -> insertValue(currNode -> getValue());
  currNode = currNode -> getNext();
 }
}//copy constructor

template<class T>
SortedListClass<T>:: ~SortedListClass()
{
 clear();
}//destructor

template<class T>
void SortedListClass<T>:: clear()
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
}//clear the dynamic allocation

template<class T>
void SortedListClass<T>:: insertValue(const T &valToInsert)
{
 if (head == 0)
 {
  LinkedNodeClass<T> *temp;
  temp = new LinkedNodeClass<T>(0, valToInsert, 0);
  head = temp;
  tail = temp;
 }
 else
 {
  LinkedNodeClass<T> *current;
  current = head;
  while ((current != 0) && (valToInsert >= current -> getValue()))
  {
   current = current -> getNext();
  }
  LinkedNodeClass<T> *temp;
  if (current == 0)
  {
   temp = new LinkedNodeClass<T>(tail, valToInsert, 0);
   tail = temp;
  }
  else
  {
   temp = new LinkedNodeClass<T>(current -> getPrev(),
                                 valToInsert, current);
   if (current -> getPrev() == 0)
   {
    head = temp;
   }
  }
  temp -> setBeforeAndAfterPointers();
 }
}//inster a node in the list

template<class T>
void SortedListClass<T>:: printForward()const
{
 cout << "current service situation in the restaurant:" << endl;
 LinkedNodeClass<T> *currNode;
 currNode = head;
 while (currNode != 0)
 {
  cout << "  " << currNode -> getValue() << endl;
  currNode = currNode -> getNext();
 }
}//print the list forward

template<class T>
void SortedListClass<T>:: printBackward()const
{
 cout << "Backward Event List Contents Follow:" << endl;
 LinkedNodeClass<T> *currNode;
 currNode = tail;
 while (currNode != 0)
 {
  cout << "  " << currNode -> getValue() << endl;
  currNode = currNode -> getPrev();
 }
 cout << "End of List Contents" << endl;
}//print the list backward

template<class T>
bool SortedListClass<T>:: removeFront(T &theVal)
{
 if (head == 0)
 {
  return 0;
 }
 else
 {
  theVal = head -> getValue();
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
}//remove the front node

template<class T>
bool SortedListClass<T>:: removeLast(T &theVal)
{
 if (tail == 0)
 {
  return 0;
 }
 else
 {
  theVal = tail -> getValue();
  if (head == tail)
  {
   delete head;
   head = 0;
   tail = 0;
   return 1;
  }
  tail = tail -> getPrev();
  delete tail -> getNext();
  tail -> setNextPointerToNull();
  return 1;
 }
}//remove the last node

template<class T>
int SortedListClass<T>:: getNumElems()const
{
 int numOfElems = 0;
 LinkedNodeClass<T> *currNode;
 currNode = head;
 if (currNode == 0)
 {
  return 0;
 }
 else
 {
  if (currNode == tail)
  {
   return 1;
  }
  while (currNode != tail)
  {
   currNode = currNode -> getNext();
   numOfElems = numOfElems + 1;
  }
  return numOfElems + 1;
 }
}//get the number of elements

template<class T>
bool SortedListClass<T>:: getElemAtIndex(const int index,
                                         T &outVal)const
{
 if ((index < 0) || (index > getNumElems() - 1))
 {
  return 0;
 }
 else
 {
  LinkedNodeClass<T> *currNode;
  int count = 0;
  currNode = head;
  while (count != index)
  {
   count = count + 1;
   currNode = currNode -> getNext();
  }
  outVal = currNode -> getValue();
  return 1;
 }
}//get element at certain index

