#include "Image.h"




#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"


void ctor_Image(char *filename,Image *self)
{
    uint8_t *rgb_image=stbi_load(filename,&self->width,&self->height,&self->channels,0);
    int i=0,j=0;
    //printf("Width %d Height %d Nof channels %d \n",self->width,self->height,self->channels);
    if(self->channels == 3)
    {
        ConstructorMat(&self->red,self->height,self->width);
        ConstructorMat(&self->green,self->height,self->width);
        ConstructorMat(&self->blue,self->height,self->width);
        for (i = 0; i < self->height; i++)
        {
            for ( j = 0; j < self->width; j++)
            {
                self->red.data[i][j]=rgb_image[3*(i*self->width+j)];
                self->green.data[i][j]=rgb_image[3*(i*self->width+j)+1];
                self->blue.data[i][j]=rgb_image[3*(i*self->width+j)+2];
            }
        }
        stbi_image_free(rgb_image);
    }
    else
    {
        ConstructorMat(&self->gray,self->height,self->width);
        for(i=0;i<self->height;i++)
        {
            for(j=0;j<self->width;j++)
            {
                self->gray.data[i][j]=rgb_image[i*self->width+j];
            }
        }
        stbi_image_free(rgb_image);
    }
}
void dtor_Image(Image *self)
{
    if(self->channels == 3)
    {
        DestructorMat(&self->red);
        DestructorMat(&self->green);
        DestructorMat(&self->blue);
    }
    else
    {
        DestructorMat(&self->gray);
    }
    
}
static uint8_t * makergbFlatten(Image *self)
{
    int size=self->height*self->width*self->channels,i,j,k;
    uint8_t * rgb=malloc(sizeof(uint8_t)*size);
    if(rgb==NULL)
    {
        printf("Not enough memory");
        return NULL;
    }
    else
    {
           for(i=0;i < self->height; i++)
           {
                for ( j = 0; j < self->width; j++)
                {
                    for(k=0;k<self->channels;k++)
                    if(k%3==0)   // Write r data
                    {
                        //printf("%d \n",3*(i*self->width+j));
                        rgb[3*(i*self->width+j)]=self->red.data[i][j];
                    }
                    else if(k%3==1)   //write g data
                    {
                        //printf("%d \n",3*(i*self->width+j)+1);
                        rgb[3*(i*self->width+j)+1]=self->green.data[i][j];
                    }
                    else    //write b data
                    {
                        //printf("%d \n",3*(i*self->width+j)+2);
                        rgb[3*(i*self->width+j)+2]=self->blue.data[i][j];
                    }
                }
               
           }
           return rgb;
    }

}

static uint8_t * makegrayscaleflatten(Image *self)
{
    int size=self->height*self->width,i,j;
    uint8_t *flatgray=malloc(sizeof(uint8_t)*size);
    if(flatgray==NULL)
    {
        printf("Not enough memory");
        return NULL;
    }
    for(i=0;i<self->height;i++)
    {
        for(j=0;j<self->width;j++)
        {
            flatgray[i*self->width+j]=self->gray.data[i][j];
        }
    }
    return flatgray;

}
void imwrite(char *filename,Image *self)
{
    if(self->channels==3)
    {
        uint8_t *tt=makergbFlatten(self);
        stbi_write_jpg(filename,self->width,self->height,self->channels,tt,100);
        free(tt);
    }
    else if(self->channels==1)
    {
        uint8_t *tt=makegrayscaleflatten(self);
        stbi_write_jpg(filename,self->width,self->height,self->channels,tt,0);
        printf("grayscale");
    }
    else
    {
        printf("Uncategorized image format");
    }
}
void MakeEmptyGrayImage(Image *pDst,int  h,int w)
{
    pDst->height=h;
    pDst->width=w;
    pDst->channels=1;
    ConstructorMat(&pDst->gray,pDst->height,pDst->width);
}
void rgb2gray(Image *pSrc,Image *pDst)
{
    if((pSrc->height==pDst->height) && (pSrc->width == pDst->width))
    {
        int i,j;
        for(i = 0; i < pDst->height ; i++)
        {
            for(j= 0; j < pDst->width ; j++)
            {
                pDst->gray.data[i][j]=(0.2126)*pSrc->red.data[i][j]+(0.7152)*pSrc->green.data[i][j]+(0.0722)*pSrc->blue.data[i][j];
            }
        }
    }
    else
    {
        printf("Image dimesions are not match \n");
        return;
    }
    
}

void ImageInfo(Image *pSrc)
{
    printf("Height of Image %d\n",pSrc->height);
    printf("Width of Image %d\n",pSrc->width);
    printf("Channels of Image %d\n",pSrc->channels);
}

