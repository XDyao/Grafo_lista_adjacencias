/*
	NOME: Yago Poletto Salgado						NUSP: 10724455
*/

#include "grafo.h"
#include <stdio.h>

int main(){
	Grafo *g;

	int V, E, x, y;
	
	scanf("%d", &V);
	g = cria_grafo(V);
	
	scanf("%d", &E);
	
	for(int i=0; i<E; i++){
		scanf("%d %d", &x, &y);
		adiciona_aresta(g, x, y);
	}
	
	//./busca_largura(g, V);
	
	apaga_grafo(g);
		
	return 0;
}
