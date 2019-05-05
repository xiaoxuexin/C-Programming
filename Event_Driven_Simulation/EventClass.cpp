//  this is the
//  EventClass.cpp file in
//  project5
//
//  Created by xiaoxue xin on 12/1/18.
//

#include "EventClass.h"
#include <iostream>

using namespace std;

EventClass:: EventClass()
{
}

EventClass:: EventClass(int custID,
                        int time,
                        int type)
{
 customerID = custID;
 eventTime = time;
 eventType = type;
} // constructor

EventClass:: ~EventClass()
{
}

int EventClass:: getTime() const
{
 return eventTime;
}

int EventClass:: getType() const
{
 return eventType;
}

int EventClass:: getCustomer() const
{
 return customerID;
}

bool EventClass:: operator>=(const EventClass &rhs) const
{
 return (eventTime >= rhs.eventTime);
}

ostream &operator<<(ostream &os,
                    const EventClass &rhs)
{
 if (rhs.getType() == 2)
 {
  os << "customer " << rhs.getCustomer() <<\
  " is being served, and service will complete at: "\
  << rhs.getTime() << endl;
 }
 return os;
}
