//  this is the
//  SimulationClass.cpp file in
//  project5
//
//  Created by xiaoxue xin on 12/1/18.
//

#include "SimulationClass.h"
#include <iostream>
#include <string>

using namespace std;

SimulationClass:: SimulationClass()
{
 leaveCustNum = 0;
 totalSevTime = 0;
 lastCustID = 0;
 endTime = 0;
 waitedCustNum = 0;
 longestLine = 0;
 waitingTime = 0;
 waitedTooLongNum = 0;
 longestWaitedTime = 0;
 EventClass initialCustomer(0, 0, CUSTOMER_ARRIVAL);
 // generate first customer arrival event
 eventList.insertValue(initialCustomer);
} // constructor

SimulationClass:: ~SimulationClass()
{
}

void SimulationClass:: handleArrivalEvent(EventClass &arrEvent)
{
 cout << "customer " << arrEvent.getCustomer()\
 << " arrives at time " << arrEvent.getTime() << endl;
 if (eventList.getNumElems() > 0) // someone is being serverd
 {
  if ((waitingQueue.getNumElems() > longLine) &&
      (getUniform(1, 100) < leavePercentage))
  {
   cout << "he/she " << "leaves since the \
line is too long." << endl;
   leaveCustNum = leaveCustNum + 1; // leave directly
  }
  else // wait in the queue
  {
   cout << "he/she " << "has to wait in the queue." << endl;
   waitingQueue.print();
   eventList.printForward(); // when the current service will complete
   CustomerClass waitCustomer(arrEvent.getCustomer(),
                              arrEvent.getTime());
   waitingQueue.enqueue(waitCustomer); // add customer in the queue
   waitedCustNum = waitedCustNum + 1;
  }
 }
 else // get service directly
 {
  cout << "he/she " << "can get service immediately." << endl;
  int serviceTime = getNormal(normMean, normStdDev);
  totalSevTime = serviceTime + totalSevTime;
  int compTime = arrEvent.getTime() + serviceTime;
  EventClass compEvent(arrEvent.getCustomer(),
                       compTime,
                       SERVICE_COMPLETE);
  eventList.insertValue(compEvent);
  // add service-complete event in event list
 }
 int deltaTime = getUniform(unifMin,
                            unifMax);
 int nextArrTime = 0;
 nextArrTime = arrEvent.getTime() + deltaTime;
 if (nextArrTime <= closingTime) // come in before closing
 {
  EventClass nextArrEvent(arrEvent.getCustomer() + 1,
                          nextArrTime,
                          CUSTOMER_ARRIVAL);
  eventList.insertValue(nextArrEvent);
 }// arrange new customer arrival and add in event list
} // handle arrival event

void SimulationClass:: handleServiceCopmEvent(EventClass &compEvent)
{
  CustomerClass customer;
  if (waitingQueue.dequeue(customer)) // if queue is not empty
  // take the first customer in waiting queue out
  {
   int serviceTime = getNormal(normMean, normStdDev);
   totalSevTime = serviceTime + totalSevTime;
   waitingTime = compEvent.getTime() - customer.getArrTime();
   // time that each customer has waited
   if (waitingTime > longestWaitedTime)
   {
    longestWaitedTime = waitingTime;
   } // the longest time that customer has waited
   if (waitingTime > 10)
   {
    waitedTooLongNum = waitedTooLongNum + 1;
   } // if the waited time is longer than 10, it is too long waited time
   int compTime = compEvent.getTime() + serviceTime;
   EventClass nextCompEvent(customer.getCustId(),
                            compTime,
                            SERVICE_COMPLETE);
   eventList.insertValue(nextCompEvent);
   // arrange next complete-service event and add in event list
  } 
} // handle service complete event

