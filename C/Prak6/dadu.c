/* file: Queue.c */
#include "dadu.h"
#include <stdlib.h>
#include <stdio.h>

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
	if(!(IsEmpty(Q)))
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

/* MODUL Queue TAMBAHAN */

int IdxEff(Queue Q)
/* mengembalikan nilai indeks efektif tabel / jumlah elemen yang ada */
{
	//Kamus lokal
	
	//Algoritma lokal
	if (!IsEmpty(Q))
	{
		return 0;
	}else 
		return (NBElmt(Q));
}

bool IsGameOver(Queue Q)
/* mengembalikan true apabila kondisi permainan berakhir terpenuhi, yaitu
   salah satu pemain mendapatkan skor sebesar 3 atau hanya tinggal satu
   pemain yang bermain */
{
	//Kamus lokal
	bool found;
	int i;
	//Algoritma lokal
	if (NBElmt(Q) == 1)
	{
		return (true);
	}else
	{
		found = false;
		i = 1;
		while (i<=NBElmt(Q) && Q.T[i].skor!=3)
		{
			if (Q.T[i].skor != 3)
			{
				i++;
			}
		}
		if(i>NBElmt(Q))
		{
			return (false);
		}else
		{
			return(true);
		}
	}
}

void CreateQueuePemain(Queue *Q,int Maks)
/* I.S : Queue kosong dengan alokasi Min 2 dan Maks 6
   F.S : Menghasilkan Q yang berisi informasi seluruh pemain berupa nama
   dengan skor awal = 0 */
{
	//Kamus lokal
	int i=1;
	infotype x;
	//Algoritma lokal
	CreateEmpty(Q,Maks);
	do 
	{
		x.skor=0;
		(*Q).T[i].Nama= (char*) malloc (255*sizeof(char));
		x.Nama = (char*) malloc (255*sizeof(char));
		scanf("%s", x.Nama);
		Add(Q,x);
		i++;
	}while(i<=Maks);
}

void ChangeTurn(Queue *Q)
/* I.S : Queue berisi minimal 2 elemen
   F.S : Head(Q) diganti menjadi pemain yang berada di antrian selanjutnya
   Sedangkan untuk Head(Q) di awal dipindah ke antrian paling
   belakang / Tail(Q) */
{
	//Kamus lokal
	infotype x1;
	//Algoritma lokal
	Del(Q,&x1);
	Add(Q,x1);
}

void PrintSkor(Queue Q)
/* I.S : Queue tidak kosong
   F.S : Menampilkan seluruh skor pemain sesuai dengan format <nama> <skor> */
{
	//Kamus lokal
	infotype x;
	int i,s;
	//Algoritma lokal
	i=1;
	s = NBElmt(Q);
	while (i<= s)
	{
		printf("%s %d \n",Q.T[i].Nama, Q.T[i].skor);
		i++;
	}
}

void GenerateRandom(int *X) {
    *X = rand() % 6 + 1;
}
