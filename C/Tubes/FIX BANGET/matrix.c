#include "matrix.h"
#include <conio.h>
#include <time.h>
#include "rlutil.h"
#include "save_load.h"

candy smartRandom(Matrix m, int i, int j){
// Generate candy random yang tidak membentuk chain 
	candy r;
	if((j>1) && (i>1)){
		do{
			r = (rand() % 5) + 1;
		}while((m[i][j-1] == r && m[i][j-2]==r) || (m[i-1][j] == r && m[i-2][j]==r));
	}			
	else if(j>1){
		do{
			r = (rand() % 5) + 1;
		}while(m[i][j-1] == r && m[i][j-2]==r);
	}
	else if(i>1){
		do{
			r = (rand() % 5) + 1;
		}while(m[i-1][j] == r && m[i-2][j]==r);
	}
	else{
		r = (rand() % 5) + 1;
	}
	return r;
}

void swap(candy *a, candy *b) {
/* I.S. : 2 Candy terdefinisi
/* F.S. : Nilai dari 2 candy ditukar */
	candy temp = *a;
	*a = *b;
	*b = temp;
}

void AcakIsi (Matrix m) {
/* I.S. : Matrix terdefinisi
/* F.S. : Isi dari matrix di acak antara 1 sampai 4
	/* KAMUS LOKAL */
	candy r;

	/* ALGORITMA */
	srand(time(NULL));
	for(int i = 0; i<Nmax; i++){
		for(int j = 0; j<Nmax; j++){
			m[i][j] = smartRandom(m, i, j);
		}
	} 
}

void PrintKotak (Matrix m, int turn, infolist * player) {
/* I.S. : Matrix terdefinisi
/* F.S. : Matrix di print
/* KETENTUAN WARNA BUAH
	1 = Merah == &&
	2 = Hijau == ##
	3 = Biru == $$
	4 = Orange == @@
*/
	/* KAMUS LOKAL */


	/* ALGORITMA */
	printf("\t\t\t    Hello, %s!\n", (*player).name);
	printf("\t\t\t Remaining Turn : %d\n", turn);
	printf("\t\t\t      Score : %d\n", (*player).skor);
	printf("\n");
	printf("\t\t");
	for (int i = 0; i < Nmax; i++){
		printf("  +%d ", i);
	}
	printf("\n");
	for(int i = 0; i<Nmax; i++) {
		setColor(15);
		printf("\t\t+---------------------------------------+");
		printf("\n");
		printf("\t%d \t|", (i*8)+1);
		//printf("\t");
		for(int j = 0; j<Nmax; j++) {
			if (m[i][j] == 1) {
				setColor(4); // RED
				printf(" && ");
			}
			else if (m[i][j] == 2) {
				setColor(3); // GREEN
				printf(" ## ");
			}
			else if (m[i][j] == 3) {
				setColor(9); // BLUE
				printf(" $$ ");
			}
			else if (m[i][j] == 4) {
				setColor(14); // ORANGE
				printf(" @@ ");
			}
			else if (m[i][j] == 5) {
				setColor(11); // light blue
				printf(" ** ");
			}
			else {
				setColor(15); // ORANGE
				printf("    ");
			}
			setColor(15);
			printf("|");
		}
		printf("\n");
	}
	setColor(15);
	printf("\t\t+---------------------------------------+");
	turn--;
}

void Update(Stack *S, Matrix m, int *score, int c3, int c4, int c5){
/* I.S. : S terdefinisi, m terdefinisi, point sembarang
/* F.S. : semua m dengan koordinat dalam stack nilainya 0 point berisi banyak koordinat rantai */
	Point c;
	while(!IsEmpty2(*S)){
		Pop(S, &c);
		m[c.x][c.y] = 0;
	}
	*score += c3*60 + c4*120 + c5*240;
}

