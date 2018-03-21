/* NIM/Nama 	: 18216003/Athur Naufan Muharam 		*/
/* Nama file	: PP04-18216003-061017-01.h				*/
/* Tanggal		: 06 Oktober 2017						*/
/* Deskripsi	: File header Tambahan Mesin karakter	*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "mesinkar.h"
#ifndef TAMBAHMESIN_H
#define TAMBAHMESIN_H

// primitif

void PrintHuruf ();
// I.S. : terdapat sebuah mesin karakter dengan pita berisi karakter mungkin kosong
// F.S. : Mencetak isi pita karakter ke layar

int CountChar ();
// Menghitung jumlah karakter pada pita
// Prekondisi : terdapat sebuah mesin karakter dengan pita berisi karakter (mungkin kosong)

int CountNum ();
// Menghitung jumlah karakter angka pada pita
// Prekondisi : terdapat sebuah mesin karakter dengan pita berisi karakter (mungkin kosong)

int CountKapital();
// Menghitung jumlah karakter huruf kapital (‘A’,’B’,’C’,…,’Z’) pada pita
// Prekondisi : terdapat sebuah mesin karakter dengan pita berisi karakter(mungkin kosong)

#endif

