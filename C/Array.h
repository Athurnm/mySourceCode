/* File ADT Array */
/* Nama File : Array.h */

#include <stdio.h>
#include "boolean.h"
#include <stdlib.h>
#ifndef ARRAY_H
#define ARRAY_H

// Kamus Umum
#define IdxMax 100
#define IdxMin 1
#define IdxUndef -999 //indeks tak terdefinisi
	
// Definisi elemen dan koleksi objek 
	typedef int IdxType; //tipe indeks
	typedef int ElType; //tipe elemen tabel
	typedef struct
	{
		ElType TI[IdxMax+1];
		int neff;
	} TabInt;
	
/* ************** KONSTRUKTOR *************** */
/*Konstruktor membuat tabel kosong*/
void MakeEmpty (TabInt *T);
// I.S. Sembarang
// F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax - IdxMin+1

/* ************** SELEKTOR ******************* */
/*Banyaknya element*/
int NbElmt (TabInt T);
//Mengirimkan banyaknya elemen efektif tabel
//mengirimkan 0 jika tabel kosong
/*daya tampung container*/
int MaxNbEl(TabInt T);
//mengirimkan maksimal elemen yang dapat ditampung oleh tabel
/*selektor INDEKS */
IdxType GetFirstIdx(TabInt T);
// prekondisi : Tabel T tidak kosong
// mengirimkan indeks elemen pertama tabel
IdxType GetLastIdx(TabInt T);
// prekondisi : Tabel T tidak kosong
// mengirimkan indeks elemen terakhir
/* Menghasilkan sebuah elemen */
ElType GetElmt (TabInt T, IdxType i);
// prekondisi : tabel T tidak kosong, i antara FirstIdx(T)..LastIdx(T)
// mengirimkan elemen tabel ke-i

/* ***Selektor SET : mengubah nilai TABEL dan elemen tabel*** */
void SetTab(TabInt Tin, TabInt *Tout);
//I.S. Tin terdefinisi, sembarang
//F.S. Tout berisi salinan Tin 
//proses assignment Thsl -> Tin 
void SetEl(TabInt *T, IdxType i, ElType v);
//I.S. T terdefinisi, sembarang
//F.S. Elemen T yang ke-i bernilai v
//proses mengeset nilai elemen ke-i menjadi v
void SetNeff(TabInt *T, IdxType N);
//I.S. T terdefinisi, sembarang
//F.S. Nilai index efektif T bernilai Nama
//proses mengubah Neff tabel T menjadi Nama

/* ********* Tes Index yang valid ************** */
/* Test tabel kosong */
bool isEmpty (TabInt T);
//mengirimkan true jika tabel T kosong, dan false jika tidak
/* Test tabel penuh */
bool isFull(TabInt T);
//mengirimkan true jika tabel T penuh dan false jika tidak

/* ********* BACA dan TULIS dengan INPUT/OUTPUT device ******** */
/* Mendefinisikan isi tabel dari pembacaan */
void BacaIsi (TabInt *T);
//I.S. sembarang
//F.S. Tabel T terdefinisi 
//Proses membaca banyaknya elemen T dan mengisi nilai elemen T
void TulisIsi(TabInt T);
//I.S. T boleh kosong
//F.S. jika T tidak kosong: index dan elemen tabel ditulis berderet ke bawah
//	   jika T kosong: Hanya menulis "Tabel kosong"
//Proses: menuliskan isi tabel dengan traversal
void TulisIsiTab(TabInt T);
//I.S. T boleh kosong
//F.S. jika T tidak kosong: [e1,e2,...,en]
//	   jika kosong: menulis []
//Proses: menuliskan isi tabel dengan traversal, tabel ditulis diantara kurung siku
//antara kedua elemen dipisahkan separator 'koma'

/* ************* OPERATOR ARITMATIKA ************** */
/* Aritmatika Tabel : penjumlahan, pengurangan */
TabInt PlusTab(TabInt T1,TabInt T2);
//Prekondisi : T1 dan T2 berukuran sama dan tak kosong
//Mengirimkan T1+T2
TabInt MinusTab(TabInt T1,TabInt T2);
//Prekondisi : T1 dan T2 berukuran sama dan tak kosong
//Mengirimkan T1-T2

#endif