void FallingCandy(Matrix m) {
/* I.S. : */
/* F.S. : */
	int k;
	int above;
	bool swapped;

	for (int i = 0; i < Nmax; i++){
		k = Nmax;
		for (int j = Nmax-1; j >= 0; j--){
			swapped = false;
			if(m[j][i]==0){
				k = j;
				do{
					k--;
					if(k>=0){
						above = m[k][i];	
						if(above != 0){
							swap(&m[j][i],&m[k][i]);
							swapped = true;
						}
					}
				}while((k>=0) && !swapped);
			}
		}
	}
	
}

void RemoveZero(Matrix m){
	for (int i = 0; i < Nmax; i++){
		for (int j = 0; j < Nmax; j++){
			if(m[i][j]==0){
				m[i][j] = smartRandom(m, i, j);
			}
		}
	}
}

void GetChain(Stack *S, Matrix m, int *chain3, int*chain4, int*chain5){
/* I.S. : Stack s sembarang, matrix m terdefinisi */
/* F.S. : Stack s terisi dengan semua koordinat rantai */
	CreateEmpty(S);
	int after, after2;
	int cek;
	int count;
	int c3 = 0;
	int c4 = 0;
	int c5 = 0;


	for (int i = 0; i < Nmax; i++)
	{
		count = 0;
		for (int j = 0; j < Nmax-2; j++)
		{
			cek = m[i][j];
			after = m[i][j+1];
			after2 = m[i][j+2];

			if((cek == after) && (cek == after2) && (cek!=0)){
				// jika ada yang rantai yang sama minimal 3
				do{
					PushUnique(S, makePoint(i,j));
					j++;
					count++;
				}while((j<Nmax) && (m[i][j] == cek));
				switch(count){
					case 3: c3++;break;
					case 4: c4++;break;
					case 5: c5++;break;
				}
			}
		}
	}

	for (int i = 0; i < Nmax; i++)
	{
		count = 0;
		for (int j = 0; j < Nmax-2; j++)
		{
			cek = m[j][i];
			after = m[j+1][i];
			after2 = m[j+2][i];

			if((cek == after) && (cek == after2) && (cek!=0)){
				do{
					PushUnique(S, makePoint(j,i));
					j++;
					count++;
				} while((j<Nmax) && (m[j][i] == cek));
				switch(count){
					case 3: c3++;break;
					case 4: c4++;break;
					case 5: c5++;break;
				}
			}
		}
	}

	*chain3 = c3;
	*chain4 = c4;
	*chain5 = c5;

}

Point MovePoint(Point P1, char dir){
	Point P2;
	switch (dir) {
		case 'w' : 
							P2.x=P1.x-1;
							P2.y=P1.y;
							break;
		case 'd' : 
							P2.x=P1.x;
							P2.y=P1.y+1;
							break;
		case 's' : 
							P2.x=P1.x+1;
							P2.y=P1.y;
							break;
		case 'a' : 
							P2.x=P1.x;
							P2.y=P1.y-1;
							break;
		case 'W' : 
							P2.x=P1.x-1;
							P2.y=P1.y;
							break;
		case 'D' : 
							P2.x=P1.x;
							P2.y=P1.y+1;
							break;
		case 'S' : 
							P2.x=P1.x+1;
							P2.y=P1.y;
							break;
		case 'A' : 
							P2.x=P1.x;
							P2.y=P1.y-1;
							break;
	}
	return P2;
}

