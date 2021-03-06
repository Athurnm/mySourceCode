#include <stdlib.h>
#include <stdio.h>
#include "listrek.h"
#include "boolean.h"
/* Deklarasi  nama untuk variabel kerja */
/*  	L : List */
/*  	P : address 	*/
/* Maka penulisan First(L) menjadi L */
/*                P.info menjadi Info(P); P.next menjadi Next(P) */

/* Selektor */
#define Info(P) (P)->info
#define Next(P) (P)->next

/* *** Manajemen Memori *** */
address Alokasi (infotype X){
  address P = (address) malloc(1*sizeof(ElmtList));

  if (P!=Nil){
    Info(P) = X;
    Next(P) = Nil;
    return P;
  }
  else {
    return P;
  }

};
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P,
  maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address P){
  free(P);
};
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/* *** Primitif-primitif yang harus direalisasikan *** */

/* Pemeriksaan Kondisi List */
int IsEmpty(List L){
  return L==Nil;
};
/* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */
int IsOneElmt(List L){
  if (IsEmpty(L)){
    return 0;
  }
  else{
    return Next(L)==Nil;
  }
};
/* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */

/* *** Selektor *** */
infotype FirstElmt (List L){
  return Info(L);
};
/* Mengirimkan elemen pertama sebuah list L yang tidak kosong */
List Tail(List L){
  return Next(L);
};
/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */

/* *** Konstruktor *** */
List Konso(infotype e, List L){
  address P = Alokasi(e);
  if (P!=Nil){
    Next(P) = L;
    L = P;
    return L;
  }
  else {
    return L;
  }
};
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya.
e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L. */
List KonsB(List L, infotype e){
  address P = Alokasi(e);
    if (P!=Nil){
      if(IsEmpty(L)){
        return Alokasi(e);
      }
      else {
        Next(L) = KonsB(Tail(L),e);

      }
  }
  return L;

};
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */

/* *** Operasi Lain *** */
List Copy (List L){
  if (IsEmpty(L)){
    return Nil;
  }
  else{
    return Konso(FirstElmt(L),Copy(Tail(L)));
  }

};
/* Mengirimkan salinan list L (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan L */
void MCopy (List Lin, List *Lout){
  List LTemp;

  if (IsEmpty(Lin)){
    *Lout = Nil;
  }
  else {
    MCopy(Tail(Lin),&LTemp);
    *Lout = Konso(FirstElmt(Lin),LTemp);
  }
};
/* I.S. Lin terdefinisi */
/* F.S. Lout berisi salinan dari Lin */
/* Proses : menyalin Lin ke Lout */
List Concat (List L1, List L2){
  if (IsEmpty(L1)){
    return Copy(L2);
  }
  else {
    return (Konso(FirstElmt(L1),Concat(Tail(L1),L2)));
  }
};
/* Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan Nil */
void MConcat (List L1, List L2, List *LHsl){
  List LTemp;
  if (IsEmpty(L1)){
    *LHsl = Copy(L2);
  }
  else {
    MConcat(Tail(L1),L2,&LTemp);
    *LHsl = Konso(FirstElmt(L1),LTemp);
  }
};
/* I.S. L1, L2 terdefinisi */
/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
/* Proses : Menghasilkan salinan hasil konkatenasi list L1 dan L2 */
void PrintList (List L){
  if (IsEmpty(L)){

  }
  else {
    printf("%d\n",Info(L));
    PrintList(Tail(L));
  }
};
/* I.S. L terdefinisi. */
/* F.S. Setiap elemen list dicetak. */
int NbElmtList (List L){
  if (IsEmpty(L)){
    return 0;
  }
  else {
    return 1 + NbElmtList(Tail(L));
  }
};
/* Mengirimkan banyaknya elemen list L, Nol jika L kosong */
boolean Search (List L, infotype X){
  if (IsEmpty(L)){
    return false;
  }
  else {
    if (Info(L)==X){
      return true;
    }
    else{
      return Search(Tail(L),X);
    }
  }
  
  
/* Mengirim true jika X adalah anggota list, false jika tidak */

};