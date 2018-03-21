#include <stdlib.h>
#include <stdio.h>
#include "dadu.h"

/* ********* Prototype ********* */
bool IsEmpty (Queue Q){
/* Mengirim true jika Q kosong: lihat definisi di atas */
	return (Head(Q)==Nil) && (Tail(Q)==Nil);
}

bool IsFull (Queue Q){
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
	return (Tail(Q)==MaxEl(Q));
}

int NBElmt (Queue Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
	if (IsEmpty(Q)){
		return 0;
	}
	else{
		return (Tail(Q) - Head(Q) + 1);
	}
}

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max){
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
	Q->T = (infotype*) malloc((Max+1)*sizeof(infotype));
	if(Q->T != NULL){
		MaxEl(*Q) = Max;
		Head(*Q) = Nil;
		Tail(*Q) = Nil;
	}else{
		MaxEl(*Q) = Nil;
	}
}

/* *** Destruktor *** */
void DeAlokasi(Queue * Q){
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
	MaxEl(*Q) = 0;
	free(Q->T);
}

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X){
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" */
	if (IsEmpty(*Q)){
		Head(*Q) = 1;
	}
	Tail(*Q)++;
	InfoTail(*Q) = X;
}

void Del (Queue * Q, infotype * X){
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., 
			jika Q masih isi, elemen setelah HEAD digeser ke "kiri",
			HEAD diset tetap = 1, TAIL = TAIL - 1;
			Q mungkin kosong (HEAD = TAIL = Nil) */
	*X = InfoHead(*Q);
	for (int i = Head(*Q); i < Tail(*Q) ; ++i){
		Q->T[i] = Q->T[i+1]; 
	}
	Tail(*Q)--;
	if(Tail(*Q) == Nil){
		Head(*Q) = Nil;
	}
}
/* MODUL Queue TAMBAHAN */

int IdxEff(Queue Q){
/* mengembalikan nilai indeks efektif tabel / jumlah elemen yang ada */
	return NBElmt(Q);
}

bool IsGameOver(Queue Q){
/* mengembalikan true apabila kondisi permainan berakhir terpenuhi, yaitu
   salah satu pemain mendapatkan skor sebesar 3 atau hanya tinggal satu
   pemain yang bermain */
	infotype p;
	if(NBElmt(Q) == 1){
			return true;
	}else{
		do{
			Del(&Q, &p);
			if(p.skor == 3){
				return true;
			}
		}while(!IsEmpty(Q));
		return false;
	}
}
void CreateQueuePemain(Queue *Q,int Maks){
 //I.S : Queue kosong dengan alokasi Min 2 dan Maks 6
 // F.S : Menghasilkan Q yang berisi informasi seluruh pemain berupa nama
   //dengan skor awal = 0
    infotype p;
	for(int i= 1; i<=Maks; i++){
		p.Nama = malloc(256*(sizeof(char)));
		scanf("%255s", p.Nama);
		p.skor = 0;
		Add(Q,p);
	}
}

void ChangeTurn(Queue *Q){
/* I.S : Queue berisi minimal 2 elemen
   F.S : Head(Q) diganti menjadi pemain yang berada di antrian selanjutnya
   Sedangkan untuk Head(Q) di awal dipindah ke antrian paling
   belakang / Tail(Q) */
   infotype p;
   Del(Q, &p);
   Add(Q, p);
}

void PrintSkor(Queue Q){
/* I.S : Queue tidak kosong
   F.S : Menampilkan seluruh skor pemain sesuai dengan format <nama> <skor> */
	for(int i = Head(Q); i<=Tail(Q); i++){
		printf("%s %d\n", Q.T[i].Nama, Q.T[i].skor);
	}
}
void GenerateRandom(int *X) {
    *X = rand() % 6 + 1;
}
