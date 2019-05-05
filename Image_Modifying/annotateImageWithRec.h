//This file is the annotate image header.
//
//Created by Xiaoxue Xin on 11/3/18.
//
#ifndef _ANNOTATEIMAGEWITHREC_H_
#define _ANNOTATEIMAGEWITHREC_H_
#include "ColorImageClass.h"
#include "RectangleClass.h"

void annotateImageWithRec(RectangleClass &rec,
                          ColorImageClass &image,
                          bool fillOrNot);

#endif
