/* 	Nama/NIM : Athur Naufan Muharam
	Tanggal : 15 Sept 2017
	Topik : ADT Point
	Deskripsi : Membuat file header, body, dan driver sebuah ADT 
	Nama File : P01-18216003-150917-01.c */
/* body point.h */
#ifndef point_C
#define point_C
#include <stdio.h>
#include <stdbool.h>
#include "point.h"


Point makePoint(int x, int y)
/* Membentuk sebuah Point dari komponen - komponennya */
{
	Point P;
	P.x = x;
	P.y = y;
	return (P);
}

int getAbsis(Point P)
/*Mengirimkan komponen Absis dari P*/
{
	return(P.x);
}

int getOrdinat (Point P)
/* Mengirimkan komponen Ordinat dari P*/
{
	return(P.y);
}

void bacaPoint(Point *P)
/*Makepoint (x,y,P) membentuk P dari x dan y yang dibaca */
{
	int x,y;
	printf("x: "); scanf("%d", &x);
	printf("y : "); scanf("%d", &y);
	*P = makePoint(x,y);
}

void tulisPoint(Point P)
/* Nilai P ditulis ke layar dg format “(X,Y}” */
{
	printf("{%d,%d}", P.x, P.y);
}

bool isEqual (Point P1, Point P2)
//Mengirimkan true jika P1=P2 : absis dan ordinatnya sama
{
	if (P1.x == P2.x && P1.y == P2.y) 
	{
		return(true);
	}else
	{
		return(false);
	}
}

bool isLessThan(Point P1, Point P2)
/*  Mengirimkan  true  jika P1  <  P2.  Definisi  lebih  kecil:  lebih  “kiribawah”
dalam bidang kartesian */
{
	if (P1.x < P2.x && P1.y < P2.y)
	{
		return(true);
	}else
	{
		return(false);
	}
}

bool isGreaterThan(Point P1, Point P2)
/*  Mengirimkan  true  jika  P1  >  P2.  Definisi  lebih  besar:  lebih 
“kananatas”
dalam bidang kartesian */
{
	if (P1.x>P2.x && P1.y>P2.y)
	{
		return(true);
	}else
	{
		return(false);
	}
}

int kuadran(Point P)
/* Menghasilkan 
kuadran dari P: 1,2,3, atau 4
Prekondisi : P bukan Titik Origin,
dan P tidak terletak di salah satu sumbu*/
{
	if(P.x >= 0 && P.y >= 0)
	{
		return(1);
	}else if(P.x < 0 && P.y > 0)
	{
		return(2);
	}else if(P.x<0 && P.y<0)
	{
		return(3);
	}else
	{
		return(0);
	}
}

Point tambah(Point P1, Point P2)
//Menghasilkan operasi penjumlahan vector P1+P2
{
	Point P;
	P.x = P1.x + P2.x;
	P.y = P1.y + P2.y;
	return(P);
}
		
Point kurang(Point P1, Point P2)
//Menghasilkan operasi pengurangan vector P1-P2
{
	Point P;
	P.x = P1.x - P2.x;
	P.y = P1.y - P2.y;
	return(P);
}

void geserPointKeSbX (Point *P)
//Geser point ke sumbu x dengan nilai x tetap
{
	Point Pa;
	Pa = *P;
	Pa.y = 0;
	*P = Pa;
}

void geserPointKeSbY (Point *P)
//Geser point ke sumbu y dengan nilai y tetap
{
	Point Pa;
	Pa = *P;
	Pa.x = 0;
	*P = Pa;
}
#endif


