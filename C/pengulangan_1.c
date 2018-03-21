/* Program penjumlahanDeret */
/* Nama File: pengulangan_1.c */

#include <stdio.h>

int main () 
{
	/*Kamus */
	int i, sum, N;
	/*Algoritma*/
	printf("Masukan nilai N :");
	scanf("%d", &N);
	/*inisiasi*/
	sum = 0; 
	i = 1;
	while (i<=N)
	{
		sum = sum + i;
		if (i<N)
		{
			printf ("%d + ",i);
		} else 
		{
			printf("%d",i);
		}
		
		i++;
	}
	printf (" = %d", sum);
	return 0;
}