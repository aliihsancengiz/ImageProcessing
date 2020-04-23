/*
Library:				Image Processing
Written by:				Ali ihsan Cengiz
Date Written:			23.04.2020
Last modified:		-/-
Description:			This is an image processing library for C language
References:
			1) stb_image.h and stb_image_write.h library
				 https://github.com/nothings/stb
										
* Copyright (C) 2020 
    This is a free software under the GNU license, you can redistribute it and/or modify it under the terms
    of the GNU General Public Licenseversion 3 as published by the Free Software Foundation.

    This software library is shared with puplic for educational purposes, without WARRANTY and Author is not liable for any damages caused directly
   or indirectly by this software, read more about this on the GNU General Public License.
*/

#ifndef _MY_IMAGE
#define _MY_IMAGE
#include "Matrix.h"


//Struct For Storing Imaage
struct _Image
{
    int height,width,channels;
    Mat red,green,blue,gray;
};
typedef struct _Image Image;

//Image constructor,destructor and some operations
void ctor_Image(char *filename,Image *self);
void dtor_Image(Image *self);
void imwrite(char *filename,Image *self);
void MakeEmptyGrayImage(Image *pDst,int  h,int w);
void rgb2gray(Image *pSrc,Image *pDst);
void ImageInfo(Image *pSrc);

#endif
