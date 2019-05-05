//  this is the
//  SimulationClass.h file in
//  project5
//
//  Created by xiaoxue xin on 12/1/18.
//

#ifndef SimulationClass_h
#define SimulationClass_h

#include <iostream>
#include "constant.h"
#include "random.h"
#include "EventClass.h"
#include "CustomerClass.h"
#include "SortedListClass.h"
#include "FIFOQueueClass.h"

class SimulationClass
{
private:
 int unifMin;
 int unifMax;
 double normMean;
 double normStdDev;
 int closingTime;
 // restaurant closing time
 int longLine;
 // length of line that is consedered long
 int leavePercentage;
 // percentage of customers that will leave
 int leaveCustNum;
 // total number of customers that leave due to long line
 int totalSevTime;
 // total service time of server
 int lastCustID;
 // ID of the last customer
 int endTime;
 // max of the last customer complete time and closing time
 int waitedCustNum;
 // total number of customers that have to wait in line
 int longestLine;
 // length of longest line
 int waitingTime;
 // time that each customer has to wait
 int waitedTooLongNum;
 // number of customers that have waited more than 10 units of time
 int longestWaitedTime;
 SortedListClass<EventClass> eventList;
 // event list
 FIFOQueueClass<CustomerClass> waitingQueue;
 // waiting queue of customers
public:
 SimulationClass();
 ~SimulationClass();
 void handleArrivalEvent(EventClass &arrEvent);
 void handleServiceCopmEvent(EventClass &compEvent);
 void simulateProcess();
 void outputStatistics();
 void readinput();
};

#endif
