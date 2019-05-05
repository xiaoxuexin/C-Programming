//  this is the
//  CustomerClass.h file in
//  project5
//
//  Created by xiaoxue xin on 12/2/18.
//

#ifndef CustomerClass_h
#define CustomerClass_h

#include <iostream>

using namespace std;

class CustomerClass
{
private:
 int customerID;
 int arrivalTime;
public:
 CustomerClass();
 CustomerClass(int custID,
               int arrTime);
 ~CustomerClass();
 int getCustId() const;
 int getArrTime() const;
};

ostream &operator<<(ostream &os,
                    const CustomerClass &rhs);

#endif 
