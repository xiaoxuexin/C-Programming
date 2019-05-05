//This file is the color class header.
//
//Created by Xiaoxue Xin on 11/3/18.
//
#ifndef _COLORCLASS_H_
#define _COLORCLASS_H_
#include <fstream>

using namespace std;

// class ColorClass
class ColorClass
{
private:
 int amountOfRed;
 int amountOfGreen;
 int amountOfBlue;
public:
 ColorClass();//constructor
 ColorClass(int inRed,
            int inGreen,
            int inBlue);//self-define constructor
 void setToBlack();//set RBG value to black
 void setToRed();//set RBG value to red
 void setToGreen();//set RBG value to green
 void setToBlue();//set RBG value to blue
 void setToWhite();//set RBG value to white
 bool setTo(int inRed,
            int inGreen,
            int inBlue);//set RBG value to given color
 bool setTo(ColorClass &inColor);//set RBG value from object
 bool setColorFromFile(ifstream &inFile, int colorMax);
 bool checkEqualColor(ColorClass &colorCopm);
 int getRed();
 int getGreen();
 int getBlue();
private:
 bool setInRange(int &amountColor);
 //self-defined func to see whether clip
};

#endif
