// NOTE: compile with g++ filename.cpp -std=c++11
#include <iostream>
#include <math.h>
#include <cstdlib>

#include "main.h"

#if _LESS_CODE_BEAUT_PIC_

#define DIM 1024
#define DM1 (DIM-1)
#define _sq(x) ((x)*(x)) // square
#define _cb(x) abs((x)*(x)*(x)) // absolute value of cube
#define _cr(x) (unsigned char)(pow((x),1.0/3.0)) // cube root
unsigned char GR(int, int)
{return 0;}
unsigned char BL(int, int)
{return 0;}
unsigned char RD(int i, int j)
{return 0;}
void pixel_write(int, int); 
FILE *fp;

int main() { 
#if defined(_WIN32)||defined(_WIN64)
	int err = fopen_s(&fp, "MathPic.ppm","wb"); 
#else
	fp = fopen("MathPic.ppm", "wb");
#endif
	fprintf(fp, "P6\n%d %d\n255\n", DIM, DIM); 
	for (int j = 0; j < DIM; j++)     
		for (int i = 0; i < DIM; i++)       
			pixel_write(i, j);    fclose(fp); 
	return 0;
}
void pixel_write(int i, int j)
{ 
	static unsigned char color[3];  
	color[0] = RD(i, j) & 255;  
	color[1] = GR(i, j) & 255;  
	color[2] = BL(i, j) & 255;   
	fwrite(color, 1, 3, fp);
}


#endif
