/* file:stack.c */
#include "stack.h"

/* Definisi stack S kosong : S.TOP = Nil */
/* S.TOP = jumlah element stack */
/* S.T[S.TOP-1] = element paling atas */


/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
{
	(*S).TOP = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
bool IsEmpty(Stack S)
/* Mengirim true jika Stack kosong*/
/* Ciri stack kosong : TOP bernilai Nil */
{
	return (S.TOP == Nil);
}
bool IsFull(Stack S)
/* Mengirim true jika stack S penuh */
/* Ciri stack penuh : TOP bernilai MaxEl */
{
	return (S.TOP == MaxEl);
}
/* ********** Operator Dasar Stack ********* */
void Push(Stack *S, infotype X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S tidak penuh */
/*F.S. X menjadi element TOP yang baru, TOP bertambah 1 */
{
	(*S).TOP++;
	(*S).T[(*S).TOP-1] = X;
}
void Pop (Stack *S, infotype *X)
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
	(*X) = (*S).T[(*S).TOP-1];
	(*S).TOP--;
}

/*{ MODUL STACK TAMBAHAN}*/
bool IsOperator (infotype X)
/*{ true jika X adalah operator } */
{
	return(X=='+'||X=='-'||X=='*'||X=='/');
}
bool IsDigit (infotype X)
/*{ true jika X adalah operator } */
{
	return(X>='0' && X<='9');
}
int Hitung(Stack *S)
/* Mengembalikan hasil operasi kalkulator postfix*/
/* Mengembalikan -999 jika terjadi kesalahan operasi (misal: nilai tak hingga, tidak terdefinisi, dll)  */
/* I.S. S sudah terdefinisi */
/* F.S. *S mungkin kosong. Semua token yang sudah dioperasikan dihapus dari stack */
{
	//kamus lokal
	int total=0; //inisialisasi
	int op1=0;
	int op2=0;
	infotype X;
	//Algoritma lokal
	if(!(IsEmpty(*S)))
	{
		Pop(S,&X);
		if (IsOperator(X)&&IsEmpty(*S))
		{
			return(-999);
		}else
		{
			if(IsOperator(X))
			{
				if (X=='*')
				{
					Pop(S,&X);
					if(IsDigit(X))
					{
						if(X=='0')
						{ 
							op1=0;
						}else if(X=='1')
						{
							op1=1;
						}else if(X=='2')
						{
							op1=2;
						}else if(X=='3')
						{
							op1=3;
						}else if(X=='4')
						{
							op1=4;
						}else if(X=='5')
						{
							op1=5;
						}else if(X=='6')
						{
							op1=6;
						}else if(X=='7')
						{
							op1=7;
						}else if(X=='8')
						{
							op1=8;
						}else if(X=='9')
						{
							op1=9;
						}
					}else
					{
						op1=Hitung(S);
					}
					Pop(S,&X);
					if(IsDigit(X))
					{
						if(X=='0')
						{ 
							op2=0;
						}else if(X=='1')
						{
							op2=1;
						}else if(X=='2')
						{
							op2=2;
						}else if(X=='3')
						{
							op2=3;
						}else if(X=='4')
						{
							op2=4;
						}else if(X=='5')
						{
							op2=5;
						}else if(X=='6')
						{
							op2=6;
						}else if(X=='7')
						{
							op2=7;
						}else if(X=='8')
						{
							op2=8;
						}else if(X=='9')
						{
							op2=9;
						}
					}
					total=total+(op1*op2);
				}else if (X=='+')
				{
					Pop(S,&X);
					if(IsDigit(X))
					{
						if(X=='0')
						{ 
							op1=0;
						}else if(X=='1')
						{
							op1=1;
						}else if(X=='2')
						{
							op1=2;
						}else if(X=='3')
						{
							op1=3;
						}else if(X=='4')
						{
							op1=4;
						}else if(X=='5')
						{
							op1=5;
						}else if(X=='6')
						{
							op1=6;
						}else if(X=='7')
						{
							op1=7;
						}else if(X=='8')
						{
							op1=8;
						}else if(X=='9')
						{
							op1=9;
						}
					}else
					{
						op1=Hitung(S);
					}
					Pop(S,&X);
					if(IsDigit(X))
					{
						if(X=='0')
						{ 
							op2=0;
						}else if(X=='1')
						{
							op2=1;
						}else if(X=='2')
						{
							op2=2;
						}else if(X=='3')
						{
							op2=3;
						}else if(X=='4')
						{
							op2=4;
						}else if(X=='5')
						{
							op2=5;
						}else if(X=='6')
						{
							op2=6;
						}else if(X=='7')
						{
							op2=7;
						}else if(X=='8')
						{
							op2=8;
						}else if(X=='9')
						{
							op2=9;
						}
					}
					total=total+(op1+op2);
				}else if (X=='-')
				{
					Pop(S,&X);
					if(IsDigit(X))
					{
						if(X=='0')
						{ 
							op1=0;
						}else if(X=='1')
						{
							op1=1;
						}else if(X=='2')
						{
							op1=2;
						}else if(X=='3')
						{
							op1=3;
						}else if(X=='4')
						{
							op1=4;
						}else if(X=='5')
						{
							op1=5;
						}else if(X=='6')
						{
							op1=6;
						}else if(X=='7')
						{
							op1=7;
						}else if(X=='8')
						{
							op1=8;
						}else if(X=='9')
						{
							op1=9;
						}
					}else
					{
						op1=Hitung(S);
					}
					Pop(S,&X);
					if(IsDigit(X))
					{
						if(X=='0')
						{ 
							op2=0;
						}else if(X=='1')
						{
							op2=1;
						}else if(X=='2')
						{
							op2=2;
						}else if(X=='3')
						{
							op2=3;
						}else if(X=='4')
						{
							op2=4;
						}else if(X=='5')
						{
							op2=5;
						}else if(X=='6')
						{
							op2=6;
						}else if(X=='7')
						{
							op2=7;
						}else if(X=='8')
						{
							op2=8;
						}else if(X=='9')
						{
							op2=9;
						}
					}
					total=total+(op1-op2);
				}else if (X=='/')
				{
					Pop(S,&X);
					if(IsDigit(X))
					{
						if(X=='0')
						{ 
							op1=0;
						}else if(X=='1')
						{
							op1=1;
						}else if(X=='2')
						{
							op1=2;
						}else if(X=='3')
						{
							op1=3;
						}else if(X=='4')
						{
							op1=4;
						}else if(X=='5')
						{
							op1=5;
						}else if(X=='6')
						{
							op1=6;
						}else if(X=='7')
						{
							op1=7;
						}else if(X=='8')
						{
							op1=8;
						}else if(X=='9')
						{
							op1=9;
						}
					}else
					{
						op1=Hitung(S);
					}
					Pop(S,&X);
					if(IsDigit(X))
					{
						if(X=='0')
						{ 
							op2=0;
						}else if(X=='1')
							{
							op2=1;
						}else if(X=='2')
						{
							op2=2;
						}else if(X=='3')
						{
							op2=3;
						}else if(X=='4')
						{
							op2=4;
						}else if(X=='5')
						{
							op2=5;
						}else if(X=='6')
						{
							op2=6;
						}else if(X=='7')
						{
							op2=7;
						}else if(X=='8')
						{
							op2=8;
						}else if(X=='9')
						{
							op2=9;
						}
					}
					total=total+(op1/op2);
				}
			}else if(IsDigit(X))
			{
				if(X=='0')
				{ 
						op2=0;
					}else if(X=='1')
					{
						op2=1;
					}else if(X=='2')
					{
						op2=2;
					}else if(X=='3')
					{
						op2=3;
					}else if(X=='4')
					{
						op2=4;
					}else if(X=='5')
					{
						op2=5;
					}else if(X=='6')
					{
						op2=6;
					}else if(X=='7')
					{
						op2=7;
					}else if(X=='8')
					{
						op2=8;
					}else if(X=='9')
					{
						op2=9;
					}
					total=total*10 +op2;
				}
			return(total);
		}
	}else 
	{
		return(-999);
	}
}




