#ifndef _MY_IMAGE
#define _MY_IMAGE
#include "Matrix.h"

struct _Image
{
    int height,width,channels;
    Mat red,green,blue,gray;
};
typedef struct _Image Image;


void ctor_Image(char *filename,Image *self);
void dtor_Image(Image *self);
void imwrite(char *filename,Image *self);
void MakeEmptyGrayImage(Image *pDst,int  h,int w);
void rgb2gray(Image *pSrc,Image *pDst);
void ImageInfo(Image *pSrc);

#endif
