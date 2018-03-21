/* NIM/Nama 	: 18216003/Athur Naufan Muharam */
/* Nama file	: mesinkar.h		*/
/* Tanggal		: 06 Oktober 2017				*/
/* Deskripsi	: File header Mesin karakter	*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#ifndef MESINKAR_H
#define MESINKAR_H
//boolean
#define bool unsigned char
#define true 1
#define false 0
//konstanta
#define MARK '.'
//kamus umum
extern char CC;

void START ();
// I.S. : sembarang 
// F.S. : CC adalah karakter pertama pita 
// Jika CC==MARK, EOP menyala (true) 
// Jika CC!=MARK, EOP padam (false) 

void ADV ();
// I.S. : CC!=MARK 
// F.S. : CC adalah karakter berikutnya dari CC pada I.S. 
// Jika CC==MARK, EOP menyala (true)

bool EOP();
// true jika CC == MARK

#endif

