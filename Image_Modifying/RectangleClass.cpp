//This file is the rectangle class.
//
//Created by Xiaoxue Xin on 11/3/18.
//
#include <iostream>
#include "constants.h"
#include "ColorClass.h"
#include "RowColumnClass.h"
#include "RectangleClass.h"
#include "setObjColor.h"

using namespace std;

RectangleClass:: RectangleClass()
{
 lengthOfRow = 0;
 lengthOfCol = 0;
 fillOrNot = false;
 boundaryFlag = false;
 planeFlag = false; 
}
RectangleClass:: RectangleClass(RowColumnClass &upLeft,
                                RowColumnClass &lowRight,
                                string color)
{
 boundaryPosition = 0;
 planePosition = 0;
 setColor(color);
 upperLeft.setRowCol(upLeft.getRow(),
                     upLeft.getCol());
 lowerRight.setRowCol(lowRight.getRow(),
                      lowRight.getCol());
}
RectangleClass:: ~RectangleClass()
{
 if (planeFlag == true)
 {
  delete [] planePosition;
 }
 if (boundaryFlag == true)
 {
  delete [] boundaryPosition;
 }
}
int RectangleClass:: getLenRow()
{
 lengthOfRow = lowerRight.getRow() - upperLeft.getRow() + 1;
 return lengthOfRow;
}
int RectangleClass:: getLenCol()
{
 lengthOfCol = lowerRight.getCol() - upperLeft.getCol() + 1;
 return lengthOfCol;
}
void RectangleClass:: setColor(string color)
{
 setObjColor(rectColor, color);
}
ColorClass RectangleClass:: getColor()
{
 return rectColor;
}
RowColumnClass* RectangleClass:: getPlanePosition()
{
 planeFlag = true;
 lengthOfRow = getLenRow();
 lengthOfCol = getLenCol();
 int len = lengthOfRow * lengthOfCol;
 planePosition = new RowColumnClass[len];
 int k = 0;
 for (int i = upperLeft.getRow(); i < lowerRight.getRow() + 1; i++)
 {
  for (int j = upperLeft.getCol(); j < lowerRight.getCol() + 1; j++)
  {
   planePosition[k].setRowCol(i, j);
   k++;
  }
 }
 return planePosition;
}
RowColumnClass* RectangleClass:: getBoundaryPostion()
{
 boundaryFlag = true;
 int len = getBoundaryPositionLen();
 boundaryPosition = new RowColumnClass[len];
 int i = 0;
 for (int c = upperLeft.getCol(); c < lowerRight.getCol() + 1; c++)
 {
  boundaryPosition[i].setRowCol(upperLeft.getRow(), c);
  boundaryPosition[i + 1].setRowCol(lowerRight.getRow(), c);
  i = i + 2;
 }
 for (int c = upperLeft.getRow() + 1; c < lowerRight.getRow(); c++)
 {
  boundaryPosition[i].setRowCol(c, upperLeft.getCol());
  boundaryPosition[i + 1].setRowCol(c, lowerRight.getCol());
  i = i + 2;
 }
 return boundaryPosition;
}
int RectangleClass:: getBoundaryPositionLen()
{
 return 2 * (lowerRight.getCol() - upperLeft.getCol() +
             lowerRight.getRow() - upperLeft.getRow());
}


