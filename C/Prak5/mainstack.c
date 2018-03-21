/* filename : mainstack.c */
#include <stdio.h>
#include "stack.h"

void isiStack (Stack *S)
{
	//kamus lokal
	int i;
	int n;
	infotype x;
	//Algoritma lokal
	CreateEmpty(S);
	printf("masukan banyaknya data (<10): ");scanf("%d",&n);
	i = 1;
	do
	{
		printf("masukan stack yang akan diisi : "); scanf("%c",x);
		Push(S,x);
		i++;
	}while (i<=n);
	printf("stack berhasil diisi!\n");
}

int main ()
{
	//Kamus 
	Stack S;
	int total;
	//Algoritma
	isiStack(&S);
	printf("\n");
	printf("Hasil penjumlahan %d\n", Hitung(&S));
	return 0;
}