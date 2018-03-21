#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"
#include "save_load.h"
#include "menu.h"
#include "stacklist.h"

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}


void Play(infolist *player);

void gameOverScrn(infolist *player);

int main() {
	/* KAMUS LOKAL */
	infolist player;
	List LSkor;
	int pil;
	char conf_exit;

	/* ALGORITMA */
	First(LSkor)=Nil;
	load(&LSkor, "pemain.txt");
	srand(time(NULL));
	welcomeScrn(&player);
	do{
		menu(&pil); 

		//masuk ke menu pilihan doi
		switch (pil) {
			case (1): 
				Play(&player);
				updateSkor(&LSkor,player);
				break;

			case (2):
				system("cls");
				howToPlay();
				break;

			case (3):
				system("cls");
				highScore(LSkor);
				break;

			case (4):
				system("cls");
				about();
				break;

			case (5):
				do{
					printf("Kamu yakin mau keluar? (Y/N)\n");
					scanf(" %c",&conf_exit);
					if (conf_exit=='Y'|| conf_exit=='y'){
						printf("GOODBYE, %s! :D\n",player.name);
						save(&LSkor,"pemain.txt");
					} else if (conf_exit=='N'|| conf_exit=='n'){
						pil = 0;
					} else{
						printf("Input Salah!\n");
					}
				} while (conf_exit!='N' && conf_exit!='Y' && conf_exit!='y' && conf_exit!='n');
				break;
		}
		
	}while(pil!=5);


	// printf("chain5 : %d\n", c5);
	
	return 0;
}

void Play(infolist *player){
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

			printf("\n\n\n\t\t\t███████╗██╗  ██╗██╗   ██╗███████╗███████╗██╗     ███████╗\n");
			printf("\t\t\t██╔════╝██║  ██║██║   ██║██╔════╝██╔════╝██║     ██╔════╝\n");
			printf("\t\t\t███████╗███████║██║   ██║█████╗  █████╗  ██║     █████╗  \n");
			printf("\t\t\t╚════██║██╔══██║██║   ██║██╔══╝  ██╔══╝  ██║     ██╔══╝  \n");
			printf("\t\t\t███████║██║  ██║╚██████╔╝██║     ██║     ███████╗███████╗\n");
			printf("\t\t\t╚══════╝╚═╝  ╚═╝ ╚═════╝ ╚═╝     ╚═╝     ╚══════╝╚══════╝\n");
			delay(1000);
			do{
				AcakIsi(m);
				detectPossibleSwap(m, &ori, &right, &down);
			}while(IsEmpty2(ori));
		}
		
		
		PrintKotak(m, turn, player);
		Move(m, ori, right, down);
		turn--;
		system("cls");
		PrintKotak(m, turn, player);
		delay(500);
		GetChain(&S, m, &c3, &c4, &c5);
		do{
			Update(&S, m, &score, c3, c4, c5);
			(*player).skor = score;
			system("cls");
			PrintKotak(m, turn, player);
			printf("\n");
			printf("\t\t\t _______  _______  _______  __   __   __  \n");
			printf("\t\t\t|       ||       ||       ||  | |  | |  | \n");
			printf("\t\t\t|    _  ||   _   ||    _  ||  | |  | |  | \n");
			printf("\t\t\t|   |_| ||  | |  ||   |_| ||  | |  | |  | \n");
			printf("\t\t\t|    ___||  |_|  ||    ___||__| |__| |__| \n");
			printf("\t\t\t|   |    |       ||   |     __   __   __  \n");
			printf("\t\t\t|___|    |_______||___|    |__| |__| |__| \n");
			delay(1000);
			FallingCandy(m);
			system("cls");
			PrintKotak(m, turn, player);
			delay(1000);
			RemoveZero(m);
			system("cls");
			PrintKotak(m, turn, player);
			delay(1000);
			GetChain(&S, m, &c3, &c4, &c5);
		}while(!IsEmpty2(S));
	}while(turn>0);
	printf("SCORE : %d\n", score);
	(*player).skor = score;
	system("cls");
 	gameOverScrn(player);

}


void gameOverScrn(infolist *player){

if (player.score>5000) {
	printf("██╗   ██╗ ██████╗ ██╗   ██╗    ██╗    ██╗██╗███╗   ██╗\n");
	printf("╚██╗ ██╔╝██╔═══██╗██║   ██║    ██║    ██║██║████╗  ██║\n");
	printf(" ╚████╔╝ ██║   ██║██║   ██║    ██║ █╗ ██║██║██╔██╗ ██║\n");
	printf("  ╚██╔╝  ██║   ██║██║   ██║    ██║███╗██║██║██║╚██╗██║\n");
	printf("   ██║   ╚██████╔╝╚██████╔╝    ╚███╔███╔╝██║██║ ╚████║\n");
	printf("   ╚═╝    ╚═════╝  ╚═════╝      ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝\n");
	print("						Your Score: %d\n",player->score);

} else {

	printf("██╗   ██╗ ██████╗ ██╗   ██╗    ██╗      ██████╗ ███████╗███████╗\n");
	printf("╚██╗ ██╔╝██╔═══██╗██║   ██║    ██║     ██╔═══██╗██╔════╝██╔════╝\n");
	printf(" ╚████╔╝ ██║   ██║██║   ██║    ██║     ██║   ██║███████╗█████╗  \n");
	printf("  ╚██╔╝  ██║   ██║██║   ██║    ██║     ██║   ██║╚════██║██╔══╝  \n");
	printf("   ██║   ╚██████╔╝╚██████╔╝    ███████╗╚██████╔╝███████║███████╗\n");
	printf("   ╚═╝    ╚═════╝  ╚═════╝     ╚══════╝ ╚═════╝ ╚══════╝╚══════╝\n");
	print("						Your Score: %d\n",player->score);
	}

do {
	printf("				Play again? (Y/N)\n");
	scanf(" %c",pa);
	if (pa=='y' || pa=='Y') {
		Play(player);
	} 
} while (pa!='y' && pa!='Y' && pa!='N' &&pa!='n');
	
}
                                                               

