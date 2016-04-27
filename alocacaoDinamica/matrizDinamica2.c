#include<stdio.h>
#include<stdlib.h>

void imprime_matriz(int **m, int l, int c) {
	int i, j;
	for (i=0; i<l; i++) {
		for (j=0; j<c; j++)
			printf("%d\t", m[i][j]);
		printf("\n");
	}
}

void le_matriz(int **m, int lin, int col) {
	int i, j;
	
	// carrego a matriz
	for (i=0; i < lin; i++)
		for (j=0; j < col; j++) {
			printf("Entre m[%d][%d]: ", i, j);
			scanf("%d", &m[i][j]);
		}
	
}

int main(void){
	int **m;
	int nlin, ncol, i;

	printf("Entre com o numero de linhas e colunas: ");
	scanf("%d %d", &nlin, &ncol);

	//aloca linhas
	m = (int **) malloc(nlin*sizeof(int *));

	//aloca colunas
	if(m != NULL){
		for (i = 0; i < nlin; i++)
		m[i] = (int *)malloc(ncol*sizeof(int));
	}else{
		printf("Nao foi possivel alocar a matriz\n");
		exit(0);
	}

	le_matriz(m, nlin, ncol);
	imprime_matriz(m, nlin, ncol);

	// libera os ponteiros das colunas
	for (i = 0; i < nlin; i++)
		free(m[i]);


	free(m);
	return 0;
}
