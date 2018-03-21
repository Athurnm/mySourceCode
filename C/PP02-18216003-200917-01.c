/* NIM/Nama 	: 18216003/Athur Naufan Muharam */
/* Nama file	: PP02-18216003-200917-01.c		*/
/* Tanggal		: 20 September 2017			*/
/* Deskripsi 	: file body dari ADT		*/

#include "point.h"
#include <stdio.h>
#include <math.h>

#ifndef point_body_C
#define point_body_c

Point makePoint(int x, int y){
/* Membentuk sebuah Point dari komponen-komponennya */
	Point P;
	P.x = x; P.y = y; //memasukan nilai x dan y ke dalam point
	return P;
}

int getAbsis(Point P){
/*Mengirimkan komponen Absis dari P*/
	return(P.x);
}

int getOrdinat (Point P){
/* Mengirimkan komponen Ordinat dari P*/
	return (P.y);
}

void bacaPoint(Point *P){
/*Makepoint (x,y,P) membentuk P dari x dan y yang dibaca */
	int x,y;
	printf("x : "); scanf("%d",&x);
	printf("y : "); scanf("%d",&y);
	*P = makePoint(x,y);
}

void tulisPoint(Point P)
/* Nilai P ditulis ke layar dg format “(X,Y}” */
{
	printf("{%d,%d}", P.x,P.y);
}	
	
bool isEqual (Point P1, Point P2)
//Mengirimkan true jika P1=P2 : absis dan ordinatnya sama
{
	if (P1.x == P2.x && P1.y == P2.y){
		return true;
	} else {
		return false;
	}
}

bool isLessThan(Point P1, Point P2)
/* Mengirimkan true jika P1 < P2. Definisi lebih kecil: lebih “kiribawah”
dalam bidang kartesian */
{
	if (P1.x < P2.x && P1.y < P2.y){
		return true;
	} else {
		return false;
	}
}

bool isGreaterThan(Point P1, Point P2)
/* Mengirimkan true jika P1 > P2. Definisi lebih besar: lebih “kananatas”
dalam bidang kartesian */
{
	if (P1.x > P2.x && P1.y>P2.y){
		return true;
	} else {
		return false;
	}
}

int kuadran(Point P)
/* Menghasilkan kuadran dari P: 1,2,3, atau 4
Prekondisi : P bukan Titik Origin,
dan P tidak terletak di salah satu sumbu*/
{
	if (P.x > 0 && P.y > 0 ){
		return 1;
	}else if (P.x < 0 && P.y>0){
		return 2;
	}else if (P.x<0 && P.y < 0){
		return 3;
	}else if(P.x>0 && P.y<0){
		return 4;
	}
}

Point tambah(Point P1, Point P2)
//Menghasilkan operasi penjumlahan vector P1+P2
{
	Point Ps;
	Ps.x = P1.x + P2.x;
	Ps.y = P1.y + P2.y;
	return (Ps);
}

Point kurang(Point P1, Point P2)
//Menghasilkan operasi pengurangan vector P1-P2
{
	Point Ps;
	Ps.x = P1.x - P2.x;
	Ps.y = P1.y - P2.y;
	return (Ps);
}

float jarak(Point P1, Point P2)
//Menghasilkan jarak P1 dengan P2
{
	float jarak;
	jarak = sqrt((P1.x-P2.x)*(P1.x-P2.x) + (P1.y-P2.y)*(P1.y-P2.y));
	return(jarak);
}

#endif

