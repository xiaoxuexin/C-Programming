//This file is the show image function.
//
//Created by Xiaoxue Xin on 11/3/18.
//
#include "iostream"
#include "constants.h"
#include "outputMenu.h"
#include "ColorImageClass.h"

using namespace std;

int showImage(ColorImageClass &imageFile)//show image
{
 int menuChoice;
 outputMenu();
 cin >> menuChoice;
 while (cin.fail())
 {
  cin.clear();
  cin.ignore(RANGE_STRING, '\n');
  cout << "the input is invalid." << endl;
  outputMenu();
  cin >> menuChoice;
 }
 if (menuChoice == FORTH_CHOICE)
 {
  imageFile.writeFile();;
 }
 return menuChoice;
}
