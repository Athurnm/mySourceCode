/* Program hitungRataRata */
/* Nama file : rerata.c */

#include <stdio.h>

int main ()
{
	/* Kamus */
	float rerata;
	int x, sum,i;
	
	/* Algoritma */
	/* inisialisasi */
	sum = 0;
	i = 0;
	printf("masukan nilai x = ");
	scanf("%d", &x);
	while (x != -1)
	{
		i++;
		sum = sum + x;
		printf("masukan nilai x = ");
		scanf("%d", &x);
	}
	if (i != 0)
	{
		rerata = sum/i;
		printf("Rata-rata nilai adalah = %f \n", rerata);
	} else 
	{
		printf("Tidak ada nilai yang diinput \n");
	}
	return 0;
}