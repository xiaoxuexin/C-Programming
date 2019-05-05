//This file is the color class.
//
//Created by Xiaoxue Xin on 11/3/18.
//
#include <iostream>
#include "constants.h"
#include "ColorClass.h"

using namespace std;

//constructor to initialize for ColorClass
ColorClass:: ColorClass()
{
 amountOfRed = MAX_COLOR;
 amountOfGreen = MAX_COLOR;
 amountOfBlue = MAX_COLOR;
}
//self-define constructor and clip invalid value
ColorClass:: ColorClass(int inRed,
                        int inGreen,
                        int inBlue)
{
 setInRange(inRed);
 amountOfRed = inRed;
 setInRange(inGreen);
 amountOfGreen = inGreen;
 setInRange(inBlue);
 amountOfBlue = inBlue;
}
//functions in ColorClass class
void ColorClass:: setToBlack()
{
 amountOfRed = MIN_COLOR;
 amountOfGreen = MIN_COLOR;
 amountOfBlue = MIN_COLOR;
}
void ColorClass:: setToRed()
{
 amountOfRed = MAX_COLOR;
 amountOfBlue = MIN_COLOR;
 amountOfGreen = MIN_COLOR;
}
void ColorClass:: setToGreen()
{
 amountOfRed = MIN_COLOR;
 amountOfBlue = MIN_COLOR;
 amountOfGreen = MAX_COLOR;
}
void ColorClass:: setToBlue()
{
 amountOfRed = MIN_COLOR;
 amountOfBlue = MAX_COLOR;
 amountOfGreen = MIN_COLOR;
}
void ColorClass:: setToWhite()
{
 amountOfRed = MAX_COLOR;
 amountOfBlue = MAX_COLOR;
 amountOfGreen = MAX_COLOR;
}
bool ColorClass:: setInRange(int &amountColor)
{
 if (amountColor < MIN_COLOR)
 {
  amountColor = MIN_COLOR;
  return 1;
 }
 else if (amountColor > MAX_COLOR)
 {
  amountColor = MAX_COLOR;
  return 1;
 }
 else
 {
  return 0;
 }
}
bool ColorClass:: setTo(int inRed,
                        int inGreen,
                        int inBlue)
{
 bool redOutRange = setInRange(inRed);
 bool greenOutRange = setInRange(inGreen);
 bool blueOutRange = setInRange(inBlue);
 amountOfRed = inRed;
 amountOfGreen = inGreen;
 amountOfBlue = inBlue;
 if (!redOutRange && !greenOutRange && !blueOutRange)
 {
  return 0;
 }
 else
 {
  return 1;
 }
}
bool ColorClass:: setTo(ColorClass &inColor)
{
 amountOfRed = inColor.amountOfRed;
 amountOfBlue = inColor.amountOfBlue;
 amountOfGreen = inColor.amountOfGreen;
 return 0;
}
bool ColorClass:: setColorFromFile(ifstream &inFile,
                                   int colorMax)
{
 inFile >> amountOfRed >> amountOfGreen >> amountOfBlue;
 if ((amountOfRed < MIN_COLOR) || (amountOfRed > colorMax) ||
     (amountOfGreen < MIN_COLOR) || (amountOfGreen > colorMax) ||
     (amountOfBlue < MIN_COLOR) || (amountOfBlue > colorMax))
 {
  cout << "the pixel is out of range." << endl;
  return 0;
 }
 return 1;
}
bool ColorClass:: checkEqualColor(ColorClass &colorCopm)
{
 return (amountOfRed == colorCopm.getRed())
 && (amountOfGreen == colorCopm.getGreen())
 && (amountOfBlue == colorCopm.getBlue()); 
}
int ColorClass:: getRed()
{
 return amountOfRed;
}
int ColorClass:: getGreen()
{
 return amountOfGreen;
}
int ColorClass:: getBlue()
{
 return amountOfBlue;
}
