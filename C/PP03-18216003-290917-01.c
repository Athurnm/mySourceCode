/* NIM/Nama 	: 18216003/Athur Naufan Muharam */
/* Nama file	: PP03-18216003-290917-01.c		*/
/* Tanggal		: 29 September 2017				*/
/* Deskripsi	: File body ADT Array			*/

#include <stdio.h>
#include <stdlib.h>
#include "PP03-18216003-290917-01.h"
#ifndef ARRAY_C
#define ARRAY_C

/* ************** KONSTRUKTOR *************** */
/*Konstruktor membuat tabel kosong*/
void MakeEmpty (TabInt *T)
// I.S. Sembarang
// F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax - IdxMin+1
{
	//Kamus lokal
	//Algoritma lokal
	SetNeff(T, 0);
}

/* ************** SELEKTOR ******************* */
/*Banyaknya element*/
int NbElmt(TabInt T)
//Mengirimkan banyaknya elemen efektif tabel
//mengirimkan 0 jika tabel kosong
{
	//Kamus lokal
	//Algoritma lokal
	return (T.neff);
}
/*daya tampung container*/
int MaxNbEl(TabInt T)
//mengirimkan maksimal elemen yang dapat ditampung oleh tabel
{
	//Kamus lokal
	//Algoritma lokal
	return (IdxMax-IdxMin+1);
}
/*selektor INDEKS */
IdxType GetFirstIdx(TabInt T)
// prekondisi : Tabel T tidak kosong
// mengirimkan indeks elemen pertama tabel
{
	//Kamus lokal
	//Algoritma lokal
	return(IdxMin);
}
IdxType GetLastIdx(TabInt T)
// prekondisi : Tabel T tidak kosong
// mengirimkan indeks elemen terakhir
{
	//Kamus lokal
	//Algoritma lokal
	return(IdxMin + NbElmt(T)-1);
}
/* Menghasilkan sebuah elemen */
ElType GetElmt (TabInt T, IdxType i)
// prekondisi : tabel T tidak kosong, i antara FirstIdx(T)..LastIdx(T)
// mengirimkan elemen tabel ke-i
{
	//Kamus lokal
	//Algoritma lokal
	return(T.TI[i]);
}

/* ***Selektor SET : mengubah nilai TABEL dan elemen tabel*** */
void SetTab(TabInt Tin, TabInt *Tout)
//I.S. Tin terdefinisi, sembarang
//F.S. Tout berisi salinan Tin 
//proses assignment Thsl -> Tin 
{
	//Kamus lokal
	int i; //var untuk iterasi
	//Algoritma lokal
	(*Tout).neff = NbElmt(Tin);
	for(i=IdxMin;i<=GetLastIdx(Tin);i++)
	{
		SetEl(Tout, i, GetElmt(Tin,i));
	}
}
void SetEl(TabInt *T, IdxType i, ElType v)
//I.S. T terdefinisi, sembarang
//F.S. Elemen T yang ke-i bernilai v
//proses mengeset nilai elemen ke-i menjadi v
{
	//Kamus lokal 
	//Algoritma lokal
	(*T).TI[i] = v;
}
void SetNeff(TabInt *T, IdxType N)
//I.S. T terdefinisi, sembarang
//F.S. Nilai index efektif T bernilai Nama
//proses mengubah Neff tabel T menjadi Nama
{
	//Kamus lokal
	//Algoritma lokal
	(*T).neff = N;
}
/* ********* Tes Index yang valid ************** */
bool IsIdxValid (TabInt T, IdxType i)
//prekondisi : i sembarang
//mengirimkan true jika i adalah indeks yang valid untuk ukuran tabel
//yaitu antara indeks yang terdefinisi untuk container
{
	return(i>=IdxMin&&i<=IdxMax);
}
bool IsIdxEff (TabInt T, IdxType i)
//prekondisi : i sembarang
//mengirimkan true jika i adalah indeks yang terdefinisi untuk tabel
//antara FirstIdx(T) dan LastIdx(T)
{
	return(i>=GetFirstIdx(T)&&i<=GetLastIdx(T));
}

