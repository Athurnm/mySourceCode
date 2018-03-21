/* NIM/Nama 	: 18216003/Athur Naufan Muharam */
/* Nama file	: P04-18216003-061017-01.c					*/
/* Tanggal		: 06 Oktober 2017				*/
/* Deskripsi	: File body Mesin kata			*/

#include "P04-18216003-061017-01.h"
/* ***** Definisi State Mesin Kata ***** */
bool EndKata; /* penanda akhir akuisisi kata */
Kata CKata;  /* kata yang sudah diakuisisi dan akan diproses */
/* ***** Primitif-Primitif Mesin Kata ***** */
void Ignore_Blank()
/* Mengabaikan satu atau beberapa BLANK */
/* I.S. : CC sembarang */
/* F.S. : CC ≠ BLANK atau CC = MARK */
{
	//kamus lokal
	//Algoritma lokal
	while ((CC == BLANK)&&(!EOP())) 
	{
		ADV();//next element
	} 
}
void STARTKATA()
/* I.S. : CC sembarang */
/* F.S. : EndKata = true, dan CC = Mark; */
/* atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
CC karakter pertama sesudah karakter terakhir kata */
{
	//kamus lokal
	//Algoritma lokal
	START();
	EndKata = false; //inisialisasi
	if (!EOP())
	{
		Ignore_Blank();
		SalinKata();
		if (CC== MARK)
		{
			EndKata = true;
		}
	}else
	{
		EndKata = true;
	}
}

void ADVKATA()
/* I.S. : EndKata = false; CC adalah karakter sesudah karakter terakhir
dari kata yg sudah diakuisisi */
/* F.S. : Jika CC = MARK, maka EndKata = true
atau EndKata = false, CKata adalah kata terakhir yang sudahdiakuisisi;
CC karakter pertama sesudah karakter terakhir kata */
{
	//kamus lokal
	//Algoritma lokal
	Ignore_Blank();
	if (EOP())
	{
		EndKata = true;
	}else
	{
		SalinKata();
		EndKata = false;
	}
}
void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata */
/* I.S. : CC adalah karakter pertama dari kata */
/* F.S. : CKata berisi kata yang sudah diakuisisi, jika karakternya melebihi
NMax, sisa "kata" dibuang; CC = BLANK atau CC = MARK; CC adalah
karakter sesudah karakter terakhir yang diakuisisi */
{
	//kamus lokal
	int i;
	//Algoritma lokal
	i = 0;
	while(!EOP() && CC != BLANK && i<=NMax)
	{
		i = i+1;
		CKata.TabKata[i] = CC;
		ADV(); //next char
	}
	CKata.Length = i;
}


