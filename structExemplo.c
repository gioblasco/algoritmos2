//Giovanna Blasco
#include<stdio.h>
#define MAX 3

typedef struct {
	int idade, qtde_filhos;
	char sexo;
	float salario;
	} pessoa; 

void le(pessoa hab[MAX], int qtde_pessoas);
void imprime(pessoa hab[MAX], int qtde_pessoas);
float media_sal(pessoa hab[MAX]);
float media_filho(pessoa hab[MAX]);
float maior_salario(pessoa hab[MAX]);
void main(){
	pessoa hab[MAX];
	int qtde_pessoas;
	for(qtde_pessoas = 0; qtde_pessoas < MAX; qtde_pessoas++){
		le(hab, qtde_pessoas);
	}
	for(qtde_pessoas = 0; qtde_pessoas < MAX; qtde_pessoas++){
		imprime(hab, qtde_pessoas);
	}
	printf("%.2f\n", media_sal(hab)); 
	printf("%.2f\n", media_filho(hab));
	printf("%.2f\n", maior_salario(hab));
}

void le(pessoa hab[MAX], int qtde_pessoas){
	scanf("%d %d %c %f", &hab[qtde_pessoas].idade, &hab[qtde_pessoas].qtde_filhos, &hab[qtde_pessoas].sexo, &hab[qtde_pessoas].salario);  
} 

void imprime(pessoa hab[MAX], int qtde_pessoas){
	printf("%d %d %c %.2f\n", hab[qtde_pessoas].idade, hab[qtde_pessoas].qtde_filhos, hab[qtde_pessoas].sexo, hab[qtde_pessoas].salario);  

}

float media_sal(pessoa hab[MAX]){
	int i;
	float soma = 0;
	for(i = 0; i < MAX; i++){
		soma += hab[i].salario;
	} 
	return soma / MAX;
}

float media_filho(pessoa hab[MAX]){
	int i;
	float soma = 0;
	for(i = 0; i < MAX; i++){
		soma += hab[i].qtde_filhos;
	} 
	return soma / (float)MAX;	
}

float maior_salario(pessoa hab[MAX]){
	float max = hab[0].salario; 
	int i;
	for(i = 1; i < MAX; i++){ 
		if(max < hab[i].salario){
			max = hab[i].salario;	
		} 
	}
return max; 
}
