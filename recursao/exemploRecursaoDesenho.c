#include<stdio.h>

void desenha1(int n){
	int i;
	if(n > 0){
		desenha1(n-1);	
		for( i = 0; i < n; i++)
			printf("*");
		printf("\n");
	}
}


void desenha2(int n){
	int i;
	if(n > 0){
		for( i = 0; i < n; i++)
			printf("-");
		printf("\n");
		desenha2(n-1);
		
	}
}

void desenha(int n){
	if(n > 0){
		desenha1(n);
		desenha2(n);
	}
	desenha(n/2);
}

void main(){
	desenha(10);
}
