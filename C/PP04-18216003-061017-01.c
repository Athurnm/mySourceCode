/* NIM/Nama 	: 18216003/Athur Naufan Muharam 		*/
/* Nama file	: PP04-18216003-061017-01.c				*/
/* Tanggal		: 06 Oktober 2017						*/
/* Deskripsi	: File body Tambahan Mesin karakter		*/

#include "PP04-18216003-061017-01.h"
#include "mesinkar.h"
// primitif

void PrintHuruf()
// I.S. : terdapat sebuah mesin karakter dengan pita berisi karakter mungkin kosong
// F.S. : Mencetak isi pita karakter ke layar
{
	//Kamus Lokal
	//Algoritma lokal
	START();
	if (EOP())
	{
		printf("File kosong,tidak ada SMS");
	} else 
	{
		do
		{
			printf("%c",CC); //proses current character
			ADV(); //next elemen
		}while (!EOP());
	}
}

int CountChar ()
// Menghitung jumlah karakter pada pita
// Prekondisi : terdapat sebuah mesin karakter dengan pita berisi karakter (mungkin kosong)
{
	//Kamus lokal
	int count; //var counter
	//Algoritma lokal
	START();
	count = 0; //inisialisasi
	if (EOP())
	{
		return(count);
	} else
	{
		do
		{
			count = count+1; //proses current element
			ADV(); //next elemen
		}while (!EOP());
		return(count);
	}
}
int CountNum ()
// Menghitung jumlah karakter angka pada pita
// Prekondisi : terdapat sebuah mesin karakter dengan pita berisi karakter (mungkin kosong)
{
	//Kamus lokal
	int count; //var counter
	//Algoritma lokal
	START();
	count = 0; //inisialisasi
	if (EOP())
	{
		return(count);
	}else
	{
		do
		{
			if (CC == '1'||CC == '2'||CC=='3'||CC=='4'||CC=='5'||CC=='6'||CC=='7'||CC=='8'||CC=='9'||CC=='0')
			{
				count=count+1; //proses current element
			}
			ADV ();//next elemen
		}while (!EOP());
		return(count);
	}
}
int CountKapital()
// Menghitung jumlah karakter huruf kapital (‘A’,’B’,’C’,…,’Z’) pada pita
// Prekondisi : terdapat sebuah mesin karakter dengan pita berisi karakter(mungkin kosong)
{
	//Kamus lokal
	int count; //var counter
	//Algoritma lokal
	START();
	count = 0; //inisialisasi
	if (EOP())
	{
		return(count);
	}else
	{
		do
		{
			if (CC>= 'A' && CC<='Z')
			{
				count=count+1; //proses current element
			}
			ADV();//next element
		}while(!EOP());
		return(count);
	}
}