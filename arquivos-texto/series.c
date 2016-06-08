#include "series.h"


BDSeries leBDSeries(char *nome_arquivo) {
	BDSeries bd;
	FILE *arquivo;
	int i;
	char linha[REGISTER_SIZE], *pos;

	arquivo = fopen(nome_arquivo, "r");
	if(arquivo == NULL) {
		perror("Erro ao abrir o arquivo!");
		exit (-1);
	}
	

	fgets(linha, REGISTER_SIZE-1, arquivo);	// le cadeia de caracteres do arquivo ate \n
	sscanf(linha, "%d", &bd.num_series);	// coloca valor de linha no campo num_series

	bd.series = (Serie *) calloc(bd.num_series, sizeof(Serie)); // Aloca estruturas
	
	if (bd.series != NULL) {
		for (i=0; i < bd.num_series; i++){
			fgets(linha, REGISTER_SIZE-1, arquivo); // lê próxima linha do arquivo
			pos = strchr(linha, '@'); // retorna ponteiro para primeira ocorrencia de '@' em linha
			strncpy(bd.series[i].nome, linha, pos-linha); //copia em nome pos-1 caracteres de linha
			sscanf(pos+1, "%d", &bd.series[i].num_temporadas); //coloca o restante de linha apos '@' num_temporadas
			pos = strchr(++pos, '@'); // retorna ponteiro para próxima ocorrencia de '@' em linha
			sscanf(pos+1, "%s", bd.series[i].genero); //coloca o restante de linha apos '@' num_temporadas
		}
	}
	
	return(bd);
}


void imprimeSeries (BDSeries bd){
	int i;
	
	for(i=0; i < bd.num_series;i++) {
		printf("%s %d %s\n", bd.series[i].nome, bd.series[i].num_temporadas, bd.series[i].genero);
	}
}

void gravaBDSeries(BDSeries bd, char *nome_arquivo) {
	int i;
	FILE *arquivo;

	arquivo = fopen(nome_arquivo, "w"); //cria novo arquivo

	fprintf(arquivo, "%d\n", bd.num_series); // escreve primeira linha

	for (i=0; i < bd.num_series; i++)
		fprintf(arquivo,"%s@%d@%s\n",bd.series[i].nome, bd.series[i].num_temporadas, bd.series[i].genero); //escreve registros

	fclose(arquivo);
}


void destroiBDSeries(BDSeries bd) {
	if (bd.series != NULL)
		free(bd.series);
}
