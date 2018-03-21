/* filename : save_load.c */
#include "save_load.h"

bool IsEmptyFile(FILE *file)
/* prekondisi : File eksternal dapat kosong dapat berisi */
/* output : true jika file eksternal kosong */
{
	//Kamus lokal
    long savedOffset = ftell(file); //variabel penampung lokasi file saat ini
	//Algoritma lokal
    fseek(file, 0, SEEK_END); //fungsi untuk mengecek eof pada akhir

    if (ftell(file) == 0){ //ftell(file) menunjukan lokasi terbaru
        return true;
    }

    fseek(file, savedOffset, SEEK_SET); //mengembalikan lokasi semula
    return false;
}

bool IsNameEq (name N1,name N2)
/* prekondisi : N1 dan N2 terdefinisi */
/* output : Apabila N1 = N2 mengirim true */
{
	//kamus lokal
	int i,length1,length2;
	bool found = false;
	//Algoritma lokal
	i = 0;
	length1 = 0;
	while (N1[i]!='\0')
	{
		length1++;
		i++;
	}
	i=0;
	length2=0;
	while (N2[i]!='\0')
	{
		length2++;
		i++;
	}
	if (length1 != length2)
		found = true;
	else
	{
		i=0;
		while (i<=length1&&!found)
		{
			if (N1[i] != N2[i])
				found = true;
			else 
				i++;
		}
	}
	return (!found);
}
void inisialisasi (infolist *player)
/* I.S : player belum berisi apa-apa, nama dan skor masih kosong. Digunakan saat login */
/* F.S : player terisi nama pemain dan skor 0 */
/* Digunakan untuk saat login */
{
	//algoritma lokal
	scanf("%49s", (*player).name);
	(*player).skor = 0;
}

void load (List *L, char filename[25])
/* I.S : file merupakan file of char, file dapat kosong dapat terisi */
/* F.S : seluruh data yang terdapat di file tersalin kedalam list */
{
	//Kamus lokal
	FILE *Fin;
	infolist x;
	char buf[100];
	//Algoritma lokal
	//inisialisasi file
	Fin = fopen(filename,"r+");
	
	if (!Fin) //apabila gagal baca file
	{
		fprintf(stderr,"Gagal membaca file\n");
		exit(1);
	}
	if (!IsEmptyFile(Fin))
	{
		while (!feof(Fin))
		{
			fgets(buf,100,Fin);
			sscanf(buf, "%s %d\n", x.name, &x.skor);
			InsVLast(L, x);
		}
	}
	
	fclose(Fin);
}
void save(List *L, char filename[25])
/* I.S : file dapat terisi sebelumnya, list tidak kosong */
/* F.S : seluruh data pada list tersalin kedalam file */
{
	//Kamus lokal
	FILE *Fout;
	infolist x;
	int count = NbElmt(*L),i = 1,total=0;
	//Algoritma lokal
	//inisialisasi file
	Fout = fopen(filename,"w");
	while (!IsEmpty(*L))
	{
		DelVFirst(L,&x);
		i++;
		if (i<=count)
			fprintf(Fout, "%s %d\n",x.name,x.skor);
		else
			fprintf(Fout, "%s %d",x.name,x.skor);
	}
	fclose(Fout);
}
int convertSkor (int chain3, int chain4, int chain5)
/* prekondisi : chain3, chain4, dan chain5 terdefinisi akan dihitung skornya */
/* output : mengeluarkan hasil konversi chain menjadi skor */
{
	return(chain3*60 + chain4*120 + chain5*240);
}
void updateSkor (List *L, infolist player)
/* I.S : List terurut berdasarkan skor mengecil, list bisa kosong, 
player nama sudah ada, dan skor ada*/
/* F.S : data player yang sudah terisi nama dan skor diinput kedalam list */
{
	//Kamus lokal
	addressL Px,P,Prec;
	bool found,scrute;
	//Algoritma lokal
	if (IsEmpty(*L))
	{
		InsVFirst(L, player);
	}else
	{
		Px = Alokasi(player);
		//Cari apakah player.nama ada di List 
		P =  First (*L);
		Prec = Nil;
		found = false;
		while (P!=Nil && !found)
		{
			if (IsNameEq(inpo(P).name,inpo(Px).name))
				found = true;
			else 
			{
				Prec = P;
				P = NextL(P);
			}
		}
		if (P!=Nil) //player.name ada
		{
			if (inpo(P).skor < inpo(Px).skor)
			{
				if (Prec != Nil)
				{
					NextL(Prec)=NextL(P);
					NextL(P)=Nil;
				}
				else //Prec = Nil
				{
					NextL(Px)=NextL(P);
					First(*L)=Px;
					scrute = true;
				}
				Dealokasi(&P);
			}else
				scrute = true;
		}
		//Mencari Lokasi P yang sesuai dan memasukan Px sebelum P
		if (!scrute)
		{
			P=First(*L);
			Prec = Nil;
			found = false;
			while (P!= Nil && !found)
			{
				if (inpo(P).skor < inpo(Px).skor)
					found = true;
				else
				{
					Prec = P;
					P = NextL(P);
				}
			}
			if (found && Prec != Nil)
			{
				NextL(Px)=NextL(Prec);
				NextL(Prec)=Px;
			}else if (found && Prec == Nil)
			{
				NextL(Px)=P;
				First(*L)=Px;
			}else 
			{
				NextL(Prec) = Px;
			}	
		}
				
	}
}
/****************** PROSES SEMUA ELEMEN LIST ******************/
int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
	//Kamus lokal
	addressL P = First(L);
	int Count = 0;
	//Algoritma lokal
	if(IsEmpty(L))
		return Count;
	else
	{
		do
		{
			Count++;
			P = NextL(P);
		}while(P!= Nil);
		return Count;
	}
}
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke bawah dalam bentuk tabel */
/* Jika list kosong : menulis tidak ada highscore */
{
	//Kamus lokal
	addressL P = First(L);
	int i,countSpace1,countSpace2,count;
	//Algoritma lokal
	if (IsEmpty(L))
	{
		printf("Tidak ada data highscore\n");
	}else
	{
		count = 0;
		printf("+-------------------------+-------+\n");
		printf("|Nama                     |Skor   |\n");
		printf("+-------------------------+-------+\n");
		do
		{
			printf("|%s",inpo(P).name);
			for(i=0;inpo(P).name[i]!='\0';++i);
			countSpace1 = 25 - i;
			for(i=0;i<countSpace1;i++)
				printf(" ");
			printf("|%d",inpo(P).skor);
			countSpace2 = floor(log10(abs(inpo(P).skor)))+1;
			countSpace2 = 7 - countSpace2;
			for(i=0;i<countSpace2;i++)
				printf(" ");
			printf("|\n");
			P = NextL(P); //NextL elemen
			count++;
		}while (P!=Nil&&count<10); //sudah tercapai elemen sebelum terakhir
		printf("+-------------------------+-------+\n");
	}
}

