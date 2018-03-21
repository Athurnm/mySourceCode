/* Nama : Athur Naufan M */
/* Nama file : jam.h 	*/
/* deskripsi : file header dari jam */

#include <stdio.h>
#include "boolean.h"

#ifndef jam_H
#define jam_H

/* notasi akses */
#define Hour(J) (J).HH
#define Minute(J) (J).MM
#define Second(J) (J).SS
typedef struct
{
	int HH;
	int MM;
	int SS;
} Jam;

/* Konstruktor */
Jam makeJam (int H, int M, int S);
// Membentuk Jam dari H,M, dan S yang valid

/* Validator */
bool isJValid(int H, int M, int S);
// mengirim true jika input valid

/* Baca dan Tulis Jam */

void bacaJam(Jam *J);
/* I.S. : J tak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam valid */
/* Proses : mengulang pembacaan komponen H,M,S hingga valid */

void tulisJam(Jam J);
