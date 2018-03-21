/* NIM/Nama 	: 18216003/Athur Naufan Muharam */
/* Nama file	: P04-18216003-061017-01-main.c	*/
/* Tanggal		: 06 Oktober 2017				*/
/* Deskripsi	: File driver Mesin kata		*/

#include "P04-18216003-061017-01.h"

//fungsi atau prosedur tambahan
void PrintHuruf()
// I.S. : terdapat sebuah mesin karakter dengan pita berisi karakter mungkin kosong
// F.S. : Mencetak isi pita karakter ke layar
{
	//Kamus Lokal
	//Algoritma lokal
	START();
	if (EOP())
	{
		printf("File kosong,tidak ada Telegram");
	} else 
	{
		do
		{
			printf("%c",CC); //proses current character
			ADV(); //next elemen
		}while (!EOP());
	}
}

int main ()
{
	//kamus
	int countKata, countMoreK, totalP,totalC;
	float kataLengthAvg;
	//Algoritma 
	countKata = 0; countMoreK = 0; totalP = 0; totalC=0;//inisialisasi
	START();
	printf("==== TELEGRAM ==== \n \n");
	printf("Isi telegram : "); PrintHuruf(); printf("\n");
	printf("\n");
	STARTKATA();
	//proses menghitung jumlah kata
	if (!EndKata)
	{
		do
		{
			if (CKata.Length>10) 
			{
				countMoreK = countMoreK+1;
			}
			countKata = countKata +1;
			totalC = totalC +CKata.Length;
			ADVKATA(); //proses next element
		}while (!EndKata);
	}
	if(countKata>10)
	{
		totalP = 1000*countKata + 500*countMoreK+200;
	}else
	{
		totalP = 1000*countKata + 500*countMoreK;
	}
	printf("Total jumlah kata : %d\n", countKata);
	printf("   Jumlah kata reguler : %d\n",countKata-countMoreK);
	printf("   Jumlah kata panjang : %d \n", countMoreK);
	printf("\n");
	printf("Total jumlah karakter : %d\n",totalC);
	if(countKata !=0)
	{
		kataLengthAvg = totalC;
		kataLengthAvg = kataLengthAvg/countKata;
	}else
	{
		kataLengthAvg = 0;
	}
	printf("Panjang kata rata-rata: %.2f karakter/kata\n",kataLengthAvg);
	printf("Biaya : Rp %d\n", totalP);
	printf("%c\n",CC);
	return 0;
}


