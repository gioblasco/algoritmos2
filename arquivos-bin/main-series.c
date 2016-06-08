#include "series.h"

int main() {
	BDSeries bd;
	
	bd = leBDSeries("series.in");
	
	imprimeSeries(bd);
	
	addSeries(&bd);
	imprimeSeries(bd);
	gravaBDSeries(bd, "series.in");
	destroiBDSeries(bd);
	alteraRegistro("series.in");

	// Crie um menu com as seguintes opções:
	// 1. Imprime séries: imprime todos os nomes de séries salvas no arquivo
	// 2. Ver detalhes de uma série: Recebe o nome da série e exibe todos os detalhes desta série (nome, numero de temporadas e genero)
	// 3. Adicionar série
	// 4. Editar série
	// 5. Sair

	return(0);
}

