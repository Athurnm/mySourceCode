/* file : roman.c */

#include "roman.h"

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Roman *R)
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack R yang kosong berkapasitas MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
{
	(*R).TOP = Nil;
}

/* *** Predikat Untuk test keadaan KOLEKSI *** */
bool IsEmpty(Roman R)
/* Mengirim true jika Roman kosong*/
/* Ciri stack kosong : TOP bernilai Nil */
{
	return(R.TOP == Nil);
}

bool IsFull(Roman R)
/* Mengirim true jika stack R penuh */
/* Ciri stack penuh : TOP bernilai MaxEl */
{
	return(R.TOP == MaxEl);
}

/* **** Operator Dasar Stack *** */
void Push(Roman *R, infotype X)
/* Menambahkan X sebagai elemen Roman *R. */
/* I.S. R mungkin kosong, R tidak penuh */
/* F.S. X menjadi element TOP yang baru, TOP bertambah 1 */
{
	(*R).TOP++;
	(*R).T[(*R).TOP-1] = X;
}
void Pop(Roman *R, infotype *X)
/* Menghapus X dari Roman *R. */
/* I.S. R tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
	(*X) = (*R).T[(*R).TOP-1];
	(*R).TOP--;
}
/* **** Roman Digit Operator *** */
bool IsRomanDigit(infotype X)
/* Mengirim true jika X adalah digit romawi I, V, X, L, C, D, atau M (case sensitive) */
{
	return(X== 'I'||X=='V'||X=='X'||X=='L'||X=='C'||X=='D'||X=='M');
}
int RomanToDec(infotype X)
/* I.S. X adalah digit romawi yang dikenali */
/* F.S. Mengembalikan nilai desimal dari X */
{
	if (X=='I')
	{
		return (1);
	}else if(X=='V') 
	{
		return(5);
	}else if(X=='X')
	{
		return(10);
	}else if(X=='L')
	{
		return(50);
	}else if(X=='C')
	{
		return(100);
	}else if(X=='D')
	{
		return(500);
	}else if(X=='M')
	{
		return(1000);
	}else
	{
		return(0);
	}
}

int Decimal(Roman R)
/* Mengembalikan nilai desimal dari bilangan romawi R */
/* I.S. R berisi digit-digit romawi yang dikenali dengan susunan yang benar,
        digit paling atas adalah digit terakhir */
/* F.S. Mengembalikan nilai desimal dari bilangan romawi R */
{
	//Kamus lokal
	infotype X1;
	int op1=0; //inisialisasi
	int op2=0;
	int total;
	int i;
	//Algoritma lokal
	if (!(IsEmpty(R))) 
	{
		i = R.TOP;
		total=0;
		for(;;)
		{
			if(IsEmpty(R))
			{
				break;
			}else
			{
				Pop(&R,&X1);
				i--;
				op1 = RomanToDec(X1);
				if (IsEmpty(R)||i==0)
				{
					total=total+op1;
					break;
				}else
				{
					Pop(&R,&X1);
					i--;
					op2 = RomanToDec(X1);
					if (op2 < op1)
					{
						total=total+op1-op2;
					}else
					{
						total=total+op1+op2;
					}
				}
			}
		}
	}
	return(total);
}


