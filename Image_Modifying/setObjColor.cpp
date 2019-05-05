//This file performs the setting color to object function.
//convert color string to color class
//Created by Xiaoxue Xin on 11/3/18.
//
#include <string>
#include "ColorClass.h"

using namespace std;

void setObjColor(ColorClass &colClas,
                 string color)
{
 if (color == "Red")
 {
  colClas.setToRed();
 }
 if (color == "Green")
 {
  colClas.setToGreen();
 }
 if (color == "Blue")
 {
  colClas.setToBlue();
 }
 if (color == "Black")
 {
  colClas.setToBlack();
 }
 if (color == "White")
 {
  colClas.setToWhite();
 }
}
