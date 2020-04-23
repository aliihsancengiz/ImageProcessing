#include "Image.h"
#include "Histogram.h"
#include<stdio.h>

int main()
{
	Image rgbImg;
	Hist a;
	ctor_Image("Images/test.JPG",&rgbImg);
	CalculateHistogram(&rgbImg,&a);
	displayHistogram(&a);
	ImageInfo(&rgbImg);
	dtor_Image(&rgbImg);
	return 0;
}
