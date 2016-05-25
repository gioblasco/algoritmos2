#include<stdio.h>

void main(){

	FILE *arq; //declaração
	
	//Abre o arquivo em modo leitura 
	arq = fopen("exemplo.txt", "r");

	if (arq == NULL) // Testa a abertura
		perror("Erro ao abrir o arquivo.\n");
	else
		printf("Arquivo aberto para leitura.\n");

	fclose(arq); // Libera o apontador
}
