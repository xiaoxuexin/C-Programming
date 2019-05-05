//  this file is the
//  EventClass.h in
//  project5
//
//  Created by xiaoxue xin on 12/1/18.
//

#ifndef EventClass_h
#define EventClass_h

#include <iostream>

using namespace std;

class EventClass
{
private:
 int eventType;
 int eventTime;
 int customerID;
public:
 EventClass();
 EventClass(int custID,
            int time,
            int type);
 ~EventClass();
 int getCustomer() const;
 int getType() const;
 int getTime() const;
 bool operator>=(const EventClass &rhs) const;
};

ostream &operator<<(ostream &os,
                    const EventClass &rhs);

#endif
