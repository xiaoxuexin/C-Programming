//This file is the color image class header.
//
//Created by Xiaoxue Xin on 11/3/18.
//
#ifndef _COLORIMAGECLASS_H_
#define _COLORIMAGECLASS_H_
#include <string>
#include "ColorClass.h"
#include "RowColumnClass.h"
#include "ColorImageClass.h"

using namespace std;

// class ColorImageClass
class ColorImageClass
{
private:
 int colorMax;
 int numOfRow;
 int numOfCol;
 bool flagVar;
 ColorClass colorForIma;
 RowColumnClass indexForIma;
 string nameOfFile;
 string newFile;
 string imageType;
 ColorClass **colorImagePointer;
public:
 ColorImageClass();//default constructor
 ColorImageClass(string fileName);//constructor
 ~ColorImageClass();//destructor
 void setColorIma(int inRed, int inGreen, int inBlue);
 void setIndexIma(int row, int col);
 ColorClass getColor();
 RowColumnClass getIndex();
 void setRow(int row);
 void setCol(int col);
 int getRow();
 int getColumn();
 bool getFlagVar();
 bool buildColorImage(string fileName);
 ColorClass** getPointer();
 bool setColorAtLocation(RowColumnClass &inRowCol,
                         ColorClass &inColor);
 //set color at given location
 bool writeFile();
private:
 bool testInRange(RowColumnClass &inRowCol);
};

#endif