/* ********* TEST KOSONG/PENUH ***************** */
/* Test tabel kosong */
bool isEmpty (TabInt T)
//mengirimkan true jika tabel T kosong, dan false jika tidak
{
	//kamus lokal
	//Algoritma lokal
	return(NbElmt(T)==0);
}
/* Test tabel penuh */
bool isFull(TabInt T)
//mengirimkan true jika tabel T penuh dan false jika tidak
{
	//kamus lokal 
	//Algoritma lokal
	return(NbElmt(T)== MaxNbEl(T));
}

/* ********* BACA dan TULIS dengan INPUT/OUTPUT device ******** */
/* Mendefinisikan isi tabel dari pembacaan */
void BacaIsi (TabInt *T)
//I.S. sembarang
//F.S. Tabel T terdefinisi 
//Proses membaca banyaknya elemen T dan mengisi nilai elemen T
{
	//Kamus lokal
	int i; //variabel traversal
	IdxType neff;
	ElType v; //penampung isi
	//Algoritma lokal
	do
	{
		printf("Jumlah elemen tabel : ");
		scanf("%d",&neff);
		if (!IsIdxValid(*T,neff))
		{
			printf("Neff harus diantara 1 sampai 100, ulangi input \n");
		}
	}while(!IsIdxValid(*T,neff));
	//input neff sudah valid

	SetNeff(T, neff);
	for (i = IdxMin; i<=NbElmt(*T); i++)
	{
		printf("Isi indeks ke-%d : ", i);
		scanf ("%d", &v);
		SetEl(T,i,v);
	}
}
void TulisIsi(TabInt T)
//I.S. T boleh kosong
//F.S. jika T tidak kosong: index dan elemen tabel ditulis berderet ke bawah
//	   jika T kosong: Hanya menulis "Tabel kosong"
//Proses: menuliskan isi tabel dengan traversal
{
	//Kamus lokal
	int i;
	//Algoritma lokal
	if (isEmpty(T)) 
	{
		printf("Tabel Kosong");
	} else 
	{
		for(i=IdxMin; i<=NbElmt(T);i++)
		{
			printf("Isi indeks ke-%d : %d \n",i,GetElmt(T,i));
		}
	}
}
void TulisIsiTab(TabInt T)
//I.S. T boleh kosong
//F.S. jika T tidak kosong: [e1,e2,...,en]
//	   jika kosong: menulis []
//Proses: menuliskan isi tabel dengan traversal, tabel ditulis diantara kurung siku
//antara kedua elemen dipisahkan separator 'koma'
{
	//Kamus lokal
	int i;
	//Algoritma lokal
	if(isEmpty(T))
	{
		printf("[]");
	}else
	{
		printf("[ ");
		for(i=IdxMin; i<=NbElmt(T); i++)
		{
			if(i<NbElmt(T))
			{
				printf("%d, ", GetElmt(T,i));
			}else
			{
				printf("%d",GetElmt(T,i));
			}				
		}
		printf(" ]");
	}
}

/* ************* OPERATOR ARITMATIKA ************** */
/* Aritmatika Tabel : penjumlahan, pengurangan */
TabInt PlusTab(TabInt T1,TabInt T2)
//Prekondisi : T1 dan T2 berukuran sama dan tak kosong
//Mengirimkan T1+T2
{
	//Kamus lokal
	int i;
	TabInt Tsum;
	//Algoritma lokal
	SetNeff(&Tsum, NbElmt(T1));
	for(i=IdxMin;i<=NbElmt(T1);i++)
	{
		SetEl(&Tsum, i, GetElmt(T1,i)+GetElmt(T2,i));	
	}
	return Tsum;
}
TabInt MinusTab(TabInt T1,TabInt T2)
//Prekondisi : T1 dan T2 berukuran sama dan tak kosong
//Mengirimkan T1-T2
{
	//Kamus lokal
	int i;
	TabInt Tmin;
	//Algoritma lokal
	SetNeff(&Tmin, NbElmt(T1));
	for(i=IdxMin; i<=NbElmt(Tmin);i++)
	{
		SetEl(&Tmin, i, GetElmt(T1,i)-GetElmt(T2,i));
	}
	return Tmin;
}

#endif

