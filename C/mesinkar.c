/* NIM/Nama 	: 18216003/Athur Naufan Muharam */
/* Nama file	: mesinkar.c		*/
/* Tanggal		: 06 Oktober 2017				*/
/* Deskripsi	: File body Mesin karakter		*/

#include "mesinkar.h"

//definisi states
char CC;

//definisi pita
static char Pita_karakter[63] = "pitakar.txt";
static FILE *FILEKU;
static int retval;

void START()
// I.S. : sembarang 
// F.S. : CC adalah karakter pertama pita 
// Jika CC==MARK, EOP menyala (true) 
// Jika CC!=MARK, EOP padam (false)
{
	FILEKU = fopen(Pita_karakter, "r");
	retval = fscanf(FILEKU, "%c", &CC);
} 

void ADV()
// I.S. : CC!=MARK 
// F.S. : CC adalah karakter berikutnya dari CC pada I.S. 
// Jika CC==MARK, EOP menyala (true)
{
	retval = fscanf(FILEKU,"%c",&CC);
	if (CC == MARK){
		fclose(FILEKU);
	}
}

bool EOP()
// true jika CC == MARK
{
	return (CC==MARK);
}