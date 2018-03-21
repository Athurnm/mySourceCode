/* NIM/Nama 	: 18216003/Athur Naufan Muharam */
/* Nama file	: P04-18216003-061017-01.h					*/
/* Tanggal		: 06 Oktober 2017				*/
/* Deskripsi	: File header Mesin kata			*/

//Mesin lain yang digunakan
#include "mesinkar.h"

#ifndef MESINKATA_H
#define MESINKATA_H
//Konstanta
#define BLANK ' '
#define NMax 50

//Definisi type kata
typedef struct
	{
		char TabKata[NMax+1];
		int Length;
	} Kata;

/* ***** Definisi State Mesin Kata ***** */
extern bool EndKata; /* penanda akhir akuisisi kata */
extern Kata CKata;  /* kata yang sudah diakuisisi dan akan diproses */
/* ***** Primitif-Primitif Mesin Kata ***** */
void Ignore_Blank();
/* Mengabaikan satu atau beberapa BLANK */
/* I.S. : CC sembarang */
/* F.S. : CC ≠ BLANK atau CC = MARK */
void STARTKATA();
/* I.S. : CC sembarang */
/* F.S. : EndKata = true, dan CC = Mark; */
/* atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
CC karakter pertama sesudah karakter terakhir kata */
void ADVKATA();
/* I.S. : EndKata = false; CC adalah karakter sesudah karakter terakhir
dari kata yg sudah diakuisisi */
/* F.S. : Jika CC = MARK, maka EndKata = true
atau EndKata = false, CKata adalah kata terakhir yang sudahdiakuisisi;
CC karakter pertama sesudah karakter terakhir kata */
void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata */
/* I.S. : CC adalah karakter pertama dari kata */
/* F.S. : CKata berisi kata yang sudah diakuisisi, jika karakternya melebihi
NMax, sisa "kata" dibuang; CC = BLANK atau CC = MARK; CC adalah
karakter sesudah karakter terakhir yang diakuisisi */

#endif

