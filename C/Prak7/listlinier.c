#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
bool IsEmpty (List L)
/* Mengirim true jika list kosong */
{
	//Kamus lokal
	//Kosong
	//Algoritma lokal
	return(First(L)==Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
	//Kamus lokal
	//kosong
	//Algoritma lokal
	First(*L)=Nil;
	
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	//Kamus lokal
	address P = (address) malloc (sizeof (ElmtList));
	//Algoritma lokal
	if (P == Nil) 
	{
		return (Nil);
	}else
	{
		Info(P)=X;
		Next(P)=Nil;
		return(P);
	}
}
void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	//Kamus lokal
	//kosong
	//Algoritma lokal
	free(*P);
}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	//Kamus lokal
	address P = First(L);
	//Algoritma lokal	
	while (P!= Nil)
	{
		if (Info(P) == X)
		{
			return P;
		}else 
		{
			P = Next(P); //Next element
		}
	}//Sudah sampai ujung elemen
	return Nil;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	//kamus lokal
	address P = Alokasi(X);
	
	//Algoritma lokal
	if (P != Nil)
	{
		Next(P) = First(*L);
		First(*L) = P;
	}
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	//kamus lokal
	address P = Alokasi(X);
	//Algoritma lokal
	if (P != Nil)
	{
		InsertLast(L,P);
	}
}
/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	//Kamus lokal
	address P = First(*L) ;
	//Algoritma lokal
	(*X) = Info(P);
	First(*L)=Next(P);
	Dealokasi(&P);
}
void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	//Kamus lokal
	address P = First(*L);
	address Prec = Nil;
	//Algoritma lokal
	while(Next(P)!=Nil)
	{
		Prec = P;
		P = Next(P);
	}
	(*X) = Info(P);
	if(Prec == Nil)
		First(*L) = Nil;
	else
		Next(Prec) = Nil;
	Dealokasi(&P);
}
/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
	//Kamus lokal
	//Kosong
	//Algoritma lokal
	Next(P)=First(*L);
	First(*L)=P;
}
void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	//Kamus lokal
	//Kosong
	//Algoritma lokal
	Next(P)=Next(Prec);
	Next(Prec)=P;
}
void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	//Kamus lokal
	address Px = First(*L);
	//Algoritma lokal
	if(IsEmpty(*L))
	{
		InsertFirst(L,P);
	}else
	{
		while (Next(Px)!=Nil)
			{
				Px = Next(Px); //Next Element
			}//udah sampai ujung
			InsertAfter(L,P,Px);
	}
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	//Kamus lokal
	//Algoritma lokal
	(*P)=First(*L);
	First(*L)=Next(First(*L));
}
void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	//Kamus lokal
	address Px = First(*L);
	address Prec = Nil;
	//Algoritma lokal
	if (Info(Px)==X)
	{
		First(*L)=Next(Px);
		Dealokasi(&Px);
	}else
	{
		while (Px != Nil && Info(Px)!= X)
		{
			Prec = Px;
			Px = Next(Px);
		}
		if(Px != Nil)
		{
			Next(Prec) = Next(Px);
			Dealokasi(&Px);
		}
	}
}
void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
	//Kamus lokal
	address Px = First(*L);
	address Prec = Nil;
	//Algoritma lokal
	if (Next(Px)==Nil)
	{
		DelFirst(L,P);
	}else
	{
		while (Next(Px)!= Nil)
		{
			Prec = Px;
			Px = Next(Px);
		}//sudah alamat terakhir	
		*P = Px;
		if(Prec != Nil)
			Next(Prec) = Nil;
	}
}
void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	//Kamus lokal
	address Px = First(*L);
	//Algoritma lokal
	while (Px != Prec)
		Px = Next(Px);
	*Pdel = Next(Prec);
	Next(Prec)=Next(Next(Prec));
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	//Kamus lokal
	address P = First(L);
	//Algoritma lokal
	if (IsEmpty(L))
	{
		printf("[]");
	}else
	{
		printf("[");
		do
		{
			printf("%d",Info(P));
			if(Next(P)!=Nil)
				printf(",");
			P = Next(P); //Next elemen
		}while (P!=Nil); //sudah tercapai elemen sebelum terakhir
		printf("]");
	}
}
int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
	//Kamus lokal
	address P = First(L);
	int Count = 0;
	//Algoritma lokal
	if(IsEmpty(L))
		return Count;
	else
	{
		do
		{
			Count++;
			P = Next(P);
		}while(P!= Nil);
		return Count;
	}
}
/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
	//Kamus lokal
	address P = First(L);
	infotype x;
	//Algoritma lokal
	x = Info(P);
	P = Next(P);
	while (P!= Nil)
	{
		if(Info(P)> x)
			x = Info(P);
		P = Next(P);
	}
	return x;
}

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
	//Kamus lokal
	address Px = First(*L1);
	//Algoritma lokal
	CreateEmpty(L3);
	if (Px!=Nil)
	{
		First(*L3)=First(*L1);
		while(Next(Px)!=Nil)
		{
			Px = Next(Px);
		}
		Next(Px)=First(*L2);
	}else
		First(*L3)=First(*L2);
	CreateEmpty(L1);
	CreateEmpty(L2);
}