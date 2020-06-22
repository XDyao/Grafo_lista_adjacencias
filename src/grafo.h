/*
 *	Esse modulo contem a implementacao do TAD Grafo por Listas de adjacencias. Inspirada na teoria passada em aula, mas com alteracoes.
 */

#include "lista.h"
#include "fila.h"

//Indicacao da cor do vertice.
typedef enum{
 branco, cinza, preto
}TipoCor;

//Struct usada para o grafo.
typedef struct grafo{
    LISTA **vertices;
    int tamanho;
    TipoCor cor[];
}Grafo;

//Cria o grafo.
Grafo *cria_grafo(int tam);

//Busca uma aresta.
int busca_aresta(Grafo* g, int x, int y);

//Adiciona aresta.
void adiciona_aresta(Grafo* g, int x, int y);

//Remove aresta.
void remove_aresta(Grafo* g, int x, int y);

//Imprime o grafo.
void imprime_grafo(Grafo* g);

//Apaga o grafo.
void apaga_grafo(Grafo* g);

//////////----------Funcoes adicionadas durante o Trabalho 3 abaixo----------//////////

//Algumas alteracoes tambem foram feitas em procedimentos anteriores tambem por questoes de adequacao do codigo a proposta.

NO* PrimeiroListaAdj(Grafo* g, int vertice);
int ListaAdjVazia(Grafo* g, int vertice);
NO** ProxAdj(Grafo* g, NO* Adj, int* FimListaAdj);
//void visita_dfs(Grafo* g, int V, int* tempo, int d[], int t[], TipoCor cor[], int antecessor[]);
//void busca_profundidade(Grafo* g);
void visita_bfs(Grafo *g, int V, int distancia[], TipoCor cor[], int antecessor[]);
void busca_largura(Grafo* g);