void SimulationClass:: simulateProcess()
{
 EventClass eventToBeHandled;
 while (eventList.removeFront(eventToBeHandled))
 {
  if (eventToBeHandled.getType() == CUSTOMER_ARRIVAL)
  {
   handleArrivalEvent(eventToBeHandled);
  }
  if (eventToBeHandled.getType() == SERVICE_COMPLETE)
  {
   handleServiceCopmEvent(eventToBeHandled);
  }
  if (eventToBeHandled.getCustomer() > lastCustID)
  {
   lastCustID = eventToBeHandled.getCustomer();
  } // record total number of customers
  endTime = eventToBeHandled.getTime();
  if (waitingQueue.getNumElems() > longestLine)
  {
   longestLine = waitingQueue.getNumElems();
  } // longest line of waiting queue
 }
} // simulate the process

void SimulationClass:: outputStatistics()
{
 cout << "Total number of customers that showed \
up " << lastCustID + 1 << endl;
 cout << "Percentage of time the server was busy \
helping customers " << 100 * float(totalSevTime)\
 / float(endTime) << "%" << endl;
 cout << "Percentage of customers had to wait in \
line " << 100 * float(waitedCustNum) / \
 float(lastCustID + 1) << "%" << endl;
 cout << "The number of customers that arrived, \
but left due to excessive line length " << leaveCustNum << endl;
 cout << "The longest the line was throughout \
the simulation " << longestLine << endl;
 cout << "The restaurant can close at " << endTime << endl;
 cout << "The number of customers that have waited \
for more than 10 units of time " << waitedTooLongNum << endl;
 cout << "The longest time that some customer \
has waited " << longestWaitedTime << endl;
} // output the statistical result of this simulation

void SimulationClass:: readinput()
{
 float mini = 0;
 float maxi = 0;
 cout << "the customer ID is 0-based" << endl;
 cout << "input the integer min for uniform distribution: ";
 cin >> mini;
 while (cin.fail() || mini < 1)
 {
  cin.clear();
  cin.ignore(RANGE_STRING, '\n');
  cout << "please enter positive min again: " << endl;
  cin >> mini;
 }
 int min = int(mini);
 cout << "input the integer max for uniform distribution: ";
 cin >> maxi;
 while (cin.fail() || maxi < min)
 {
  cin.clear();
  cin.ignore(RANGE_STRING, '\n');
  cout << "please enter max that greater than min \
again: " << endl;
  cin >> maxi;
 }
 int max = int(maxi);
 float mean = 0;
 float stdDev = 0;
 cout << "input the mean for the normal distribution: ";
 cin >> mean;
 while (cin.fail() || mean < 0)
 {
  cin.clear();
  cin.ignore(RANGE_STRING, '\n');
  cout << "please enter positive integer mean again: " << endl;
  cin >> mean;
 }
 cout << "input the standard deviation for the normal \
distribution: ";
 cin >> stdDev;
 while (cin.fail() || stdDev < 0)
 {
  cin.clear();
  cin.ignore(RANGE_STRING, '\n');
  cout << "please enter positive integer standard \
deviation again: " << endl;
  cin >> stdDev;
 }
 float closedTime = 0;
 cout << "input the closing time of the restaurant: ";
 cin >> closedTime;
 while (cin.fail() || closedTime < 0)
 {
  cin.clear();
  cin.ignore(RANGE_STRING, '\n');
  cout << "please enter positive integer closing time \
again: " << endl;
  cin >> closedTime;
 }
 int closeTime = int(closedTime);
 float flength = 0;
 cout << "input the length of line that is considered long: ";
 cin >> flength;
 while (cin.fail() || flength < 0)
 {
  cin.clear();
  cin.ignore(RANGE_STRING, '\n');
  cout << "please enter positive integer length again: " << endl;
  cin >> flength;
 }
 int length = int(flength);
 float fpercentage = 0;
 cout << "input the percentage of customer that will leave \
if line is long: ";
 cin >> fpercentage;
 while (cin.fail() || fpercentage < 0 || fpercentage > 100)
 {
  cin.clear();
  cin.ignore(RANGE_STRING, '\n');
  cout << "please enter positive integer percentage in 0 \
and 100 again: " << endl;
  cin >> fpercentage;
 }
 int percentage = int(fpercentage);
 unifMin = min;
 unifMax = max;
 normMean = mean;
 normStdDev = stdDev;
 closingTime = closeTime;
 longLine = length;
 leavePercentage = percentage;
} // read the parameters from user
