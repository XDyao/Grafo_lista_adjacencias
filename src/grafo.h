typedef struct grafo Grafo;

Grafo *cria_grafo(int tam);
int busca_aresta(Grafo* g, int x, int y);
void adiciona_aresta(Grafo* g, int x, int y);
void remove_aresta(Grafo* g, int x, int y);
void imprime_grafo(Grafo* g);
void apaga_grafo(Grafo* g);
