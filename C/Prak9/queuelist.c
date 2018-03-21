/* File : queuelist.c */
#include "queuelist.h"

/* Prototype manajemen memori */
void Alokasi (address *P, infotype X)
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
{
	*P = (address) malloc (sizeof (ElmtQueue));
	if (*P != Nil)
	{
		Info(*P) = X;
		Next(*P) = Nil;
	}
}
void Dealokasi (address  P)
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{
	free(P);
}
bool IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
{
	return (Head(Q)==Nil && Tail(Q)==Nil);
}
int NbElmt(Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
{
	if (IsEmpty(Q))
		return 0;
	else
	{
		int count = 0;
		address Px = Head(Q);
		while (Px != Nil)
		{
			count = count + 1;
			Px = Next(Px);
		}
		return count;
	}
}
/*** Kreator ***/
void CreateEmpty(Queue * Q)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
{
	//Kamus lokal
	//Algoritma lokal
	Head(*Q) = Nil;
	Tail(*Q) = Nil;
}
/*** Primitif Add/Delete ***/
void Add (Queue * Q, infotype X)
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
{
	//Kamus lokal
	address P;
	//Algoritma lokal
	Alokasi(&P,X);
	if (P!= Nil)
	{
		if (IsEmpty(*Q))
		{
			Head(*Q)=P;
			Tail(*Q)=P;
		}else
		{
			Next(Tail(*Q))=P;
			Tail(*Q) = P;
		}
	}
}
void Del(Queue * Q, infotype * X)
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
{
	//Kamus lokal
	address P;
	//Algoritma lokal
	if (Head(*Q)==Tail(*Q)) //1 elemen
	{
		(*X)=Info(Head(*Q));
		P = Head(*Q);
		Head(*Q) = Nil;
		Tail(*Q) = Nil;
	}else
	{
		(*X)= Info(Head(*Q));
		P=Head(*Q);
		Head(*Q)=Next(Head(*Q));
	}
	Dealokasi(P);
}