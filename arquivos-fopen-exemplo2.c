#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 300

// Testa a abertura
void testFileOpen(FILE *file){
	if (file == NULL){
		perror("Erro ao abrir o arquivo.\n");
		exit(-1);
	}
}

void main(){

	// Declaração
	FILE *fileRead, *fileWrite;
	char line[MAX];
	
	// Abre o arquivo em modo leitura e escrita
	fileRead = fopen("exemplo2.txt", "a+");

	// Abre o arquivo em modo escrita
	fileWrite = fopen("exemplo2saida.txt", "w");

	if (fileRead == NULL){
		perror("Erro ao abrir o arquivo.\n");
		exit(-1);
	}

	// Testa a abertura
	if (fileRead == NULL){
		perror("Erro ao abrir o arquivo.\n");
		exit(-1);
	}
	
	while(!feof(fileRead)){
		/* Lê uma linha com até MAX-1 caracateres 
		(o último o caractere é o \0) */
		fgets(line, MAX, fileRead);
		printf("%s\n", line); // Imprime a linha lida
		printf("%d\n", strlen(line));// Imprime a quantidade de caracteres da linha
	}

	// Reposiciona indicador no inicio do arquivo
	rewind(fileRead);

	fgets(line, MAX, fileRead);
	fprintf(fileWrite, "%s", line);

	// Libera o apontador
	fclose(fileRead);
}
