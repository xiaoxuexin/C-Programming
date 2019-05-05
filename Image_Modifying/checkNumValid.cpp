//This file is the valid number checking function.
//
//Created by Xiaoxue Xin on 11/3/18.
//
#include "ColorImageClass.h"

int* checkNumValid(ColorImageClass &image, int *validIndex)
//check the location of the rectangle
//and modify if the inputs are invalid
{
 int upLeftRow = validIndex[0];
 int upLeftCol = validIndex[1];
 int lowRightRow = validIndex[2];
 int lowRightCol = validIndex[3];
 if (upLeftRow < 0)
 {
  upLeftRow = 0;
 }
 if (upLeftRow > image.getRow() - 3)
 {
  upLeftRow = image.getRow() - 3;
 }
 validIndex[0] = upLeftRow;
 if (upLeftCol < 0)
 {
  upLeftCol = 0;
 }
 if (upLeftCol > image.getColumn() - 3)
 {
  upLeftCol = image.getColumn() - 3;
 }
 validIndex[1] = upLeftCol;
 if (lowRightRow < 2)
 {
  lowRightRow = 2;
 }
 if (lowRightRow > image.getRow() - 1)
 {
  lowRightRow = image.getRow() - 1;
 }
 validIndex[2] = lowRightRow;
 if (lowRightCol < 2)
 {
  lowRightCol = 2;
 }
 if (lowRightCol > image.getColumn() - 1)
 {
  lowRightCol = image.getColumn() - 1;
 }
 validIndex[3] = lowRightCol;
 return validIndex;
}
