//This file is the pattern class.
//
//Created by Xiaoxue Xin on 11/3/18.
//
#include <iostream>
#include <string>
#include <fstream>
#include "constants.h"
#include "PatternClass.h"
#include "setObjColor.h"

using namespace std;

PatternClass:: PatternClass()//constructor
{
 validNameFlag = true;
 errorFlag = false;
 positionLen = 0;
 patternTextPosition = 0;
 patternTextPointer = 0;
}
PatternClass:: ~PatternClass()//destructor
{
 if (validNameFlag)
 {
  if (errorFlag == false)
  {
   delete [] patternTextPosition;
   patternTextPosition = 0;
  }
  for (int i = 0; i < patternRow; i++)
  {
   delete[] patternTextPointer[i];
   patternTextPointer[i] = 0;
  }
  delete[] patternTextPointer;
  patternTextPointer = 0;
 } 
}
int PatternClass:: getPatternRow()
{
 return this -> patternRow;
}
int PatternClass:: getPatternCol()
{
 return this -> patternCol;
}
bool PatternClass:: buildTextPattern(string pattName)
//build the pattern text file
{
 ifstream inFile;
 patternName = pattName;
 inFile.open(patternName.c_str());
 if (inFile.fail())
 {
  inFile.clear();
  inFile.ignore(RANGE_STRING, '\n');
  cout << "there is no file with such name." << endl;
  validNameFlag = false;
  return 0;
 }//error handling of failing to open the file
 inFile >> patternCol;
 if (patternCol < 0)
 {
  cout << "the column is negative." << endl;
  errorFlag = true;
  return 0;
 }
 inFile >> patternRow;
 if (patternRow < 0) {
  cout << "the row is negative." << endl;
  errorFlag = true;
  return 0;
 }
 patternTextPointer = new int *[patternRow];
 for (int i = 0; i < patternRow; i++)
 {
  patternTextPointer[i] = new int[patternCol];
 }
 for (int i = 0; i < patternRow; i++)
 {
  for (int j = 0; j < patternCol; j++)
  {
   inFile >> pointValue;
   if ((inFile.eof()) &&
       ((i * patternRow + j) < (patternRow * patternCol - 1)))
   {
    cout << "the number of elements is smaller than ";
    cout << "product of row and column." << endl;
    errorFlag = true;
    return 0;
   }// error handling
   patternTextPointer[i][j] = pointValue;
   if (pointValue == 1)
   {
    positionLen = positionLen + 1;
   }
  }
 }
 string test;
 inFile >> test;
 if (!test.empty())
 {
  errorFlag = true;
  cout << "the number of elements is larger than ";
  cout << "product of row and column." << endl;
  return 0;
 }//error handling
 inFile.close();
 return 1;
}
RowColumnClass* PatternClass:: getPatternPosition()
//get an array consists of coordinates of pattern position
{
 patternTextPosition = new RowColumnClass[positionLen];
 int index = 0;
 for (int i = upperLeft.getRow(); i < upperLeft.getRow()
      + patternRow; i++)
 {
  for (int j = upperLeft.getCol(); j < upperLeft.getCol()
       + patternCol; j++)
  {
   if (patternTextPointer[i - upperLeft.getRow()]
       [j - upperLeft.getCol()] == 1)
   {
    patternTextPosition[index].setRowCol(i, j);
    index = index + 1;
   }
  }
 }
 return patternTextPosition;
}
int PatternClass:: getPositionLen()
{
 return positionLen;
}
void PatternClass:: setColor(string color)
{
 setObjColor(patternColor, color);
}
ColorClass PatternClass:: getColor()
{
 return patternColor;
}
void PatternClass:: setIndex(RowColumnClass &index)
{
 upperLeft.setRow(index.getRow());
 upperLeft.setCol(index.getCol());
}
RowColumnClass PatternClass:: getIndex()
{
 return upperLeft;
}

