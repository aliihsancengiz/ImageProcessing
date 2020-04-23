#ifndef _MY_MAT
#define _MY_MAT

#include <stdint.h>

struct _Mat
{
	int width,height;
	uint8_t **data;
};
typedef struct _Mat Mat;

void ConstructorMat(Mat *pSrc,int h,int w);
void DestructorMat(Mat *pSrc);
void AddMat(Mat *pSrcA,Mat *pSrcB,Mat *pDst);
void FillMat(Mat *pSrc,int value);
void displayMat(Mat a);
int  dotProduct(Mat *pSrcA,Mat *pSrcB);
void MatProduct(Mat *pSrcA,Mat *pSrcB,Mat *pDst);
#endif