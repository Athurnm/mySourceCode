/* Program Penjumlahan deret */
/* Menjumlahkan deret
		1+2+3+...+N
	dengan N bilangan bulat positif */

#include <stdio.h>
#include <stdlib.h>

int main ()
{
	/* Kamus */
	int i,N,sum;
	/* Algoritma */
	printf("Masukan N yang diinginkan: ");
	scanf("%d", &N);
	sum = 0; /* inisiasi */
	for (i=0; i<=N; i++)
	{
		sum = sum + i;
		if (i<N)
		{
			printf("%d + ", i);	
		} else
		{
			printf("%d", i);	
		}
	}
	printf(" = %d", sum);
	return 0;
}