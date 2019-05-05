//This file is the annotate image function.
//annotate based image with inserted image
//Created by Xiaoxue Xin on 11/3/18.
//
#include "ColorImageClass.h"
#include "NonTranspImageClass.h"

void annotateImageWithImage(NonTranspImageClass &patterImage,
                            ColorImageClass &image)
//annatate the original image with additional image
{
 int len = patterImage.getPositionLen();
 if (image.getRow() * image.getColumn() <
     patterImage.getPositionLen())
 {
  len = image.getRow() * image.getColumn();
 }
 for (int i = 0; i < len; i++)
 {
  RowColumnClass patInd;
  int row = patterImage.getPositionInfo()[i].getIndex().getRow();
  int col = patterImage.getPositionInfo()[i].getIndex().getCol();
  if ((row > 0) && (row < image.getRow()) &&
      (col > 0) && (col < image.getColumn()))
  {
   patInd.setRowCol(row, col);
   ColorClass patColor;
   patColor.setTo(patterImage.getPositionInfo()[i].getColor().getRed(),
                  patterImage.getPositionInfo()[i].getColor().getGreen(),
                  patterImage.getPositionInfo()[i].getColor().getBlue());
   image.setColorAtLocation(patInd, patColor);
  }
 }
}
