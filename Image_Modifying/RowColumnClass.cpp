//This file is the row column class.
//
//Created by Xiaoxue Xin on 11/3/18.
//
#include <iostream>
#include "constants.h"
#include "RowColumnClass.h"

using namespace std;

//constructor and initialization for RowColumnClass
RowColumnClass:: RowColumnClass()
{
 rowIndex = INITIAL_COL_ROW;
 columnIndex = INITIAL_COL_ROW;
}
//self-difine constructor
RowColumnClass:: RowColumnClass(int inRow,
                                int inCol)
{
 rowIndex = inRow;
 columnIndex = inCol;
}
//functions in RowColumnClass
void RowColumnClass:: setRowCol(int inRow,
                                int inCol)
{
 rowIndex = inRow;
 columnIndex = inCol;
}
void RowColumnClass:: setRow(int inRow)
{
 rowIndex = inRow;
}
void RowColumnClass:: setCol(int inCol)
{
 columnIndex = inCol;
}
int RowColumnClass:: getRow()
{
 return rowIndex;
}
int RowColumnClass:: getCol()
{
 return columnIndex;
}
