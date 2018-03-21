/* File: ADT_Array.h */

#ifndef ADT_ARRAY_H
#define ADT_ARRAY_H
#define IdxUndef -999
#define NMax 100

//Tipe yang dipakai
typedef int IdxType;
typedef int ElType;
typedef struct 
{
	int T1[NMax+1];
	int Neff;
}TabInt;

//konstruktor
void CreateEmpty (TabInt *T);
//selektor
int GetNeff(TabInt T);
ElType GetElmt (TabInt T, IdxType i);
//selektor indeks
IdxType GetFirstIdx (TabInt T);