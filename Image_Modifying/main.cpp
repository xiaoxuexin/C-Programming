//This file is the main function.
//
//Created by Xiaoxue Xin on 11/3/18.
//
#include <iostream>
#include <fstream>
#include <string>
#include "ColorImageClass.h"
#include "chooseFromMenu.h"

using namespace std;

int main()
{
 cout << "Enter string for PPM image file name to load: ";
 string nameOfFile;
 cin >> nameOfFile;
 ColorImageClass imageFile(nameOfFile);//read image
 if (imageFile.getFlagVar() == false)//error handling
 {
  return 0;
 }
 chooseFromMenu(imageFile);//make choice
 return 0;
}
