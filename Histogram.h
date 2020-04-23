/*
Library:				Histogram of Image
Written by:				Ali ihsan Cengiz
Date Written:			23.04.2020
Last modified:		-/-
Description:			calculate histogram of image
References:
		
* Copyright (C) 2020 
    This is a free software under the GNU license, you can redistribute it and/or modify it under the terms
    of the GNU General Public Licenseversion 3 as published by the Free Software Foundation.

    This software library is shared with puplic for educational purposes, without WARRANTY and Author is not liable for any damages caused directly
   or indirectly by this software, read more about this on the GNU General Public License.
*/


#ifndef _MYHISTOGRAM
#define _MYHISTOGRAM

#include "Image.h"
#include <stdint.h>
#include <stdio.h>

// Struct For holding frequency of image data
struct _hist
{
    uint16_t HistogramArray[256];
};
typedef struct _hist Hist;

void CalculateHistogram(Image *pDst,Hist *pSrc)
{
    int i,j;
    for (i = 0; i < 256; i++)
    {
        pSrc->HistogramArray[i]=0;
    }
    if(pDst->channels==1)
    {
        for(i=0;i<pDst->height;i++)
        {
            for(j=0;j<pDst->width;j++)
            {
                pSrc->HistogramArray[pDst->gray.data[i][j]]++;
            }
        }
    }
    else if(pDst->channels == 3)
    {
        for(i=0;i<pDst->height;i++)
        {
            for(j=0;j<pDst->width;j++)
            {
                pSrc->HistogramArray[pDst->red.data[i][j]]++;
                pSrc->HistogramArray[pDst->green.data[i][j]]++;
                pSrc->HistogramArray[pDst->blue.data[i][j]]++;
            }
        }
    }
}
void displayHistogram(Hist *h)
{
    int i=0;
    for(i=0;i<256;i++)
    {
        printf("%d --> %d \n",i,h->HistogramArray[i]);
    }

}

#endif