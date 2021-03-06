/* Filename : save_load.h */
#ifndef save_load_h
#define save_load_h 

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>

#define Nil NULL

typedef struct {
	char name[50];
	int skor;
} infolist;
typedef struct tElmtlist *addressL;
typedef struct tElmtlist { 
	infolist inpo;
	addressL nextl;
} ElmtList;
typedef struct {
	addressL First;
} List;
typedef char name[50];

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan addressL P dapat diacu inpo(P), NextL(P) */
/* Elemen terakhir list : jika addressLnya Last, maka NextL(Last)=Nil */

#define inpo(P) (P)->inpo
#define NextL(P) (P)->nextl
#define First(L) (L).First

bool IsEmptyFile(FILE *file);
/* prekondisi : File eksternal dapat kosong dapat berisi */
/* output : true jika file eksternal kosong */

bool IsNameEq(name N1,name N2);
/* prekondisi : N1 dan N2 terdefinisi */
/* output : Apabila N1 = N2 mengirim true */

void inisialisasi (infolist *player);
/* I.S : player belum berisi apa-apa, nama dan skor masih kosong */
/* F.S : player terisi nama pemain dan skor 0 */
/* Digunakan untuk saat login */

void load (List *L, char filename[25]);
/* I.S : file merupakan file of char, file dapat kosong dapat terisi */
/* F.S : seluruh data yang terdapat di file tersalin kedalam list */

void save(List *L, char filename[25]);
/* I.S : file dapat terisi sebelumnya, list tidak kosong */
/* F.S : seluruh data pada list tersalin kedalam file */

int convertSkor (int chain3, int chain4, int chain5);
/* prekondisi : chain3, chain4, dan chain5 terdefinisi akan dihitung skornya */
/* output : mengeluarkan hasil konversi chain menjadi skor */

void updateSkor (List *L, infolist player);
/* I.S : List terurut berdasarkan skor mengecil, list bisa kosong, 
nama player sudah ada, dan skor ada*/
/* F.S : data player yang sudah terisi nama dan skor diinput kedalam list */

/****************** PROSES SEMUA ELEMEN LIST ******************/
int NbElmt (List L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
void PrintInfo (List L);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke bawah dalam bentuk tabel */
/* Jika list kosong : menulis tidak ada highscore */

void InsVFirst (List *L, infolist X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

void DelVFirst (List *L, infolist *X);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */

void InsVLast (List *L, infolist X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, addressL P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressL P sebagai elemen pertama */

void InsertAfter (List *L, addressL P, addressL Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

void InsertLast (List *L, addressL P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/****************** TEST LIST KOSONG ******************/
bool IsEmpty (List L);
/* Mengirim true jika list kosong */

/****************** Manajemen Memori ******************/
addressL Alokasi (infolist X);
/* Mengirimkan addressL hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressL tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, NextL(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (addressL *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressL P */
#endif

