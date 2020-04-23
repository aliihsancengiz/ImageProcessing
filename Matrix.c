#include<stdio.h>
#include<stdlib.h>
#include "Matrix.h"


void ConstructorMat(Mat *pSrc,int h,int w)
{
	int i,j;
	if(w<0 || h <0)
	{
		printf("Matrix size cannot be negative \n");
		return;
	}
	pSrc->height=h;
	pSrc->width=w;
	pSrc->data=(uint8_t **)malloc(sizeof(uint8_t*)*pSrc->height);
	if(pSrc->data==NULL)
	{
		printf("Failed to Allocate Memory \n");
		return ;
	}
	for(i=0;i<pSrc->height;i++)
	{
		pSrc->data[i]=(uint8_t*)malloc(sizeof(uint8_t)*pSrc->width);
		if(pSrc->data[i] == NULL)
		{
			printf("Failed to Allocate Memory \n");
		}
	}
	for(i=0;i<pSrc->height;i++)
	{
		for(j=0;j<pSrc->width;j++)
		{
			pSrc->data[i][j]=0;
		}
	}
}
void displayMat(Mat a)
{
	int i,j;
	for(i=0;i<a.height;i++)
	{
		for(j=0;j<a.width;j++)
		{
			printf("%d ",a.data[i][j]);
		}
		printf("\n");
	}
}
void DestructorMat(Mat *pSrc)
{
	int i;
	if(pSrc->data == NULL)
	{
		return;
	}
	for(i=0;i< pSrc->height;i++)
	{
		free(pSrc->data[i]);
	}
	free(pSrc->data);	
	pSrc->data=NULL;
}


void AddMat(Mat *pSrcA,Mat *pSrcB,Mat *pDst)
{
	if((pSrcA->width == pSrcB->width) && (pSrcA->height == pSrcB->height))
	{
		int i,j;
		for(i=0;i<pSrcA->height;i++)
		{
			for ( j = 0; j < pSrcA->width; j++)
			{
				pDst->data[i][j]=pSrcA->data[i][j]+pSrcB->data[i][j];
			}
		}
	}
	else
	{
		printf("Matrix Dimensions does not Agree");
	}
}


void FillMat(Mat *pSrc,int value)
{
	int i,j;
	for(i=0;i<pSrc->height;i++)
	{
		for (j = 0; j < pSrc->width; j++)
		{
			pSrc->data[i][j]=value;
		}
		
	}
}

int dotProduct(Mat *pSrcA,Mat *pSrcB)
{
	if((pSrcA->width == pSrcB->width) && (pSrcA->height == pSrcB->height))
	{
		int i,j,Sum=0;
		for(i=0;i<pSrcA->height;i++)
		{
			for ( j = 0; j < pSrcA->width; j++)
			{
				Sum+=pSrcA->data[i][j]*pSrcB->data[i][j];
			}
		}
		return Sum;
	}
	else
	{
		printf("Matrix Dimensions does not Agree");
		return -1;
	}
}


void MatProduct(Mat *pSrcA,Mat *pSrcB,Mat *pDst)
{
	if(pSrcA->width != pSrcB->height)
	{
		printf("Matrix Dimesnsions does not agree with each other\n");
		return;
	}
	if((pDst->height != pSrcA->height) || (pDst->width != pSrcB->width))
	{
		printf("Matrix Dimesnsions does not agree with each other\n");
		return ;
	}
	int i,j,k,Sum=0;
	for(i=0;i<pDst->height;i++)
	{
		for (j = 0; j < pDst->width; j++)
		{
			for(k=0;k<pSrcB->height;k++)
			{
				Sum+=pSrcA->data[i][k]*pSrcB->data[k][j];
			}
			pDst->data[i][j]=Sum;
			Sum=0;
		}
		
	}
}