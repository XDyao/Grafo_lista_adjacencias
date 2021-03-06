/*
 *	Creditos TAD Lista: https://github.com/matprado -- Mateus Prado, ICMC/2018
 */

/*
 *	Esse modulo contem a implementacao do TAD Lista, usando o TAD que pode ser encontrado no link passado em "Creditos".
 *	Possui implementacoes extras que se julgaram necessarias. 
 */

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

LISTA *lista_criar(void){
	LISTA *new = (LISTA *)malloc(sizeof(LISTA));
	if(new != NULL){		
		new->inicio = NULL;
		new->fim = NULL;
		new->tam = 0;
	}
	return new;
}

void lista_apagar(LISTA *L){
	if(L != NULL && !lista_vazia(L)){
   		NO *no = L->inicio, *aux;
    	while(no != NULL){
       	 	aux = no;
       	 	no = no->proximo;
        	free(aux);
    	}
    	L->fim = NULL;
    	L->inicio = NULL;
    	free(L);
		L = NULL;
	}
}

TIPO lista_buscar_item(LISTA *L, TIPO chave){
	NO *aux;
	if(L != NULL && !lista_vazia(L)){
		aux = L->inicio;
		while(aux != NULL){
			if(aux->item > chave) return ERRO;
			if(aux->item == chave) return aux->item;
			aux = aux->proximo;
		}
	}
	return (ERRO);
}	

int lista_buscar_posicao(LISTA *L, TIPO chave){
	NO *aux;
	int i=0;
	if(L != NULL && !lista_vazia(L)){
		aux = L->inicio;
		while(aux != NULL){
			if(aux->item > chave) return ERRO;
			if(aux->item == chave) return i;
			aux = aux->proximo;
			i++;
		}
	}
	return ERRO;
}

int lista_inserir_ordenadamente(LISTA *L, TIPO item){
	if(L == NULL) return (ERRO);
	NO *aux = (NO *) malloc(sizeof(NO)), *busca = NULL, *anterior = NULL;	
	if(aux != NULL){
		aux->item = item;
		aux->proximo = NULL;
		if(lista_vazia(L)){
			L->inicio = aux;
      L->fim = aux;
		}else{
			busca = L->inicio;
			while(busca != NULL && busca->item < aux->item){
				anterior = busca;
				busca = busca->proximo; /*anterior recebe o nó anterior de busca*/
			}
			if(busca == L->inicio){ 	//CASO PARTICULAR: inserir como primeiro elemento
				aux->proximo = L->inicio;
				L->inicio = aux;
			}else if(busca == NULL){	//CASO PARTICULAR: inserir como último elemento	
				anterior->proximo = aux;
				L->fim = aux;
			}else{
				aux->proximo = anterior->proximo;
				anterior->proximo = aux;
			}
		}	
		L->tam++;
		return 1;
	}
	return 0;
}


int lista_remover_item(LISTA *L, TIPO chave){
	NO *p = NULL, *aux = NULL;
	if(L != NULL && !lista_vazia(L)){
		p = L->inicio;
		while((p != NULL) && (p->item != chave)){
			aux = p; /*aux_busca recebe o nó anterior de aux_remocao*/
			p = p->proximo;
		}
		if(p != NULL){
			if(p == L->inicio){ /*Exceção: chave no inicio*/
				L->inicio = p->proximo;
				p->proximo = NULL;
			}else{
				aux->proximo = p->proximo;
				p->proximo = NULL;
			}
			if(p == L->fim){ /*Se a chave está no último nó*/
				L->fim = aux;
			}
			L->tam--;
			free(p);	
			return 1;
		}
	}
	return 0;
}

int lista_vazia(LISTA *L){
	if(L != NULL && L->inicio == NULL) return 1;
 	return 0;
}

int lista_tamanho(LISTA *L){
	return (L != NULL ? L->tam : ERRO);	
}

void lista_imprimir(LISTA *L){
	NO *aux; int i=0;
	if(L != NULL && !lista_vazia(L)){
		aux = L->inicio;
		while(aux != NULL){
			printf(" %d",aux->item);
			aux = aux->proximo;
		}
	}
}
