//This file is the first choice function.
//the user may choose annotate image with rectangle
//Created by Xiaoxue Xin on 11/3/18.
//
#include <iostream>
#include "constants.h"
#include "RowColumnClass.h"
#include "ColorImageClass.h"
#include "checkNumValid.h"
#include "matchColor.h"
#include "RectangleClass.h"
#include "annotateImageWithRec.h"

using namespace std;

bool firstChoice(ColorImageClass &Image)
{
 int rectIndex = 0;
 cout << "1. Specify upper left and lower ";
 cout << "right corners of rectangle" << endl
 << "2. Specify upper left corner and dimensions of rectangle" << endl
 << "3. Specify extent from center of rectangle" << endl
 << "Enter int for rectangle specification method:";
 cin >> rectIndex;
 while (cin.fail())
 {
  cin.clear();
  cin.ignore(RANGE_STRING, '\n');
  cout << "please enter again: " << endl;
  cin >> rectIndex;
 }
 int upLeftRow = 0;//variable initiallization
 int upLeftCol = 0;
 int lowRightRow = 0;
 int lowRightCol = 0;
 int validIndex[4];
 if (rectIndex == RECT_INDEX_FIRST)//first choice
 {
  cout << "Enter upper left corner row and column: ";
  cin >> upLeftRow;
  cin >> upLeftCol;
  cout << "Enter lower right corner row and column: ";
  cin >> lowRightRow;
  cin >> lowRightCol;
  validIndex[0] = upLeftRow;
  validIndex[1] = upLeftCol;
  validIndex[2] = lowRightRow;
  validIndex[3] = lowRightCol;
  //check whether the coordinates are valid
  upLeftRow = checkNumValid(Image, validIndex)[0];
  upLeftCol = checkNumValid(Image, validIndex)[1];
  lowRightRow = checkNumValid(Image, validIndex)[2];
  lowRightCol = checkNumValid(Image, validIndex)[3];
 }
 else if (rectIndex == RECT_INDEX_SECOND)//second chlice
 {
  cout << "Enter upper left corner row and column: ";
  cin >> upLeftRow;
  cin >> upLeftCol;
  int numRow;
  cout << "Enter int for number of rows: ";
  cin >> numRow;
  int numCol;
  cout << "Enter int for number of columns: ";
  cin >> numCol;
  lowRightRow = upLeftRow + numRow;
  lowRightCol = upLeftCol + numCol;
  validIndex[0] = upLeftRow;
  validIndex[1] = upLeftCol;
  validIndex[2] = lowRightRow;
  validIndex[3] = lowRightCol;
  upLeftRow = checkNumValid(Image, validIndex)[0];
  upLeftCol = checkNumValid(Image, validIndex)[1];
  lowRightRow = checkNumValid(Image, validIndex)[2];
  lowRightCol = checkNumValid(Image, validIndex)[3];
  //check whether the coordinates are valid
 }
 else if (rectIndex == RECT_INDEX_THIRD)//third choice
 {
  int centerRow;
  int centerCol;
  cout << "Enter rectangle center row and column: ";
  cin >> centerRow;
  cin >> centerCol;
  int halfRow;
  int halfCol;
  cout << "Enter int for half number of rows: ";
  cin >> halfRow;
  cout << "Enter int for half number of columns: ";
  cin >> halfCol;
  upLeftRow = centerRow - halfRow;
  upLeftCol = centerCol - halfCol;
  lowRightRow = centerRow + halfRow;
  lowRightCol = centerCol + halfCol;
  validIndex[0] = upLeftRow;
  validIndex[1] = upLeftCol;
  validIndex[2] = lowRightRow;
  validIndex[3] = lowRightCol;
  upLeftRow = checkNumValid(Image, validIndex)[0];
  upLeftCol = checkNumValid(Image, validIndex)[1];
  lowRightRow = checkNumValid(Image, validIndex)[2];
  lowRightCol = checkNumValid(Image, validIndex)[3];
 }
 else
 {
  cout << "Invalid input of rectangle specification method." << endl;
  return 0;
 }
 if ((upLeftRow > lowRightRow - 1) || (upLeftCol > lowRightCol - 1))
 {
  cout << "the upleft point and lowright point are invalid." << endl;
  return 0;
 }
 RowColumnClass rectupleft(upLeftRow, upLeftCol);
 RowColumnClass rectlowright(lowRightRow, lowRightCol);
 int colorIndex;
 string color;
 cout << "1. Red" << endl
 << "2. Green" << endl
 << "3. Blue" << endl
 << "4. Black" << endl
 << "5. White" << endl
 << "Enter int for rectangle color: ";
 cin >> colorIndex;//choose color of rectangle
 while (cin.fail())
 {
  cin.clear();
  cin.ignore(RANGE_STRING, '\n');
  cout << "please enter again: " << endl;
  cin >> colorIndex;
 }
 if ((colorIndex < 1) || (colorIndex > 5))
 {
  cout << "invalid input of color." << endl;
  return 0;
 }//invalid input color error
 color = matchColor(colorIndex);
 bool fillOrNot;
 int fillIndex = 0;
 cout << "1. No" << endl
 << "2. Yes" << endl
 << "Enter int for rectangle fill option: ";
 cin >> fillIndex;
 while (cin.fail())
 {
  cin.clear();
  cin.ignore(RANGE_STRING, '\n');
  cout << "please enter again: " << endl;
  cin >> fillIndex;
 }
 if (fillIndex == NOT_FILL_RECT)
 {
  fillOrNot = false;
 }
 else if (fillIndex == FILL_RECT)
 {
  fillOrNot = true;
 }//whether the rectangle is filled or not
 else
 {
  cout << "This is invalid input of fill or not." << endl;
  return 0;
 }
 RectangleClass rectg(rectupleft, rectlowright, color);
 annotateImageWithRec(rectg, Image, fillOrNot);
 return 1;
}
