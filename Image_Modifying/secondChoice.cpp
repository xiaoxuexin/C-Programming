//This file is the second choice function.
//
//Created by Xiaoxue Xin on 11/3/18.
//
#include <iostream>
#include <string>
#include "constants.h"
#include "ColorImageClass.h"
#include "PatternClass.h"
#include "matchColor.h"
#include "annotateImageWithPat.h"

using namespace std;

bool secondChoice(ColorImageClass &Image)
{
 cout << "Enter string for file name containing pattern: ";
 string textName;
 cin >> textName;
 PatternClass patternFile;
 if (patternFile.buildTextPattern(textName) == 0)
 {
  cout << "there is an error." << endl;
  return 0;
 }
 cout << "Enter upper left corner of pattern row and column: ";
 int pattRow;
 int PattCol;
 cin >> pattRow;
 cin >> PattCol;
 RowColumnClass patInd(pattRow, PattCol);
 patternFile.setIndex(patInd);
 cout << "Enter int for pattern color: " << endl;
 int colorInd;
 cout << "1. Red" << endl
 << "2. Green" << endl
 << "3. Blue" << endl
 << "4. Black" << endl
 << "5. White" << endl
 << "Enter int for pattern color: ";
 string colorPattern;
 cin >> colorInd;
 while (cin.fail())
 {
  cin.clear();
  cin.ignore(RANGE_STRING, '\n');
  cout << "please enter again: " << endl;
  cin >> colorInd;
 }
 if ((colorInd < RED_INDEX) || (colorInd > WHITE_INDEX))
 {
  cout << "invalid input of color." << endl;
  return 0;
 }
 colorPattern = matchColor(colorInd);
 patternFile.setColor(colorPattern);
 annotateImageWithPat(patternFile, Image);
 return 1;
}

