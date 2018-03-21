// Main Menu
// Rifda 22 Nov 2017
#include <stdlib.h>
#include <conio.h>
#include "menu.h"
#include "matrix.h"
#include "save_load.h"

void about() {
//F.S menampilkan page about
char c;
	system("COLOR C");
	 printf("   _   ___  ___  _   _ _____ \n");
	 printf("  /_\\ | _ )/ _ \\| | | |_   _|\n");
	 printf(" / _ \\| _ \\ (_) | |_| | | |  \n");
	 printf("/_/ \\_\\___/\\___/ \\___/  |_|  \n");
                    
	printf("Game ini terinspirasi dari game Candy Crush Saga.\nGame ini dibuat dalam rangka Tugas Besar Matakuliah Algoritma dan Struktur Data, 2017\n");
	printf("	Programmer:\n");
	printf("\n");
	printf("    (\\___/)\n");
	printf("     )o o(   Rifda Annelies (18216001)\n");
	printf("    (_(_)_)\n");
	printf("\n");
	printf("   ('('~')')\n");
	printf("   ('|*_*|') Alessandro A(18216002)\n");
	printf("    (`\\=/`)\n");
	printf("    '¯\\,/¯'\n");
	printf("\n");
	printf("      .-.\n");
	printf("     (~ ~)\n");
	printf("     :o o:   Athur Naufan (18216003)\n");
	printf("    (((_)))\n");
	printf("      '-'\n");
	printf("\n");
	printf("    ,oOOOo,\n");
	printf("    o(\"\"\")o\n");
	printf("    o|* *|o  Al Varrel P (18216020)	\n");
	printf("    C((_))C\n");
	printf("      '='\n\n\n");
	printf("Press any key to go access menu...");
	getch();
	system("cls");
}

void howToPlay() {
//F.S menampilkan page how to play
 system("COLOR B");
 printf(" _  _  _____      __  _____ ___    ___ _      ___   __\n");
 printf("| || |/ _ \\ \\    / / |_   _/ _ \\  | _ \\ |    /_\\ \\ / /\n");
 printf("| __ | (_) \\ \\/\\/ /    | || (_) | |  _/ |__ / _ \\ V / \n");
 printf("|_||_|\\___/ \\_/\\_/     |_| \\___/  |_| |____/_/ \\_\\_|  \n");

	printf("	The game is played by swiping candies, \n");
	printf("	in any direction to create sets of 3 or more matching same color candies. \n");
	printf("	When matched, the candies will crush and shift the candies above them, \n");
	printf("	allowing you to accomplish a series of different goals. \n");
	printf("	If your candy match creating sets of 3 matching candy, you will receive 60.\n");
	printf("	If your candy match creating sets of 4 matching candy, you will receive 120.\n");
	printf("	If your candy match creating sets of 5 matching candy, you will receive 150.\n");
	printf("	Goal of this game is to reach score more than 5000 in 18 turns.\n");
	printf("Press any key to go access menu...");
	getch();
	system("cls");
}

void highScore(List LSkor) {
//F.S menampilkan page highscore

	system("COLOR E");
	printf(" _  _ ___ ___ _  _   ___  ___ ___  ___ ___ \n");
	printf("| || |_ _/ __| || | / __|/ __/ _ \\| _ \\ __|\n");
	printf("| __ || | (_ | __ | \\__ \\ (_| (_) |   / _| \n");
	printf("|_||_|___\\___|_||_| |___/\\___\\___/|_|_\\___|\n");
    PrintInfo(LSkor);                                        
	printf("Press any key to go access menu..."); 
	getch();
	system("cls");
}

void welcomeScrn(infolist *players){

	system("cls");
	system("COLOR 3");
	printf("\n\n\t  /$$$$$$   /$$$$$$  /$$   /$$ /$$$$$$$  /$$     /$$        /$$$$$$  /$$$$$$$  /$$   /$$  /$$$$$$  /$$   /$$\n");
	printf("\t /$$__  $$ /$$__  $$| $$$ | $$| $$__  $$|  $$   /$$/       /$$__  $$| $$__  $$| $$  | $$ /$$__  $$| $$  | $$\n");
	printf("\t| $$  \\__/| $$  \\ $$| $$$$| $$| $$  \\ $$ \\  $$ /$$/       | $$  \\__/| $$  \\ $$| $$  | $$| $$  \\__/| $$  | $$\n");
	printf("\t| $$      | $$$$$$$$| $$ $$ $$| $$  | $$  \\  $$$$/        | $$      | $$$$$$$/| $$  | $$|  $$$$$$ | $$$$$$$$\n");
	printf("\t| $$    $$| $$  | $$| $$\\  $$$| $$  | $$    | $$          | $$    $$| $$  \\ $$| $$  | $$ /$$  \\ $$| $$  | $$\n");
	printf("\t|  $$$$$$/| $$  | $$| $$ \\  $$| $$$$$$$/    | $$          |  $$$$$$/| $$  | $$|  $$$$$$/|  $$$$$$/| $$  | $$\n");
	printf("\t \\______/ |__/  |__/|__/  \\__/|_______/     |__/           \\______/ |__/  |__/ \\______/  \\______/ |__/  |__/\n");
    printf("\n\n\n\t Who's Playing : ");  
	inisialisasi(players);                                                                                                
}

void menu(int *choice) {
	Matrix m;
	char conf_exit;
	char pil;
	List L;

	system("cls");
	system("COLOR F");
	printf(" __  __ ___ _  _ _   _ \n");
	printf("|  \\/  | __| \\| | | | |\n");
	printf("| |\\/| | _|| .` | |_| |\n");
	printf("|_|  |_|___|_|\\_|\\___/ \n\n\n");

	printf("1. Play\n");
	printf("2. How To Play\n");
	printf("3. Highscore\n");
	printf("4. About\n");
	printf("5. Quit\n");

	do {
		printf("Your choice: ");
		scanf(" %c",&pil);
		if (pil<'1' || pil>'5') {
			printf("Invalid Input!\nMasukkan Angka 1-5!\n");
		}
	} while (pil<'1' || pil>'5');
	*choice = pil-'0';
}


