/*
	NOME: Yago Poletto Salgado						NUSP: 10724455
*/

#include "grafo.h"
#include <stdio.h>

int main(){
	
	Grafo *g;
	int n, m, x, y, q, operacao;
	
	scanf("%d %d", &n, &m);
	
	cria_grafo(g, n);
	
	for(int i=0; i<m; i++){
		scanf("%d %d", &x, &y);
		adiciona_aresta(g, x, y);	
	}
	
	scanf("%d", &q);
	
	for(int i=0; i<q; i++){
		scanf("%d", &operacao);
		switch(operacao){
			case 1:
				scanf("%d %d", &x, &y);
				adiciona_aresta(g, x, y);
				break;
			case 2:
				scanf("%d %d", &x, &y);
				remove_aresta(g, x, y);
				break;
			case 3:
				imprime_grafo(g, n);
				break;
			default:
				print("Operacao invalida\n");
		}		
	}
	
	apaga_grafo(g, n);
		
	return 0;
}
