#include<stdio.h>
#include<stdlib.h>

void le_vetor(int *v, int n) {
	int i;
	for (i=0; i < n; i++)
		scanf("%d", &v[i]);
}


void imprime_vetor(int *v, int n) {
	int i;
	for (i=0; i<n; i++)
		printf("%d ", v[i]);
}

int main(void) {
	int n, *vetor;
	scanf("%d", &n);
	
	//aloca memoria dinamica
	vetor = (int *) malloc(n*sizeof(int));

	le_vetor(vetor, n);
	imprime_vetor(vetor, n);

	printf("\n");
	free(vetor);
	return 0;
}
