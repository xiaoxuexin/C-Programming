//This file is the annotate image function.
//
//Created by Xiaoxue Xin on 11/3/18.
//
#include "ColorClass.h"
#include "ColorImageClass.h"
#include "RectangleClass.h"

void annotateImageWithRec(RectangleClass &rec,
                          ColorImageClass &image,
                          bool fillOrNot)
//annotate original image with rectangle
{
 ColorClass rectColor;
 rectColor.setTo(rec.getColor().getRed(),
                 rec.getColor().getGreen(),
                 rec.getColor().getBlue());
 if (fillOrNot == 0)//rectangle boundary
 {
  for (int i = 0; i < rec.getBoundaryPositionLen(); i++)
  {
   RowColumnClass rectPosi;
   rectPosi.setRow(rec.getBoundaryPostion()[i].getRow());
   rectPosi.setCol(rec.getBoundaryPostion()[i].getCol());
   image.setColorAtLocation(rectPosi, rectColor);
  }
 }
 else//annotate image with rectangle plane
 {
  for (int i = 0; i < (rec.getLenRow() * rec.getLenCol()); i++)
  {
   RowColumnClass rectPosi;
   rectPosi.setRow(rec.getPlanePosition()[i].getRow());
   rectPosi.setCol(rec.getPlanePosition()[i].getCol());
   image.setColorAtLocation(rectPosi, rectColor);
  }
 }
}
