//This file is the rectangle class header.
//
//Created by Xiaoxue Xin on 11/3/18.
//
#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_
#include <string>
#include "ColorClass.h"
#include "RowColumnClass.h"
#include "RectangleClass.h"

using namespace std;

class RectangleClass
{
private:
 RowColumnClass upperLeft;
 RowColumnClass lowerRight;
 int lengthOfRow;
 int lengthOfCol;
 ColorClass rectColor;
 bool fillOrNot;
 bool boundaryFlag;
 bool planeFlag;
 // if the rectangle is filled, the plane flag is true.
 RowColumnClass *boundaryPosition;
 // return the position of boundary of rectangle
 RowColumnClass *planePosition;
 // return the position of all points of filled rectangle
public:
 RectangleClass();
 RectangleClass(RowColumnClass &upLeft,
                RowColumnClass &lowRight,
                string color);//constructor
 ~RectangleClass();//destructor
 void setColor(string color);
 ColorClass getColor();
 int getLenRow();
 int getLenCol();
 RowColumnClass* getPlanePosition();
 //get the position of the filled rectangle
 RowColumnClass* getBoundaryPostion();
 //get the position of the boundary of rectangle
 int getBoundaryPositionLen();
 //get the length of boundary of rectangle
};

#endif
