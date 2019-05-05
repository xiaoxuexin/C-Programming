//This file is the insert image function.
//
//Created by Xiaoxue Xin on 11/3/18.
//
#include <iostream>
#include <string>
#include "constants.h"
#include "RowColumnClass.h"
#include "ColorImageClass.h"
#include "NonTranspImageClass.h"
#include "matchColor.h"
#include "setObjColor.h"
#include "annotateImageWithImage.h"

using namespace std;

bool insertImage(ColorImageClass &image)
{
 cout << "Enter string for file name of PPM image to insert: ";
 string insertedFile;
 cin >> insertedFile;
 NonTranspImageClass insertedImage;
 bool validFlag;
 validFlag = insertedImage.buildInsertedImage(insertedFile);
 if (!validFlag)
 {
  cout << "there is an error with inserted image file." << endl;
  return 0;
 }
 cout << "Enter upper left corner to insert image row and column: ";
 int upLeftRow;
 int upLeftCol;
 cin >> upLeftRow;
 cin >> upLeftCol;
 RowColumnClass imageInd(upLeftRow, upLeftCol);
 insertedImage.setIndex(imageInd);
 int transColorNum;
 cout << "1. Red" << endl
 << "2. Green" << endl
 << "3. Blue" << endl
 << "4. Black" << endl
 << "5. White" << endl
 << "Enter int for transparecy color: ";
 cin >> transColorNum;
 while (cin.fail())
 {
  cin.clear();
  cin.ignore(RANGE_STRING, '\n');
  cout << "please enter again: " << endl;
  cin >> transColorNum;
 }
 if ((transColorNum < 1) || (transColorNum > 5))
 {
  cout << "invalid input of color." << endl;
  return 0;
 }
 string transpColor;
 ColorClass trColor;
 transpColor = matchColor(transColorNum);
 //convert string to color class object
 setObjColor(trColor, transpColor);
 //set color object to the nontranspclass object
 insertedImage.setTranColor(trColor);
 insertedImage.setPositionLen(insertedImage.setPosiLength(trColor));
 annotateImageWithImage(insertedImage, image);
 return 1;
};
