/* 	Nama/NIM : Athur Naufan Muharam
	Tanggal : 15 Sept 2017
	Topik : ADT Point
	Deskripsi : Membuat file header, body, dan driver sebuah ADT 
	Nama File : P01-18216003-150917-01-main.c */
/* Driver ADT Point */
#include <stdio.h>
#include <stdbool.h>
#include "point.h"


int main ()
{
/* Kamus Global */
	Point P1, P2, P3, P4;
	
/* Algoritma */
	printf("POINT 1: \n");
	bacaPoint(&P1);
	printf("POINT 1 adalah ");
	tulisPoint(P1);
	
	printf("\n");
	printf("POINT 2: \n");
	bacaPoint(&P2);
	printf("POINT 2 adalah ");
	tulisPoint(P2);

	printf("\n");
	printf("Kuadran POINT 1: Point 1 berada di kuadran %d \n", kuadran(P1));
	printf("Kuadran POINT 2: Point 2 berada di kuadran %d \n", kuadran(P2));
	
	printf("\n");
	printf("Perbandingan POINT 1 dan POINT 2 adalah sebagai berikut: \n");
	if (isEqual(P1,P2)) 
	{
		printf("Point 1 sama dengan Point 2 \n");
	} else
	{
		printf("Point 1 tidak sama dengan Point 2 \n");
	}
	if (isGreaterThan(P1,P2))
	{
		printf("Point 1 lebih besar dari Point 2 \n");
	} else if (isLessThan(P1,P2))
	{
		printf("Point 1 lebih kecil dari Point 2 \n");
	}
	
	printf("\n");
	printf("POINT 1 + POINT 2 = "); tulisPoint(P1); printf("+"); tulisPoint(P2);
	printf(" = "); tulisPoint(tambah(P1,P2)); printf("\n");
	printf("POINT 1 - POINT 2 = "); tulisPoint(P1); printf("-"); tulisPoint(P2);
	printf(" = "); tulisPoint(kurang(P1,P2)); printf("\n");	
	
	printf("\n");
	printf("POINT 1 digeser sejajar sumbu X. \n"); geserPointKeSbX(&P1);
	printf("POINT 1 menjadi "); tulisPoint(P1);
	printf("POINT 2 digeser sejajar sumbu Y. \n"); geserPointKeSbY(&P2);
	printf("POINT 2 menjadi "); tulisPoint(P2);
	
	printf("\n");
	printf("POINT 3: \n");
	bacaPoint(&P3);
	printf("POINT 3 adalah ");
	tulisPoint(P3);
	
	printf("\n");
	printf("Kuadran POINT 3: Point 3 berada di kuadran %d \n", kuadran(P3));
	
	printf("\n");
	printf("POINT 4 adalah POINT hasil penjumlahan POINT 3 dan POINT 2. \n");
	P4 = tambah(P3,P2);
	printf("POINT 4 adalah "); tulisPoint(P4);
	return 0;
}

 
	
	
	
