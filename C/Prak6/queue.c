/* file: Queue.c */
#include "queue.h"
#include <stdlib.h>

/* ********* Prototype ********* */
bool IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
	//Kamus lokal
	//Algoritma lokal
	return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}
bool IsFull (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
	//Kamus lokal
	//Algoritma lokal
	return((Head(Q)==1) && (Tail(Q)==MaxEl(Q)));
}
int NBElmt (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
	//Kamus lokal
	//Algoritma lokal
	if (!IsEmpty(Q))
		return(Tail(Q) - Head(Q)+1);
	else
		return 0;
}

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
	//Kamus lokal
	
	//Algoritma lokal
	(*Q).T = (infotype *) malloc ((Max+1)*sizeof(infotype));
	if ((*Q).T != NULL)
	{
		MaxEl (*Q) = Max;
		Head(*Q)= Nil;
		Tail(*Q)= Nil;
	}else
	{
		MaxEl(*Q)=Nil;
	}
	
}

/* *** Destruktor *** */
void DeAlokasi(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
	//Kamus lokal
	
	//Algoritma lokal
	MaxEl(*Q) = Nil;
	free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" */
{
	//Kamus lokal

	//Algoritma lokal
	if (IsEmpty(*Q))
		Head(*Q)=1;
	Tail(*Q)++;
	InfoTail(*Q)=X;
}
void Del (Queue * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., 
			jika Q masih isi, elemen setelah HEAD digeser ke "kiri",
			HEAD diset tetap = 1, TAIL = TAIL - 1;
			Q mungkin kosong (HEAD = TAIL = Nil) */
{
	//Kamus lokal
	address i;
	//Algoritma lokal
	if (NBElmt(*Q)==1)
	{
		(*X)=InfoHead(*Q);
		Head(*Q)=Nil;
		Tail(*Q)=Nil;
	}else
	{
		i = 1;
		(*X)=InfoHead(*Q);
		while (i<Tail(*Q))
		{
			(*Q).T[i] = (*Q).T[i+1];
			i++;
		}
		Tail(*Q)--;
	}
}