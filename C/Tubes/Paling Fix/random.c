#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void Play(){
	Matrix m;
	Stack S, ori, right, down;
	int c3, c4, c5, score, turn;
	score = 0;
	turn = 15;
	AcakIsi(m);
 
	do{
		system("cls");
		detectPossibleSwap(m, &ori, &right, &down);
		if(IsEmpty2(ori)){
			printf("ntar lu buat shuffle\n");
			delay(1000);
			do{
				AcakIsi(m);
				detectPossibleSwap(m, &ori, &right, &down);
			}while(IsEmpty2(ori));
		}
		
		printf("turn : %d\n", turn);
		PrintKotak(m);
		Move(m, ori, right, down);
		turn--;
		system("cls");
		PrintKotak(m);
		delay(500);
		GetChain(&S, m, &c3, &c4, &c5);
		do{
			Update(&S, m, &score, c3, c4, c5);
			system("cls");
			PrintKotak(m);
			printf("\n");
			printf(" _______  _______  _______  __   __   __  \n");
			printf("|       ||       ||       ||  | |  | |  | \n");
			printf("|    _  ||   _   ||    _  ||  | |  | |  | \n");
			printf("|   |_| ||  | |  ||   |_| ||  | |  | |  | \n");
			printf("|    ___||  |_|  ||    ___||__| |__| |__| \n");
			printf("|   |    |       ||   |     __   __   __  \n");
			printf("|___|    |_______||___|    |__| |__| |__| \n");
			delay(1000);
			FallingCandy(m);
			system("cls");
			PrintKotak(m);
			delay(1000);
			RemoveZero(m);
			system("cls");
			PrintKotak(m);
			delay(1000);
			GetChain(&S, m, &c3, &c4, &c5);
		}while(!IsEmpty2(S));
	}while(turn>=0);
	printf("SCORE : %d\n", score);
}

int main(){
	Matrix m;
	Stack S, ori, right, down;
	int c3, c4, c5, score;

	Play();
}