/* file :antrianbank.c */

#include "queue.h"
#include <stdio.h>

float AvgElmt (Queue Q)
/* Menghasilkan rata-rata elemen dalam queue Q yang tidak kosong */
{
	//Kamus lokal
	float x,sum;
	int count=0;
	infotype a;
	//Algoritma lokal
	sum =0;//inisialisasi
	do
	{
		Del(&Q, &a);
		x=a;
		count++;
		sum = sum + x;
	}while (!IsEmpty(Q));
	x=count;
	sum = sum / x;
	return (sum);
}

int main()
{
	//Kamus 
	Queue Q;
	int p,Max; //p = pilihan
	infotype x;
	
	//Algoritma 
	scanf("%d",&Max);
	CreateEmpty(&Q,Max);
	scanf("%d", &p);
	while (p != 0)
	{
		switch (p)
		{
			case 1 :
			{
				scanf("%d",&x);
				if (!IsFull(Q))
				{
					Add(&Q,x);
				}else
					printf("Queue penuh\n");
				break;
			}
			case 2 :
			{
				if(IsEmpty(Q))
				{
					printf("Queue kosong\n");
				}else
				{
					Del(&Q,&x);
				}
				break;
			}
			case 0 : break;
		}
		scanf("%d", &p); //next option
	}
	printf("%d\n",NBElmt(Q));
	if (IsEmpty(Q))
	{	
		printf("Tidak bisa dihitung\n");
	}else
	{
		printf("%.2f\n",AvgElmt(Q));
	}
	DeAlokasi(&Q);
	return 0;
}

