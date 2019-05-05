//  this is header file of NonTranspImageClass
//
//  Created by Xiaoxue Xin on 11/13/18.
//
#ifndef _NONTRANSPIMAGECLASS_H_
#define _NONTRANSPIMAGECLASS_H_
#include <fstream>
#include <string>
#include "ColorClass.h"
#include "RowColumnClass.h"
#include "ColorImageClass.h"

class NonTranspImageClass
{
private:
 ColorClass tranColor;//transparent color
 RowColumnClass upperLeft;//up left position
 int patternColorMax;
 int patternImaRow;
 int patternImaCol;
 int positionLen;
 string patternName;
 string patternType;
 bool nameFlag;//record whether the name is valid
 bool errorFlag;//record whether there is an error
 ColorClass **patternImagePointer;
//read the image information
 ColorImageClass *imagePositionInfo;
//get the information of nontransparent points
public:
 NonTranspImageClass();
 bool buildInsertedImage(string insertedImageName);
 ~NonTranspImageClass();
 void setPositionLen(int len);
 int getPositionLen();
 int getInsertedImaRow();
 int getInsertedImaCol();
 int setPosiLength(ColorClass &transColor);
 void setIndex(RowColumnClass &index);
 void setTranColor(ColorClass &transparentColor);
 ColorImageClass* getPositionInfo();
 RowColumnClass getIndex();
};

#endif
