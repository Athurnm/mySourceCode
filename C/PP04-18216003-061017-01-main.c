/* NIM/Nama 	: 18216003/Athur Naufan Muharam 		*/
/* Nama file	: PP04-18216003-061017-01-main.c		*/
/* Tanggal		: 06 Oktober 2017						*/
/* Deskripsi	: File drive Tambahan Mesin karakter	*/

#include "PP04-18216003-061017-01.h"
#include <stdio.h>

int main()
{
	//kamus
	int total,countCap,countNum,countChar;
	//Algoritma
	printf("==== TARIF SMS ==== \n");
	printf("Isi SMS : ");
	PrintHuruf();printf("\n");
	countChar = CountChar();
	countNum = CountNum();
	countCap = CountKapital();
	printf("Jumlah karakter : %d \n",countChar);
	printf("Jumlah angka : %d \n",countNum);
	printf("Jumlah huruf kapital : %d \n",countCap);
	if (countChar <= 25)
	{
		total=50*countChar+5*countNum+5*countCap;
	}else //karakter 26 keatas
	{
		total=50*countChar+5*countNum+5*countCap+2*(countChar-25);
	}
	printf("Tarif SMS Anda : Rp %d \n",total);
}