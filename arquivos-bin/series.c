#include "series.h"


BDSeries leBDSeries(char *nome_arquivo) {
	BDSeries bd;
	FILE *arquivo;
	int i;
	char linha[REGISTER_SIZE], *pos;

	arquivo = fopen(nome_arquivo, "a+b");
	if(arquivo == NULL) {
		perror("Erro ao abrir o arquivo!");
		exit (-1);
	}
	bd.num_series = 0;	
	fread(&bd.num_series, sizeof(int),1,arquivo);
	bd.series = (Serie *) calloc(bd.num_series + TAMANHO_DO_VETOR, sizeof(Serie)); // Aloca estruturas
	
	if (bd.series != NULL) {
		for (i=0; i < bd.num_series; i++){
			printf("Byte: %ld\n", ftell(arquivo));
			fread(&bd.series[i],sizeof(Serie),1,arquivo);
		}
	}
	
	return(bd);
}


void imprimeSeries (BDSeries bd){
	int i;
	
	for(i=0; i < bd.num_series;i++) {
		printf("SERIE: %s %s %d \n", bd.series[i].nome,bd.series[i].genero, bd.series[i].num_temporadas);
	}
}

void gravaBDSeries(BDSeries bd, char *nome_arquivo) {
	int i;
	FILE *arquivo;

	arquivo = fopen(nome_arquivo, "wb"); //cria novo arquivo
	fwrite(&bd.num_series, sizeof(int), 1, arquivo);
			 
	for (i=0; i < bd.num_series; i++)
		fwrite(&bd.series[i],sizeof(Serie), 1, arquivo);
	fclose(arquivo);
}


void destroiBDSeries(BDSeries bd) {
	if (bd.series != NULL)
		free(bd.series);
}

void addSeries( BDSeries *bd){
	int quantSeries = 0;
	scanf("%d", &quantSeries);
	//TODO REALLOC
	for(int i = 0; i < quantSeries; i++){
		__fpurge(stdin);
		scanf("%99[^\n]s",  bd->series[bd->num_series +i].nome);
		__fpurge(stdin);
		scanf("%99[^\n]s",  bd->series[bd->num_series +i].genero);
		scanf("%d",  &bd->series[bd->num_series +i].num_temporadas);
	}
	bd->num_series+= quantSeries;
}

// Alterar esta funcao para o programa alterar qualquer registro
void alteraRegistro(char *nome_arquivo) {
	FILE *arquivo;
	Serie aux;

	/* Abre arquivo para leitura e escrita */
	arquivo = fopen(nome_arquivo, "r+b");

	/* posiciona leitura/escrita no inicio do segundo registro */
	fseek(arquivo, sizeof(int)+sizeof(Serie), SEEK_SET);

	fread(&aux, sizeof(Serie), 1, arquivo); /* le serie */
	sprintf(aux.nome, "Hey"); 				/* Altera o nome*/

	/* posiciona leitura/escrita no inicio do segundo registro */
	fseek(arquivo, sizeof(int)+sizeof(Serie), SEEK_SET);

	fwrite(&aux, sizeof(arquivo), 1, arquivo); /* grava registro modificado */

	fclose(arquivo);
}
