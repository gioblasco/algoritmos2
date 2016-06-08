#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE     	100  //tamanho maximo por nome
#define REGISTER_SIZE 	250  //tamanho maximo de cada registro
#define TAMANHO_DO_VETOR 100 //tamanho maximo de alocação

typedef struct serie{
	char nome[NAME_SIZE];
	int  num_temporadas;
	char genero[NAME_SIZE];
} Serie;

typedef struct bdseries{
	Serie *series;
	int num_series;
} BDSeries;


//Prototipos de funcoes
BDSeries leBDSeries(char *nome_arquivo);
void gravaBDSeries(BDSeries bd, char *nome_arquivo);
void imprimeSeries (BDSeries bd);
void destroiBDSeries(BDSeries bd);

void addSeries( BDSeries *bd);
void alteraRegistro(char *nome_arquivo);
