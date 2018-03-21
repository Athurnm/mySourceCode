#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>
#include <stdlib.h>
#include "stacklist.h"
#include "save_load.h"

#define Nmax 8
typedef int candy;
typedef candy Matrix[Nmax][Nmax];

candy smartRandom(Matrix m, int i, int j);

void swap(candy *a, candy *b);

void AcakIsi (Matrix m);

void PrintKotak (Matrix m, int turn, infolist * player);

void Update(Stack *S, Matrix m, int *score, int c3, int c4, int c5);

void FallingCandy(Matrix m);

void RemoveZero(Matrix m);

void GetChain(Stack *S, Matrix m, int *chain3, int*chain4, int*chain5);

void Move(Matrix M, Stack ori, Stack right, Stack down);

bool isValidMove(Point P1, Point P2, char dir, Stack ori, Stack right, Stack down);

bool IsChain(Matrix m, int baris, int kolom);

void detectPossibleSwap(Matrix m, Stack *ori, Stack *right, Stack *down);

#endif