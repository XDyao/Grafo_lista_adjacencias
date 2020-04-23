#include "grafo.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

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
