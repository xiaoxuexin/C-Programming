//  this file is NonTranspImageClass
//  that return the position information
//  and color class of every pixel of
//  nontransparent points
//  Created by Xiaoxue Xin on 11/13/18.
//

#include <iostream>
#include <string>
#include <fstream>
#include "constants.h"
#include "ColorClass.h"
#include "RowColumnClass.h"
#include "ColorImageClass.h"
#include "RectangleClass.h"
#include "NonTranspImageClass.h"
#include "setObjColor.h"

using namespace std;

NonTranspImageClass:: NonTranspImageClass()
{
 nameFlag = true;//name is valid
 errorFlag = false;//no error in initiallization
 positionLen = 0;//null pointer
 patternImagePointer = 0;//null pointer
 imagePositionInfo = 0;//null pointer
}
bool NonTranspImageClass:: buildInsertedImage(string insertedImageName)
//build the inserted image
{
 ifstream inFile;
 patternName = insertedImageName;
 inFile.open(patternName.c_str());
 if (inFile.fail())
 {
  inFile.clear();
  inFile.ignore(RANGE_STRING, '\n');
  nameFlag = false;//invalid name
  cout << "unable to open inserted image" << endl;
  return 0;
 }//if the input name is invalid, there is error handling
 inFile >> patternType;
 if (patternType != "P3")
 {
  cout << "the type of the image is wrong." << endl;
  errorFlag = true;//record error
  return 0;
 }
 inFile >> patternImaCol;
 if (patternImaCol < 0)
 {
  cout << "the image column should be positive." << endl;
  errorFlag = true;
  return 0;
 }
 inFile >> patternImaRow;
 if (patternImaRow < 0)
 {
  cout << "the image row should be positive." << endl;
  errorFlag = true;
  return 0;
 }
 inFile >> patternColorMax;
 patternImagePointer = new ColorClass *[patternImaRow];
 for (int i = 0; i < patternImaRow; i++)
 {
  patternImagePointer[i] = new ColorClass[patternImaCol];
 }
 for (int i = 0; i < patternImaRow; i++)
 {
  for (int j = 0; j < patternImaCol; j++)
  {
   bool pixelFlag;
   pixelFlag = patternImagePointer[i][j].
               setColorFromFile(inFile, patternColorMax);
   if (!pixelFlag)
   {
    errorFlag = true;
    return 0;
   }
   if ((inFile.eof()) &&
       ((i * patternImaRow + j) <
        (patternImaRow * patternImaCol - 1)))
   {
    cout << "the number of pixel is smaller than ";
    cout << "product of row and column." << endl;
    errorFlag = true;//record error
    return 0;
   }//error handling of mismatch of numbers
  }
 }
 string test;
 inFile >> test;
 if (!test.empty())
 {
  cout << "the number of pixel is larger than ";
  cout << "product of row and column." << endl;
  errorFlag = true;//record error
  return 0;
 }//error handling of mismatch of number
 inFile.close();
 return 1;
}
NonTranspImageClass:: ~NonTranspImageClass()
{
 if (nameFlag)//if there is no such file, no pointer will be build
 {
  if (errorFlag == false)
  {
   delete [] imagePositionInfo;
   imagePositionInfo = 0;
  }
  for (int i = 0; i < patternImaRow; i++)
  {
   delete[] patternImagePointer[i];
   patternImagePointer[i] = 0;
  }
  delete[] patternImagePointer;
  patternImagePointer = 0;
 }
}//destructor
void NonTranspImageClass:: setPositionLen(int len)
{
 positionLen = len;
}
int NonTranspImageClass:: getPositionLen()
{
 return positionLen;
}//get length
int NonTranspImageClass:: getInsertedImaRow()
{
 return patternImaRow;
}//get the row
int NonTranspImageClass:: getInsertedImaCol()
{
 return patternImaCol;
}//get the column
void NonTranspImageClass:: setIndex(RowColumnClass &index)
{
 upperLeft.setRow(index.getRow());
 upperLeft.setCol(index.getCol());
}
int NonTranspImageClass:: setPosiLength(ColorClass &tranColor)
{
 for (int i = 0; i < patternImaRow; i++)
 {
  for (int j = 0; j < patternImaCol; j++)
  {
   if (!patternImagePointer[i][j].checkEqualColor(tranColor))
   {
    positionLen = positionLen + 1;
    //calculate the length of dynamic allocation
   }
  }
 }
 return positionLen;
}
ColorImageClass* NonTranspImageClass:: getPositionInfo()
//get position, i.e. rowcolumnclass, and color of inserted image,
//i.e. colorclass, in this function
//that have deducted the transparent color
{
 imagePositionInfo = new ColorImageClass[positionLen];
 int index = 0;
 bool flagVar = false;
 for (int i = 0; i < patternImaRow; i++)
 {
  for (int j = 0; j < patternImaCol; j++)
  {
   flagVar = patternImagePointer[i][j].checkEqualColor(tranColor);
   if (!flagVar)//not the transparent color
   {
    imagePositionInfo[index].setIndexIma(i + upperLeft.getRow(),
                                         j + upperLeft.getCol());
    imagePositionInfo[index].setColorIma
               (patternImagePointer[i][j].getRed(),
                patternImagePointer[i][j].getGreen(),
                patternImagePointer[i][j].getBlue());
    index = index + 1;
   }//record the coordinates and color of nontransparent pixel
  }
 }
 return imagePositionInfo;
}
void NonTranspImageClass:: setTranColor(ColorClass &transparentColor)
{
 tranColor.setTo(transparentColor);
}
