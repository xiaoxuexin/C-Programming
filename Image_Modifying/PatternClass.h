//This file is the pattern class header.
//
//Created by Xiaoxue Xin on 11/3/18.
//
#ifndef _PATTERNCLASS_H_
#define _PATTERNCLASS_H_
#include <fstream>
#include <string>
#include "ColorClass.h"
#include "RowColumnClass.h"
#include "ColorImageClass.h"

class PatternClass
{
private:
 RowColumnClass upperLeft;
 ColorClass patternColor;
 bool validNameFlag;//check whether exist the pattern
 bool errorFlag;//check whether there is error in pattern
 int pointValue;//0 or 1 in pattern
 int patternRow;
 int patternCol;
 int positionLen;
 int **patternTextPointer;
 string patternName;
 RowColumnClass *patternTextPosition;
public:
 PatternClass();
 bool buildImage(string insertedImageName);
 ~PatternClass();
 int getPositionLen();
 int getPatternRow();
 int getPatternCol();
 void setColor(string color);
 void setIndex(RowColumnClass &index);
 bool buildTextPattern(string patternName);
 RowColumnClass* getPatternPosition();
 ColorClass getColor();
 RowColumnClass getIndex();
};

# endif
