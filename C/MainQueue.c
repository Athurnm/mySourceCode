/* file: MainQueue.c */

#include "queue.h"
#include <stdio.h>

int main ()
{
	//Kamus 
	Queue Q;
	infotype X;
	int N,i;
	int Max = 10;
	//Algoritma
	printf("Masukan jumlah elemen dari queue yg akan anda masukan = ");
	scanf("%d",&N);
	CreateEmpty(&Q,Max);
	printf("\n");
	i = 1;
	while (i<=N)
	{
		printf("Masukan nilai elemen anda : ");
		scanf("%d",&X);
		Add(&Q,X);
		i++;
	}
	printf("\n");
	printf("Jumlah elemen queue anda : %d \n",NBElmt(Q));
	printf("\n");
	printf("Isi Queue : \n");
	i=1;
	while (i<=Tail(Q))
	{
		printf("%d ", Q.T[i]);
		i++;
	}
	printf("\n");
	Del(&Q,&X);
	printf("Isi Queue : \n");
	i=1;
	while (i<=Tail(Q))
	{
		printf("%d ", Q.T[i]);
		i++;
	}
	printf("\n");
	printf("nilai elemen yang anda hapus = %d\n",X);
	DeAlokasi(&Q);
	return 0;
}