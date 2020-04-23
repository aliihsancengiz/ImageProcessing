/*
Library:				Matrix Processing
Written by:				Ali ihsan Cengiz
Date Written:			23.04.2020
Last modified:		-/-
Description:			This is an matrix processing library for C language
References:
		
* Copyright (C) 2020 
    This is a free software under the GNU license, you can redistribute it and/or modify it under the terms
    of the GNU General Public Licenseversion 3 as published by the Free Software Foundation.

    This software library is shared with puplic for educational purposes, without WARRANTY and Author is not liable for any damages caused directly
   or indirectly by this software, read more about this on the GNU General Public License.
*/

#ifndef _MY_MAT
#define _MY_MAT

#include <stdint.h>

// Struct for holding Matrix data and properties
struct _Mat
{
	int width,height;
	uint8_t **data;
};
typedef struct _Mat Mat;


// Some matrixc operations
void ConstructorMat(Mat *pSrc,int h,int w);
void DestructorMat(Mat *pSrc);
void AddMat(Mat *pSrcA,Mat *pSrcB,Mat *pDst);
void FillMat(Mat *pSrc,int value);
void displayMat(Mat a);
int  dotProduct(Mat *pSrcA,Mat *pSrcB);
void MatProduct(Mat *pSrcA,Mat *pSrcB,Mat *pDst);
#endif