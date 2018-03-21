/* NIM/Nama 	: 18216003/Athur Naufan Muharam */
/* Nama file	: PP03-18216003-290917-01-main.c*/
/* Tanggal		: 29 September 2017				*/
/* Deskripsi	: File driver ADT Array			*/

#include "PP03-18216003-290917-01.h"
#include <stdio.h>

int main () 
{
	//Kamus Global
	TabInt T1,T2;
	int icg; //indeks yang ingin diganti
	int v; //value pengganti
	int choice; //var penampung pilihan opsi
	
	//Algoritma Global
	printf("=== ADT TABEL KONTIGU === \n");
	MakeEmpty(&T1);MakeEmpty(&T2); //inisalisasi
	BacaIsi(&T1);
	printf("\n");
	do
	{
		printf("*****MENU*****\n");
		printf("1. Tulis Tabel \n");
		printf("2. Indeks Awal dan Akhir Tabel \n");
		printf("3. Ganti Elemen Tabel \n");
		printf("4. Buat Tabel Baru \n");
		printf("5. Keluar \n");
		printf("Pilihan Anda : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: 
			{
				printf("\n");
				printf("=====TULIS TABEL=====\n");
				TulisIsi(T1);
				printf("\n");
			} break;
			case 2:
			{
				printf("\n");
				printf("Indeks awal tabel : %d \n", GetFirstIdx(T1));
				printf("Elemen index awal tabel : %d \n", GetElmt(T1,GetFirstIdx(T1)));
				printf("Indeks akhir tabel : %d \n", GetLastIdx(T1));
				printf("Elemen index akhir tabel : %d \n \n",GetElmt(T1,GetLastIdx(T1)));
			} break;
			case 3:
			{
				printf("\n");
				do
				{
					printf("Indeks elemen yang ingin diganti : "); scanf("%d",&icg);
					if(!IsIdxEff(T1,icg))
					{
						printf("Input harus dari %d - %d, ulangi input \n",GetFirstIdx(T1),GetLastIdx(T1));
					}
				}while(!IsIdxEff(T1,icg));
				printf("Elemen baru : "); scanf("%d",&v);
				SetEl(&T1,icg,v);
				printf("Ganti elemen tabel berhasil! \n \n");
			} break;
			case 4:
			{
				printf("\n");
				printf("TABEL BARU (jumlah elemen tabel harus sama dengan tabel sebelumnya) \n");
				BacaIsi(&T2);
				printf("\n");
				printf("Hasil penjumlahan tabel \n");
				printf("=====TULIS TABEL=====\n");
				TulisIsi(PlusTab(T1,T2));
				printf("\n");
				printf("Hasil pengurangan tabel\n");
				printf("=====TULIS TABEL=====\n");
				TulisIsi(MinusTab(T1,T2));
				printf("\n");
			} break;
			case 5: printf("Selamat Tinggal ! \n");
			break;
			default: printf("Nomor yang anda masukan salah, silahkan pilih opsi 1-5 \n");
					break;
		}
	} while (choice != 5);
	return 0;
}