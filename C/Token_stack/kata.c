/* NIM/Nama : 18216003/Athur Naufan M
Nama file   : kata.c
Topik       : mesin token
Tanggal     : 20 Oktober 2017
Deskripsi   : meyeleksi token dan angka */

#include "mesinkar.h"
#include "kata.h"


/* State Mesin Kata */
bool EndKata;
Token ctoken;


void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
I.S. : CC sembarang
F.S. : CC ≠ BLANK atau CC = MARK */
{
  /* Algoritma */
  while ((CC == BLANK) && (CC != MARK))
  {
	 ADV(); 
  }	  
  /* CC != BLANK or CC = MARK */
}

void STARTKATA()
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = Mark;
       atau EndKata = false, CKata adalah kata yang sudah
diakuisisi, CC karakter pertama sesudah karakter terakhir kata
jika ingin menggunakan SalinKata, input bool kata = true, else false*/  
{ 
  /* Algoritma*/
  START();
  IgnoreBlank();
  if (CC == MARK) 
    EndKata = true;
  else 
   {/* CC != MARK */
    EndKata = false;
    SalinToken();
   }
}

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
CC adalah karakter pertama dari kata berikutnya,
mungkin MARK
Proses : Akuisisi kata menggunakan procedure SalinKata */
{
  /* Algoritma*/
  IgnoreBlank();
  if (CC == MARK) 
    EndKata = true;
  else /* CC != MARK */ 
  SalinToken();
}


void SalinToken(){
/* Mengakuisisi kata, menyimpan dalam CKata
I.S. : CC adalah karakter pertama dari kata
F.S. : CKata berisi kata yang sudah diakuisisi;
CC = BLANK atau CC = MARK;
CC adalah karakter sesudah karakter terakhir yang
diakuisisi */
	//kamus lokal
	int i;
	//Algoritma lokal
	i = 0;
	while(!EOP() && CC != BLANK && i<=NMax)
	{
		i = i+1;
		ctoken.tkn[i] = CC;
		ADV(); //next char
	}
	ctoken.length = i;
} /* CC = MARK or CC = BLANK */

