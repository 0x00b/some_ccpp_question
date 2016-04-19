/*
有没有一段代码，让你觉得人类的智慧也可以璀璨无比？

不一定要是完整算法，就是那种看着看着就觉得嗨爆了，惊为天人的结构或语句。

知名博主 Matrix67 的一篇博文：

《用三段 140 字符以内的代码生成一张 1024×1024 的图片》

Kyle McCormick 在 StackExchange 上发起了一个叫做 Tweetable Mathematical Art 的比赛，参赛者需要用三条推这么长的代码来生成一张图片。

具体地说，参赛者需要用 C++ 语言编写 RD 、 GR 、 BL 三个函数，每个函数都不能超过 140 个字符。每个函数都会接到 i 和 j 两个整型参数（0 ≤ i, j ≤ 1023），然后需要返回一个 0 到 255 之间的整数，表示位于 (i, j) 的像素点的颜色值。举个例子，如果 RD(0, 0) 和 GR(0, 0) 返回的都是 0 ，但 BL(0, 0) 返回的是 255 ，那么图像的最左上角那个像素就是蓝色。

note：windows可以使用xnview工具打开.ppm图片
*/

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

/*rewrite follow 3 function*/
unsigned char GR(int, int);
unsigned char BL(int, int);
unsigned char RD(int i, int j);


void pixel_write(int, int);


FILE *fp;

/* 想要哪个的代码就注释哪行 */
#define MARTIN_1	// Martin Büttner 
#define MARTIN_2	// Martin Büttner 
#define MARTIN_3	// Martin Büttner 

#define MANUEL_1	// Manuel Kasten
#define MANUEL_2	// Manuel Kasten

#define PHAGOCYTE_1	// github phagocyte
#define PHAGOCYTE_2	// githubphagocyte

#define ERIC_1		// Eric Tressler

//#define GITOX00b_1	// github 0x00b
#define GITOX00b_2	// github 0x00b 其实2 和 3只需要改一下sin()里面的内容就会有很不一样的效果
#define GITOX00b_3	// github 0x00b

int main() {
#if defined(_WIN)
	int err = fopen_s(&fp, "MathPic.ppm", "wb");
#else
	fp = fopen("MathPic.ppm", "wb");
#endif
	fprintf(fp, "P6\n%d %d\n255\n", DIM, DIM);
	for (int j = 0; j < DIM; j++)
		for (int i = 0; i < DIM; i++)
			pixel_write(i, j);  
	fclose(fp);
	return 0;
}

#ifndef MARTIN_1
unsigned char RD(int i, int j) {
	return (char)(_sq(cos(atan2(j - 512, i - 512) / 2)) * 255);
}

unsigned char GR(int i, int j) {
	return (char)(_sq(cos(atan2(j - 512, i - 512) / 2 - 2 * acos(-1) / 3)) * 255);
}

unsigned char BL(int i, int j) {
	return (char)(_sq(cos(atan2(j - 512, i - 512) / 2 + 2 * acos(-1) / 3)) * 255);
}
#endif


#ifndef MARTIN_2

unsigned char RD(int i, int j) {
#define r(n)(rand()%n)
	static char c[1024][1024]; return!c[i][j] ? c[i][j] = !r(999) ? r(256) : RD((i + r(2)) % 1024, (j + r(2)) % 1024) : c[i][j];
}

unsigned char GR(int i, int j) {
	static char c[1024][1024]; return!c[i][j] ? c[i][j] = !r(999) ? r(256) : GR((i + r(2)) % 1024, (j + r(2)) % 1024) : c[i][j];
}

unsigned char BL(int i, int j) {
	static char c[1024][1024]; return!c[i][j] ? c[i][j] = !r(999) ? r(256) : BL((i + r(2)) % 1024, (j + r(2)) % 1024) : c[i][j];
}

#endif

#ifndef MARTIN_3
unsigned char RD(int i, int j) {
	float x = 0, y = 0; int k; for (k = 0; k++ < 256;) { float a = x*x - y*y + (i - 768.0) / 512; y = 2 * x*y + (j - 512.0) / 512; x = a; if (x*x + y*y>4)break; }return log(k) * 47;
}

unsigned char GR(int i, int j) {
	float x = 0, y = 0; int k; for (k = 0; k++ < 256;) { float a = x*x - y*y + (i - 768.0) / 512; y = 2 * x*y + (j - 512.0) / 512; x = a; if (x*x + y*y>4)break; }return log(k) * 47;
}

unsigned char BL(int i, int j) {
	float x = 0, y = 0; int k; for (k = 0; k++ < 256;) { float a = x*x - y*y + (i - 768.0) / 512; y = 2 * x*y + (j - 512.0) / 512; x = a; if (x*x + y*y>4)break; }return 128 - log(k) * 23;
}
#endif

#ifndef MANUEL_1
unsigned char RD(int i, int j) {
	double a = 0, b = 0, c, d, n = 0;
	while ((c = a*a) + (d = b*b) < 4 && n++ < 880)
	{
		b = 2 * a*b + j*8e-9 - .645411; a = c - d + i*8e-9 + .356888;
	}
	return 255 * pow((n - 80) / 800, 3.);
}

unsigned char GR(int i, int j) {
	double a = 0, b = 0, c, d, n = 0;
	while ((c = a*a) + (d = b*b) < 4 && n++ < 880)
	{
		b = 2 * a*b + j*8e-9 - .645411; a = c - d + i*8e-9 + .356888;
	}
	return 255 * pow((n - 80) / 800, .7);
}

unsigned char BL(int i, int j) {
	double a = 0, b = 0, c, d, n = 0;
	while ((c = a*a) + (d = b*b) < 4 && n++ < 880)
	{
		b = 2 * a*b + j*8e-9 - .645411; a = c - d + i*8e-9 + .356888;
	}
	return 255 * pow((n - 80) / 800, .5);
}
#endif 



