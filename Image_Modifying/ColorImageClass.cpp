//This file is the color image class.
//
//Created by Xiaoxue Xin on 11/3/18.
//
#include <iostream>
#include <fstream>
#include <string>
#include "constants.h"
#include "ColorClass.h"
#include "RowColumnClass.h"
#include "ColorImageClass.h"

using namespace std;

ColorImageClass:: ColorImageClass()
{
}
ColorImageClass:: ColorImageClass(string fileName)
{
 flagVar = true;
 colorImagePointer = 0;
 if (buildColorImage(fileName) == 0)
 {
  cout << "there is an error..." << endl;
 }
}
ColorImageClass:: ~ColorImageClass()
{
 if (flagVar == true)
 {
  for (int i = 0; i < numOfRow; i++)
  {
   delete[] colorImagePointer[i];
   colorImagePointer[i] = 0;
  }
  delete[] colorImagePointer;
  colorImagePointer = 0;
 }
}
//functions in ColorImageClass
void ColorImageClass:: setColorIma(int inRed,
                                   int inGreen,
                                   int inBlue)
{
 colorForIma.setTo(inRed, inGreen, inBlue);
}
void ColorImageClass:: setIndexIma(int row,
                                   int col)
{
 indexForIma.setRowCol(row, col);
}
void ColorImageClass:: setRow(int row)
{
 numOfRow = row;
}
void ColorImageClass:: setCol(int col)
{
 numOfCol = col;
}
ColorClass ColorImageClass:: getColor()
{
 return colorForIma;
}
RowColumnClass ColorImageClass:: getIndex()
{
 return indexForIma;
}
int ColorImageClass:: getRow()
{
 return this -> numOfRow;
}
int ColorImageClass:: getColumn()
{
 return this -> numOfCol;
}

bool ColorImageClass:: getFlagVar()
{
 return this -> flagVar;
}
bool ColorImageClass:: buildColorImage(string fileName)
{
 int numOfPoint = 0;
 ifstream inFile;
 nameOfFile = fileName;
 inFile.open(nameOfFile.c_str());
 if (inFile.fail())
 {
  inFile.clear();
  inFile.ignore(RANGE_STRING, '\n');
  flagVar = false;
  cout << "no such file in current document." << endl;
  return 0;
 }
 inFile >> imageType;
 if (imageType != "P3")
 {
  cout << "The type of the image is wrong." << endl;
  flagVar = false;
  return 0;
 }
 inFile >> numOfCol;
 inFile >> numOfRow;
 inFile >> colorMax;
 colorImagePointer = new ColorClass *[numOfRow];
 for (int i = 0; i < numOfRow; i++)
 {
  colorImagePointer[i] = new ColorClass[numOfCol];
 }
 for (int i = 0; i < numOfRow; i++)
 {
  for (int j = 0; j < numOfCol; j++)
  {
   bool pixelFlag;
   pixelFlag = colorImagePointer[i][j].setColorFromFile(inFile, colorMax);
   if (!pixelFlag)
   {
    cout << "there is something wrong with pixel." << endl;
    flagVar = false;
    return 0;
   }
   if ((inFile.eof()) &&
       ((i * numOfRow + j) < (numOfRow * numOfCol - 1)))
   {
    cout << "the number of pixel is smaller than ";
    cout << "product of row and column." << endl;
    flagVar = false;
    return 0;
   }// error handling
   numOfPoint = numOfPoint + 1;
  }
 }
 string test;
 inFile >> test;
 if (!test.empty())
 {
  flagVar = false;
  cout << "the number of pixel is larger than ";
  cout << "product of row and column." << endl;
  return 0;
 }//error handling
 inFile.close();
 return 1;
}
ColorClass** ColorImageClass:: getPointer()
{
 return colorImagePointer;
}
bool ColorImageClass:: setColorAtLocation(RowColumnClass &inRowCol,
                                          ColorClass &inColor)
{
 if (testInRange(inRowCol))
 {
  colorImagePointer[inRowCol.getRow()]
  [inRowCol.getCol()].setTo(inColor);
  return 1;
 }
 return 0;
}
bool ColorImageClass:: testInRange(RowColumnClass &inRowCol)
{
 if (inRowCol.getRow() >= 0 &&
     inRowCol.getRow() < numOfRow &&
     inRowCol.getCol() >= 0 &&
     inRowCol.getCol() < numOfCol)
 {
  return true;
 }
 else
 {
  return false;
 }
}
bool ColorImageClass:: writeFile()
{
 ofstream outFile;
 cout << "Enter string for PPM file name to output: ";
 cin >> newFile;
 outFile.open(newFile.c_str());
 if (outFile.fail())
 {
  outFile.clear();
  cout << "unable to open the file" << endl;
  return 0;
 }
 outFile << imageType << endl;
 outFile << numOfCol;
 outFile << ' ';
 outFile << numOfRow << endl;
 outFile << colorMax << endl;
 for (int i = 0; i < numOfRow; i++)
 {
  for (int j = 0; j < numOfCol; j++)
  {
   outFile << colorImagePointer[i][j].getRed() << ' ';
   outFile << colorImagePointer[i][j].getGreen() << ' ';
   outFile << colorImagePointer[i][j].getBlue()<< ' ';
  }
  if (i != numOfCol - 1)
  {
   outFile << '\n';
  }
 }
 outFile.close();
 return 1;
}
