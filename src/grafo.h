typedef struct grafo Grafo;

Grafo *cria_grafo(int tam);
int busca_aresta(Grafo* g, int x, int y);
void adiciona_aresta(Grafo* g, int x, int y);
void remove_aresta(Grafo* g, int x, int y);
void imprime_grafo(Grafo* g);
void apaga_grafo(Grafo* g);
NO *primeiroAdj(GRAFO* g, int vertice, int* erro);
void ProxAdj(Grafo* g, no_aresta** Adj, no_aresta** Prox, int* FimListaAdj);
void visita_dfs(Grafo* g, int V, int* tempo, int d[], int t[], TipoCor cor[], int antecessor[]);
void busca_profundidade(Grafo* g);
void visita_bfs(Grafo *g, int V, int distancia[], TipoCor cor[], int antecessor[]);
void busca_largura(Grafo* g);
