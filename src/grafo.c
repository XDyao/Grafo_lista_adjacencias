#include "grafo.h"
#include "lista.h"
#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

typedef enum{
 branco, cinza, preto
}TipoCor;

struct grafo{
    LISTA **vertices;
    int tamanho;
};

Grafo *cria_grafo(int tam){
    Grafo *gf = (Grafo*)malloc(sizeof(Grafo));
    gf->tamanho = tam;
    gf->vertices = (LISTA**)malloc(tam*sizeof(LISTA*));
    for(int i=0; i<gf->tamanho; i++){
        gf->vertices[i] = lista_criar();
    }
    return gf;
}

int busca_aresta(Grafo* g, int x, int y){
    int boolean;
    if(lista_buscar_item(g->vertices[x],y) != -404){
        return 1;
    }
    return 0;
}

void adiciona_aresta(Grafo* g, int x, int y){
    lista_inserir_ordenadamente(g->vertices[x],y);
    lista_inserir_ordenadamente(g->vertices[y],x);
}

void remove_aresta(Grafo* g, int x, int y){
    lista_remover_item(g->vertices[x],y);
    lista_remover_item(g->vertices[y],x);
}

void imprime_grafo(Grafo* g){
    for(int i=0; i<g->tamanho; i++){
        printf("%d:",i);
        lista_imprimir(g->vertices[i]);
        printf("\n");
    }
}

void apaga_grafo(Grafo* g){
    for(int i=0; i<g->tamanho; i++){
        lista_apagar(g->vertices[i]);
    }
    free(g->vertices);
    free(g);
}

NO *primeiroAdj(GRAFO* g, int vertice, int* erro){
	if(vertice > g->tamanho){
		*erro = 1;
		return NULL;
	}
	else{
		NO *aux = g->vertices->inicio;
		for(int i=0; i<vertice; i++){
			aux = aux-> proximo;
		}
		// aux é o vertice que queremos
		aux->item->inicio;
	}
}

void ProxAdj(Grafo* g, no_aresta** Adj, no_aresta** Prox, int* FimListaAdj){
	*Adj= *Prox;
	*Prox= (*Prox)->prox;
	if (*Prox == NULL){
		*FimListaAdj= 1;
	}
}

void visita_dfs(Grafo* g, int V, int* tempo, int d[], int t[], TipoCor cor[], int antecessor[]){
	int FimListaAdj, erro;
	no_lista *Adj, *Aux;
	cor[V]= cinza; (*tempo)++; d[V]= *tempo;
	
	if(!ListaAdjVazia(g, V, &erro)){
		Aux= PrimeiroListaAdj(g, V, &erro);
		FimListaAdj= 0;
		while(!FimListaAdj){
			ProxAdj(g, &Adj, &Aux, &FimListaAdj);
			if(cor[Adj->v] == branco){
				antecessor[Adj->v]= V;
				visita_dfs(g, Adj->v, tempo, d, t, cor, antecessor);
			}
		}
	}
	cor[V]=preto; (*tempo)++; t[V]=*tempo;
	printf("No %d, descoberta=%d, termino=%d, antecessor=%d\n", V, d[V], t[V], antecessor[V]);

	while(!FimListaAdj){
		ProxAdj(g, &Adj, &Aux, &FimListaAdj);
		if(cor[Adj->v] == branco){
			antecessor[Adj->v]= V;
			visita_dfs(g, Adj->v, tempo, d, t, cor, antecessor);
		}
	}

}

void busca_profundidade(Grafo* g){
	int V, tempo;
	int d[MaxNumVertices], t[MaxNumVertices], antecessor[MaxNumVertices];
	TipoCor cor[MaxNumVertices];
	printf("*** Sequencia de nos visitados na busca em profundidade ***\n\n");
	tempo= 0;
	
	for(V= 0; V < g->NumVertices; V++){
		cor[V]= branco;
		antecessor[V]= -1;
	}
	for(V= 0; V< g->NumVertices; V++){
		if(cor[V] == branco){
			visita_dfs(g, V, &tempo, d, t, cor, antecessor);
		}
	}
	
}

void visita_bfs(Grafo* g, int V, int distancia[], TipoCor cor[], int antecessor[]){
	int FimListaAdj, erro;
	no_lista *Adj, *Aux;
	
	Fila F;
	Create(&F);
	
	cor[V]= cinza;
	distancia[V]= 0;
	Entra-Fila(&F, &V, &erro);
	printf("No %d, distancia = %d, antecessor = %d\n", V, distancia[V], antecessor[V]);
	
	while(!IsEmpty(&F)){
		Sai-Fila(&F, &V, &erro);
		if(!ListaAdjVazia(g, V, &erro)){
			Aux= PrimeiroListaAdj(g, V, &erro);
			FimListaAdj= 0;
			while (!FimListaAdj){
				ProxAdj(g, &Adj, &Aux, &FimListaAdj);
				if (cor[Adj->v] == branco){
					cor[Adj->v]= cinza;
					distancia[Adj->v]= distancia[V]+1;
					antecessor[Adj->v]= V;
					Entra-Fila(&F, &Adj->v, &erro);
					printf("No %d, distancia=%d, antecessor=%d\n", Adj->v, distancia[Adj->v], antecessor[Adj->v]);
				}
			}
		}
		cor[V]= preto;
	}
}

void busca_largura(Grafo *g){
	int V, distancia[g->tamanho + 1], antecessor[g->tamanho];
	TipoCor cor[g->tamanho];
	
	//-----Insere sub-rotina DSF para achar ciclos aqui-----//
	
	printf("*** Sequencia de nos visitados na busca em largura ***\n\n");
	for(V= 1; V <= g->NumVertices; V++){
		cor[V]= branco;
		distancia[V]= -1;
		antecessor[V]= -1;
	}
	
	for(V= 1; V <= g->NumVertices; V++){
		if(cor[V] == branco){
			visita_bfs(g, V, distancia, cor, antecessor);
		}
	}
}
