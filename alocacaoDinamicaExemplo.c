//Guilherme Yutaka Nishioka
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
	char nome[MAX];
	float media; 
	int num_faltas;
} Aluno;

void le (Aluno *p, int qtde);
void imprime (Aluno *p, int qtde);
void ordena (Aluno *p, int qtde);

int main(){
	int num_alunos;
	Aluno *p;
	
	printf("Número de alunos: ");
	scanf ("%d", &num_alunos);

	p = (Aluno *) malloc (num_alunos * sizeof(Aluno));
	
	le (p, num_alunos);
	
	ordena (p, num_alunos);
	
	imprime (p, num_alunos);
	
return 0;
}


void le (Aluno *p, int qtde){
	int i;
	
	for (i = 0; i < qtde; i++){
		scanf("%s", p[i].nome);
		scanf("%f", &p[i].media);
		scanf("%d", &p[i].num_faltas);
	}
}

void imprime (Aluno *p, int qtde){
	int i;
	
	for (i = 0; i < qtde; i++){
		printf("%s ", p[i].nome);
		printf("%.2f ", p[i].media);
		printf("%d\n", p[i].num_faltas);
	}
}

void ordena (Aluno *p, int qtde){
	int i, j;
	Aluno aux;
	
	for (i = 0; i < qtde; i++){
		for (j = 0; j < qtde-i-1; j++){
			if (p[j].media > p[j+1].media){
				aux = p[j];
				p[j] = p[j+1];
				p[j+1] = aux;
			}	
		}
	}

}
