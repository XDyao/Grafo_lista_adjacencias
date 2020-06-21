#include "lista.h"
#include "fila.h"

typedef enum{
 branco, cinza, preto
}TipoCor;

typedef struct grafo{
    LISTA **vertices;
    int tamanho;
    TipoCor cor[];
}Grafo;

Grafo *cria_grafo(int tam);
int busca_aresta(Grafo* g, int x, int y);
void adiciona_aresta(Grafo* g, int x, int y);
void remove_aresta(Grafo* g, int x, int y);
void imprime_grafo(Grafo* g);
void apaga_grafo(Grafo* g);
NO* PrimeiroListaAdj(Grafo* g, int vertice);
int ListaAdjVazia(Grafo* g, int vertice);
void ProxAdj(Grafo* g, NO** Adj, NO** Prox, int* FimListaAdj);
//void visita_dfs(Grafo* g, int V, int* tempo, int d[], int t[], TipoCor cor[], int antecessor[]);
//void busca_profundidade(Grafo* g);
void visita_bfs(Grafo *g, int V, int distancia[], TipoCor cor[], int antecessor[]);
void busca_largura(Grafo* g);
