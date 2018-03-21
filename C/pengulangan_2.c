/* Program penjumlahanDeret */
/* Nama File: pengulangan_2.c */

#include <stdio.h>

int main ()
{
	/*kamus*/
	int i, sum, N;
	/*Algoritma*/
	/*inisialisasi*/
	i = 1;
	sum = 0;
	printf("masukan nilai N = ");
	scanf("%d", &N);
	do
	{
		sum = sum +i;
		if (i<N) 
		{
			printf("%d +",i);
		} else 
		{
			printf("%d",i);
		}
		i ++;
	} while (i<=N);
	printf(" = %d", sum);
	return 0;
}