#ifndef MANUEL_2
unsigned char RD(int i, int j) {
	static double k; k += rand() / 1. / RAND_MAX; int l = k; l %= 512; return l > 255 ? 511 - l : l;
}

unsigned char GR(int i, int j) {
	static double k; k += rand() / 1. / RAND_MAX; int l = k; l %= 512; return l > 255 ? 511 - l : l;
}

unsigned char BL(int i, int j) {
	static double k; k += rand() / 1. / RAND_MAX; int l = k; l %= 512; return l > 255 ? 511 - l : l;
}
#endif 

#ifndef PHAGOCYTE_1

unsigned char RD(int i, int j) {
	float s = 3. / (j + 99);
	float y = (j + sin((i*i + _sq(j - 700) * 5) / 100. / DIM) * 35)*s;
	return (int((i + DIM)*s + y) % 2 + int((DIM * 2 - i)*s + y) % 2) * 127;
}
unsigned char GR(int i, int j) {
	float s = 3. / (j + 99);
	float y = (j + sin((i*i + _sq(j - 700) * 5) / 100. / DIM) * 35)*s;
	return (int(5 * ((i + DIM)*s + y)) % 2 + int(5 * ((DIM * 2 - i)*s + y)) % 2) * 127;
}

unsigned char BL(int i, int j) {
	float s = 3. / (j + 99);
	float y = (j + sin((i*i + _sq(j - 700) * 5) / 100. / DIM) * 35)*s;
	return (int(29 * ((i + DIM)*s + y)) % 2 + int(29 * ((DIM * 2 - i)*s + y)) % 2) * 127;
}
#endif

#ifndef PHAGOCYTE_2
unsigned char RD(int i, int j) {
#define D DIM
#define M m[(x+D+(d==0)-(d==2))%D][(y+D+(d==1)-(d==3))%D]
#define R rand()%D
#define B m[x][y]
	return(i + j) ? 256 - (BL(i, j)) / 2 : 0;
}

unsigned char GR(int i, int j) {
#define A static int m[D][D],e,x,y,d,c[4],f,n;if(i+j<1){for(d=D*D;d;d--){m[d%D][d/D]=d%6?0:rand()%2000?1:255;}for(n=1
	return RD(i, j);
}

unsigned char BL(int i, int j) {
	A; n; n++) {
	x = R; y = R; if (B == 1) { f = 1; for (d = 0; d<4; d++) { c[d] = M; f = f<c[d] ? c[d] : f; }if (f>2) { B = f - 1; } else { ++e %= 4; d = e; if (!c[e]) { B = 0; M = 1; } } }
}
}return m[i][j];
}
#endif

#ifndef ERIC_1

unsigned char RD(int i, int j) {
#define A float a=0,b,k,r,x
#define B int e,o
#define C(x) x>255?255:x
#define R return
#define D DIM
	R BL(i, j)*(D - i) / D;
}

unsigned char GR(int i, int j) {
#define E DM1
#define F static float
#define G for(
#define H r=a*1.6/D+2.4;x=1.0001*b/D
	R BL(i, j)*(D - j / 2) / D;
}

unsigned char BL(int i, int j) {
	F c[D][D]; if (i + j<1) { A; B; G; a<D; a += 0.1) { G b = 0; b<D; b++){H; G k = 0; k<D; k++){x = r*x*(1 - x); if (k>D / 2) { e = a; o = (E*x); c[e][o] += 0.01; }}} } }R C(c[j][i])*i / D;
}
#endif


#ifndef GITOX00b_1

unsigned char GR(int i, int j)
{
#define PI 3.14
#define N 255
#define R return
#define L 40
#define D 512
	R sin((i / (double)DIM) *PI) * N;
}
unsigned char BL(int i, int j)
{
#define TS(k,r) (-(r)* (((sin(k) * sqrt(abs(cos(k)))) / (sin(k) + 1.4)) - 2 * sin(k) + 2))
	R sin((j / (double)DIM) * PI) * N;
}
unsigned char RD(int i, int j)
{
	float n, x, y, k;
	for (k = 0; k < L*1.6; k += .05)
	{
		n = TS(k, L);
		x = n * cos(k) + D;
		y = n * sin(k) + D;
		if (fabs((i - x)*(j - y))<3)
		{
			R  N ^ (GR(i, j) | BL(i, j));
		}
	}
	R (GR(i, j) | BL(i, j));
}
#endif

#ifndef GITOX00b_2

unsigned char RD(int i, int j)
{
	return 255 & GR(i, j) ^ BL(i, j);
}
unsigned char GR(int i, int j)
{
	//	return sin(((j) / (double)DIM) ) * 255;
	return j<i ? sin(((i) / (double)DIM)) * 255 : sin(((j) / (double)DIM)) * 255;
}
unsigned char BL(int i, int j)
{
	return sin(((j + i) / (double)DIM)) * 255;
}
#endif
#ifndef GITOX00b_3

unsigned char RD(int i, int j)
{
	//return 255^(GR(i, j) & BL(i, j));
	return 255 & (GR(i, j) | BL(i, j));
}
unsigned char GR(int i, int j)
{
	return sin( (i^j)/(double)DIM ) * 255;
}
unsigned char BL(int i, int j)
{
	return sin(i&j) * 255;
}
#endif

void pixel_write(int i, int j)
{
	static unsigned char color[3];
	color[0] = RD(i, j) & 255;
	color[1] = GR(i, j) & 255;
	color[2] = BL(i, j) & 255;
	fwrite(color, 1, 3, fp);
}
#endif
