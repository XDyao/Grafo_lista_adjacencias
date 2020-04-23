typedef struct grafo Grafo;

void cria_grafo(Grafo* g, int tam);
int busca_aresta(Grafo* g, int tam);
void adiciona_aresta(Grafo* g, int x, int y);
void remove_aresta(Grafo* g, int x, int y);
void imprime_grafo(Grafo* g, int tam);
void apaga_grafo(Grafo* g, int tam);
