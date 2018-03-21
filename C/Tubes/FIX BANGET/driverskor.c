/* filename : driverskor.c */

#include "save_load.h"

int main ()
{
	//Kamus 
	List L;
	infolist x;
	//Algoritma
	load(&L, "pemain.txt");
	PrintInfo(L);
	printf("masukan nama dan skor :");
	scanf("%s %d", x.name, &x.skor);
	updateSkor(&L,x);
	PrintInfo(L);
	save(&L, "pemain.txt");
	return 0;
}
