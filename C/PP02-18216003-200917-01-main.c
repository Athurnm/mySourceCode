/* NIM/Nama 	: 18216003/Athur Naufan Muharam */
/* Nama file	: PP02-18216003-200917-01-main.c*/
/* Tanggal		: 21 September 2017				*/
/* Deskripsi 	: file driver					*/

#include "point.h"
#include <stdio.h>

int main ()
{
	/* Kamus Global */
	Point P1, P2, P3;
	
/* Algoritma */
	printf("Program Point \n");
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

	printf("\n");
	printf("Kuadran POINT 1: Point 1 berada di kuadran %d \n", kuadran(P1));
	printf("Kuadran POINT 2: Point 2 berada di kuadran %d \n", kuadran(P2));
	
	printf("\n");
	printf("Perbandingan POINT 1 dan POINT 2 adalah sebagai berikut: \n");
	if (isEqual(P1,P2)) 
	{
		printf("-Point 1 sama dengan Point 2 \n");
	} else
	{
		printf("-Point 1 tidak sama dengan Point 2 \n");
	}
	if (isGreaterThan(P1,P2))
	{
		printf("-Point 1 lebih besar dari Point 2 \n");
	} else if (isLessThan(P1,P2))
	{
		printf("-Point 1 lebih kecil dari Point 2 \n");
	}
	
	printf("\n");
	printf("POINT 1 + POINT 2 = "); tulisPoint(P1); printf("+"); tulisPoint(P2);
	printf(" = "); tulisPoint(tambah(P1,P2)); printf("\n");
	printf("POINT 1 - POINT 2 = "); tulisPoint(P1); printf("-"); tulisPoint(P2);
	printf(" = "); tulisPoint(kurang(P1,P2)); printf("\n");	
	
	printf("\n");
	printf("POINT 3: \n");
	bacaPoint(&P3);
	printf("POINT 3 adalah ");
	tulisPoint(P3);
	
	printf("\n");
	printf("Kuadran POINT 3: Point 3 berada di kuadran %d \n", kuadran(P3));
	
	printf("\n");
	printf("Jarak POINT 1 dengan POINT 3 = %.2f \n", jarak(P1,P3));
	
	return 0;
}