#ifndef _MYHISTOGRAM
#define _MYHISTOGRAM

#include "Image.h"
#include <stdint.h>
#include <stdio.h>


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