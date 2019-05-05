//This file is a function that
//the user can choose what they want to do
//Created by Xiaoxue Xin on 11/3/18.
//
#include <string>
#include "iostream"
#include "constants.h"
#include "ColorImageClass.h"
#include "outputMenu.h"
#include "firstChoice.h"
#include "secondChoice.h"
#include "insertImage.h"
#include "showImage.h"

using namespace std;

//make a choice from menu
bool chooseFromMenu(ColorImageClass &imageFile)
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
 while (menuChoice != EXIT_CHOICE)
 {
  if (menuChoice == FIRST_CHOICE)//choose 1 choice
  {
   firstChoice(imageFile);
   menuChoice = showImage(imageFile);
  }
  else if (menuChoice == SECOND_CHOICE)//choose 2 choice
  {
   secondChoice(imageFile);
   menuChoice = showImage(imageFile);
  }
  else if (menuChoice == THIRD_CHOICE)//choose 3 choice
  {
   insertImage(imageFile);
   menuChoice = showImage(imageFile);
  }
  else if (menuChoice == FORTH_CHOICE)//show the image
  {
   outputMenu();
   cin >> menuChoice;
  }
  else//other situation
  {
   cout << "The input is invalid." << endl;
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
  }
 }
  cout << "Thank you for using this program" << endl;
  return 1;
}

