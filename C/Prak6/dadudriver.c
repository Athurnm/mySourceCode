// Namafile     : dadudriver.c
// Tanggal   	: 27 Oktober 2017
// Deskripsi	: Driver untuk program ADT Queue - Permainan Dadu

#include <stdio.h>
#include "dadu.h"

int main()
{
	/* KAMUS */
	Queue Q;
	int jml,turn=0,dadu1,dadu2;
	address j=1;
	char * pil;
	Pemain out;

	/* ALGORITMA */
	printf("** Permainan Dadu **\n");
	do {
		printf("Masukkan jumlah Pemain : ");
		scanf("%d",&jml);
		if ((jml<2) || (jml>6)) {
			printf("Jumlah pemain minimal 2 dan maksimal 6, ulangi!\n");
		}
	} while ((jml<2) || (jml>6));
	CreateEmpty(&Q,jml);
	CreateQueuePemain(&Q,jml);
	printf("** Permainan Dimulai **");
	do {
		turn++;
		printf("\n---Turn %d---\n",turn);
		printf("Giliran : %s\n",InfoHead(Q).Nama);
		printf("Kocok Dadu : ");
		pil = malloc(256);
		scanf("%255s",pil);
		if (strcmp(pil,"Ya")==0) {
			GenerateRandom(&dadu1);
			srand(time(NULL));
			GenerateRandom(&dadu2);
			printf("---Hasil---\n");
			printf("Dadu 1 : %d\n",dadu1);
			printf("Dadu 2 : %d\n",dadu2);
			if (dadu1 == dadu2) {
                InfoHead(Q).skor += 1;
			}
			printf("---Skor---\n");
			PrintSkor(Q);
			printf("\n");
		}
		else if (strcmp(pil,"Tidak")==0) {
			Del(&Q,&out);
			printf("NOTE : %s keluar dari permainan\n",(out).Nama);
		}
		ChangeTurn(&Q);
	} while (!IsGameOver(Q));

	printf("\n***Permainan Berakhir***\n");
	if (Head(Q)==Tail(Q)) {
		printf("Pemenang : %s",(InfoHead(Q)).Nama);
	}
	else {
		while (Q.T[j].skor<3) {
			if (Q.T[j].skor==3) {
				printf("Pemenang : %s",Q.T[j].Nama);
			}
		}
	}
	DeAlokasi(&Q);

	return 0;
}
