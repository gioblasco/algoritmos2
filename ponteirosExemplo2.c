//Caio Souza
#include<stdio.h>

typedef struct{
	int dias, meses, anos;
	
} tempo;

void calcula (tempo *t) {
	t->meses = t->dias/30;
	(*t).anos = t->dias/365;
}
	
int main(){
	tempo pessoa;
	
	scanf("%d", &pessoa.dias);
	calcula(&pessoa);
	printf("%d %d %d", pessoa.dias, pessoa.meses, pessoa.anos);
	
}
