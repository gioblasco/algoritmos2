// Danielle Laizi
#include "recursao.h"

#define MAX 7

int main() {
	int vetor[] = {1, 7, 5, 4, 2, 3, 6};
	int i;
	
	ordena (vetor, MAX, 0);
	
	for(i = 0; i < MAX; i++) {
		printf("%d ", vetor[i]);
	}
	
	printf("\n");
	return (0);
}  