void InsVFirst (List *L, infolist X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	//kamus lokal
	addressL P = Alokasi(X);
	
	//Algoritma lokal
	if (P != Nil)
	{
		NextL(P) = First(*L);
		First(*L) = P;
	}
}

void DelVFirst (List *L, infolist *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai inpo disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	//Kamus lokal
	addressL P = First(*L) ;
	//Algoritma lokal
	(*X) = inpo(P);
	First(*L)=NextL(P);
	Dealokasi(&P);
}

void InsVLast (List *L, infolist X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	//kamus lokal
	addressL P = Alokasi(X);
	//Algoritma lokal
	if (P != Nil)
	{
		InsertLast(L,P);
	}
}

/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, addressL P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressL P sebagai elemen pertama */
{
	//Kamus lokal
	//Kosong
	//Algoritma lokal
	NextL(P)=First(*L);
	First(*L)=P;
}
void InsertAfter (List *L, addressL P, addressL Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	//Kamus lokal
	//Kosong
	//Algoritma lokal
	NextL(P)=NextL(Prec);
	NextL(Prec)=P;
}
void InsertLast (List *L, addressL P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	//Kamus lokal
	addressL Px = First(*L);
	//Algoritma lokal
	if(IsEmpty(*L))
	{
		InsertFirst(L,P);
	}else
	{
		while (NextL(Px)!=Nil)
			{
				Px = NextL(Px); //NextL Element
			}//udah sampai ujung
			InsertAfter(L,P,Px);
	}
}
/****************** TEST LIST KOSONG ******************/
bool IsEmpty (List L)
/* Mengirim true jika list kosong */
{
	//Kamus lokal
	//Kosong
	//Algoritma lokal
	return(First(L)==Nil);
}

/****************** Manajemen Memori ******************/
addressL Alokasi (infolist X)
/* Mengirimkan addressL hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressL tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, NextL(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	//Kamus lokal
	addressL P = (addressL) malloc (sizeof (ElmtList));
	//Algoritma lokal
	if (P == Nil) 
	{
		return (Nil);
	}else
	{
		inpo(P)=X;
		NextL(P)=Nil;
		return(P);
	}
}
void Dealokasi (addressL *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressL P */
{
	//Kamus lokal
	//kosong
	//Algoritma lokal
	free(*P);
}