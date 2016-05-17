#include<stdio.h>

// Qual a diferença dos dois métodos (impvet1 e impvet2) a seguir?

void impvet1(int v[], int i, int n){
	if (i < n){
		printf("%d ", v[i]);
		impvet1(v, i+1, n);
	}
}

void impvet2(int v[], int i, int n){
	if (i < n){	
		impvet2(v, i+1, n);
		printf("%d ", v[i]);
	}
}


void main(){
	int vetor[] = {1, 2, 3, 4, 5, 6, 7};

	impvet1(vetor, 0, 7);
	printf("\n");
	impvet2(vetor, 0, 7);
}

/* A diferença dos algoritmos está na ordem da chamada dafunçao impvet1 e impvet2 e a impressão na tela.
A ordem da chamada das funções podem mudar completamente a execução da função!
Para entender melhor, desenhe a pilha de execução com as chamadas recursivas de impvet1 e impvet2.
*/

