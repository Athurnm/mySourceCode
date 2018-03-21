/* Program rata-rata */
/* Nama file: rataLarik.c */
#include <stdio.h>
#define Nmaks 100

typedef int LarikInt[Nmaks+1]; 
void bacaLarik(LarikInt A, int N);
/* Mengisi elemen larik A[1..n] */

void cetakLarik(LarikInt A, int N);
/* mencetak elemen-elemen larik A[1..N] */

void hitungRata(LarikInt A, int N, float *u);
/* menghitung nilai rata2 */

/* Algoritma Utama */
int main () 
{
	/* Kamus */
	LarikInt A;
	int k;
	int N;
	float U;
	
	/* Algoritma */
	printf("Berapa jumlah data (N)? "); scanf("%d", &N);
	printf("Baca data \n");
	bacaLarik(A,N);
	printf("Cetak data : \n");
	cetakLarik(A,N);
	printf("Hitung rata-rata : \n");
	hitungRata(A,N,&U);
	printf("Rata-rata data = %f \n", U);
	return 0 ;
}

void bacaLarik(LarikInt A, int N)
{
	/* Kamus */
	int i; 
	
	/* Algoritma */
	for (i=1; i<=N; i++)
	{
		printf("Masukan nilai A[%d] : ", i); scanf("%d", &A[i]);
	}
}

void cetakLarik(LarikInt A, int N)
{
	/* Kamus */
	int i;
	
	/* Algoritma */
	for(i=1; i<=N; i++)
	{
		printf("A[%d] = %d ", i, A[i]);
	}
}

void hitungRata(LarikInt A, int N, float *u)
{
	/* Kamus */
	int i;
	float sum;
	
	/* Algoritma */
	i=1;
	sum = 0;
	for (i=1; i<=N; i++)
	{
		sum = sum + A[i];
	}
	*u = sum/N;
}