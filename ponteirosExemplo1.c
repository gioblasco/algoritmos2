//Renan Ramalho
#include<stdio.h>

void ordenar (int *x, int *y){
	int aux;
	
	aux = *x;
	*x = *y;
	*y = aux;
	
}

void main () {
	
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d %d %d\n", a, b, c);
	
	if (a > b){
		ordenar(&a,&b);
	}
	if (a > c){
		ordenar(&a,&c);
	}
	if (b > c){
		ordenar(&b,&c);
	} 
	printf("%d %d %d\n", a, b, c);	
}