void Move(Matrix m, Stack ori, Stack right, Stack down) {
/* I.S. : Matrix terdefinisi
/* F.S. : Candy tertukar sesuai dengan masukan user */
	Point P1,P2;
	int select;
	char dir;
	bool valid;
	do {
		do {
			printf("\n\n\tInsert Tiles Number! (1-64) : ");
			scanf("%d",&select);
			if (select<1 || select>64) {
				printf("\tWrong Input! Input integer (1-64)!\n");
			}
		} while (select<1 || select>64);

		//konversi dari table ke matriks
		P1.x=select/8; //x=row y=col
		P1.y=(select%8)-1;

		if (P1.y == -1) {
			P1.y = 7;
		}

		do {
			printf("\tMoving Direction? (W,S,A,D) : ");
			scanf(" %c", &dir);
		} while (dir!='W' && dir!='S' && dir!='A' && dir!='D' && dir!='w' && dir!='d' && dir!='a' && dir!='s');
		//belum ada verifikasi kalo diujung-ujung hehe

		P2 = MovePoint(P1, dir);
		valid = isValidMove(P1,P2,dir,ori,right,down);
		if (!valid) {
			printf("\tInvalid Move!\n");
		}
	} while (!valid);
	//melakukan pertukaran
	swap(&m[P1.x][P1.y],&m[P2.x][P2.y]);
}

bool isValidMove(Point P1, Point P2, char dir, Stack ori, Stack right, Stack down)
/* Input : Koordinat dan arah pergerakan dari titik
/* Output : Apakah masukan valid atau tidak */
{	
	//pengecekan ujung-ujung matriks
	int row = P1.x;
	int col = P1.y;
	if ((row==0 && (dir=='W' || dir =='w')) || (col==0 &&(dir=='A' || dir=='a')) || (col==7 &&(dir=='D' || dir=='d'))|| (row==7 &&(dir=='S' || dir=='s'))) 
	{
		return false;
	}else{
		if(dir=='W'||dir=='w'){
			return Search(ori, P2) && Search(down, P1);
		}
		else if(dir=='A'||dir=='a'){
			return Search(ori, P2) && Search(right, P1);
		}
		else if(dir=='S'||dir=='s'){
			return Search(ori, P1) && Search(down, P2);
		}
		else if(dir=='D'||dir=='d'){
			return Search(ori, P1) && Search(right, P2);
		}
	}

}

bool IsChain(Matrix m, int baris, int kolom){
	candy now = m[baris][kolom];
	int horizontal = 1;
	for (int i = kolom-1; i>= 0; i--)
	{
		if(m[baris][i]==now){
			horizontal++;
		}else{
			break;
		}
	}
	for (int i = kolom+1; i< Nmax; i++)
	{
		if(m[baris][i]==now){
			horizontal++;
		}else{
			break;
		}
	}

	if(horizontal>=3){
		return true;
	}

	int vertikal = 1;
	for (int i = baris-1; i>= 0; i--)
	{
		if(m[i][kolom]==now){
			vertikal++;
		}else{
			break;
		}
	}
	for (int i = baris+1; i< Nmax; i++)
	{
		if(m[i][kolom]==now){
			vertikal++;
		}else{
			break;
		}
	}
	return (vertikal>=3);
}

void detectPossibleSwap(Matrix m, Stack *ori, Stack *right, Stack *down){
	CreateEmpty(ori);
	CreateEmpty(right);
	CreateEmpty(down);
	for (int i = 0; i < Nmax; i++){
		for (int j = 0; j < Nmax; j++){
			// right swap
			if(j<Nmax-1){
				// printf("Ri = %d, j = %d\n", i, j);
				swap(&m[i][j],&m[i][j+1]);
				if(IsChain(m, i, j) || IsChain(m, i, j+1)){
					// insert to list
					PushUnique(ori, makePoint(i,j));
					PushUnique(right, makePoint(i,j+1));
				}
				swap(&m[i][j],&m[i][j+1]);
			}
			// down swap
			if(i<Nmax-1){
				// printf("Di = %d, j = %d\n", i, j);
				swap(&m[i][j],&m[i+1][j]);
				if(IsChain(m, i, j) || IsChain(m, i+1, j)){
					// insert to list
					PushUnique(ori, makePoint(i,j));
					PushUnique(down, makePoint(i+1,j));                                                                               
				}
				swap(&m[i][j],&m[i+1][j]);
			}
		}
	}

}