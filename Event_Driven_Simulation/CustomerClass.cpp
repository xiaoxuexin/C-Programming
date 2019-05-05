//  this is the
//  CustomerClass.cpp file in
//  project5
//
//  Created by xiaoxue xin on 12/2/18.
//

#include "CustomerClass.h"
#include <iostream>

CustomerClass:: CustomerClass()
{
}

CustomerClass:: CustomerClass(int custID,
                              int arrTime)
{
 customerID = custID;
 arrivalTime = arrTime;
}

CustomerClass:: ~CustomerClass()
{
}

int CustomerClass:: getCustId() const
{
 return customerID;
}

int CustomerClass:: getArrTime() const
{
 return arrivalTime;
}

ostream &operator<<(ostream &os,
                    const CustomerClass &rhs)
{
 os << "customer ID: " << rhs.getCustId() \
 << " arrival time: " << rhs.getArrTime() << endl;
 return os;
}
