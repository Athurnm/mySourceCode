#include <stdio.h>
#include "queue.h"

float AvgElmt (Queue Q){
/* Menghasilkan rata-rata elemen dalam queue Q yang tidak kosong */
	infotype x;
	float sum = 0;
	int count = 0;
	
	do{
		Del(&Q, &x);
		sum += x;
		count ++;
	}while(!IsEmpty(Q));

	return sum/count;
}

int main(){
	Queue Q;
	int kode, N;
	infotype x;
	
	scanf("%d", &N);
	CreateEmpty(&Q, N);
	
	do{
		scanf("%d", &kode);
		switch(kode){
			case 1:
				scanf(" %d", &x);
				if(IsFull(Q)){
					printf("Queue penuh\n");
				}else{
					Add(&Q,x);
				}
			break;
			case 2:
				if(IsEmpty(Q)){
					printf("Queue kosong\n");
				}else{
					Del(&Q, &x);
				}
			break;
		}
	}while(kode != 0);
	
	printf("%d\n", NBElmt(Q));
	if(IsEmpty(Q)){
		printf("Tidak bisa dihitung\n");
	}else{
		printf("%.2f\n", AvgElmt(Q));
	}
	

	return 0;
}
