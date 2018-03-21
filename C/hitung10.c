/* Program menghitung jumlah 1 dan 0 */
/* nama file : hitung10.c */
#include <stdio.h>
#define Nmax 100

typedef char LarikChar[Nmax];
void bacaLarik (LarikChar A, int N);
void printLarik (LarikChar A, int N);

/* program utama */
int main () 
{
	/* Kamus */
	int N;
	LarikChar A;
	int sum1;
	int sum0;
	int i;
	
	printf("masukan banyaknya data (N) : "); scanf("%d", &N);
	bacaLarik(A,N);
	printf("Nilai Array anda : \n");
	printLarik(A,N);
	sum1 = 0;
	sum0 = 0;
	for (i=0; i<N; i++)
	{
		if (A[i] == '1')
		{
			sum1 = sum1 + 1;
		} else if (A[i] == '0')
		{
			sum0 = sum0 + 1;
		}
	}
	printf("Banyaknya angka 1 = %d \n",sum1);
	printf("Banyaknya angka 0 = %d \n", sum0);
	return 0;
}

void bacaLarik(LarikChar A, int N)
{
	int i;
	for(i=0; i<N; i++)
	{
		printf("Masukan nilai A[%d] : ", i+1); scanf (" %c", &A[i]);
	}
}

void printLarik(LarikChar A, int N)
{
	int i;
	for(i=0; i<N; i++)
	{
		printf("A[%d] = %c \n", i+1, A[i]);
	}
}