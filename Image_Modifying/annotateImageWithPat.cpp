//This file is the annotate image function.
//annotate iamge with pattern
//Created by Xiaoxue Xin on 11/3/18.
//
#include "ColorClass.h"
#include "ColorImageClass.h"
#include "PatternClass.h"

void annotateImageWithPat(PatternClass &pattern,
                          ColorImageClass &image)
//annotate the image with pattern
{
 ColorClass patColor;
 patColor.setTo(pattern.getColor().getRed(),
                pattern.getColor().getGreen(),
                pattern.getColor().getBlue());
 for (int i = 0; i < pattern.getPositionLen(); i++)
 {
  int row = pattern.getPatternPosition()[i].getRow();
  int col = pattern.getPatternPosition()[i].getCol();
  if ((row > 0) && (row < image.getRow()) &&
      (col > 0) && (col < image.getColumn()))
  {
   image.setColorAtLocation(pattern.getPatternPosition()[i],
                            patColor);
  }//modify the pixel that in the base image
 }
}
