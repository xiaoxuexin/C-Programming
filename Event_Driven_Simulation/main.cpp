//  this file is the
//  main.cpp in
//  project5
//
//  Created by xiaoxue xin on 12/1/18.
//

#include <iostream>
#include "constant.h"
#include "EventClass.h"
#include "CustomerClass.h"
#include "LinkedNodeClass.h"
#include "SortedListClass.h"
#include "FIFOQueueClass.h"
#include "SimulationClass.h"

using namespace std;

int main()
{
 srand(1); // set seed
 SimulationClass simu; // simu is a simulation object
 simu.readinput(); // read data from user
 simu.simulateProcess(); // simulate the process
 simu.outputStatistics(); // output the statistical result
 return 0;
}
