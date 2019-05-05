//This file is the row column class header.
//
//Created by Xiaoxue Xin on 11/3/18.
//
#ifndef _ROWCOLUMNCLASS_H_
#define _ROWCOLUMNCLASS_H_

class RowColumnClass
{
private:
 int rowIndex;
 int columnIndex;
public:
 RowColumnClass();//constructor
 RowColumnClass(int inRow,
                int incol);//self-define constructor
 void setRowCol(int inRow,
                int inCol);//set row and column
 void setRow(int inRow);//set row
 void setCol(int inCol);
 int getRow();//get row
 int getCol();//get column
};

#endif
