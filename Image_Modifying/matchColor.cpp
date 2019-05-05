//This file is the matching color
//index and string function.
//Created by Xiaoxue Xin on 11/3/18.
//
#include <string>
#include "constants.h"

using namespace std;

string matchColor(int ind)
{
 string color;
 if (ind == RED_INDEX)
 {
  color = "Red";
 }
 else if (ind == GREEN_INDEX)
 {
  color = "Green";
 }
 else if (ind == BLUE_INDEX)
 {
  color = "Blue";
 }
 else if (ind == BLACK_INDEX)
 {
  color = "Black";
 }
 else if (ind == WHITE_INDEX)
 {
  color = "White";
 }
 else
 {
  string err= "the color is out of range.";
  return err;
 }
 return color;
}

