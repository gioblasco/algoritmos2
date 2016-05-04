// Danielle Laizi
#include "recursao.h"

void ordena (int *vetor, int tamanho, int indice) {
	int j;
	int temp;
	if(indice < tamanho) {
		for(j = indice; j > 0; j--) {
		
			if(vetor[j] < vetor[j-1]) {
				temp = vetor[j];
				vetor[j] = vetor[j-1];
				vetor[j-1] = temp;
			}else{
				break;
			}
		}
		ordena(vetor, tamanho, ++indice);
	}
}
