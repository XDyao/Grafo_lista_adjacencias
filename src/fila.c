#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct fila{
	TIPO vet[TamFila];
	int ini;
	int fim;
	int tam;
};

void Create(Fila* f){
	f = (Fila*)malloc(sizeof(Fila));
	if(f != NULL){		
		f->ini = 0;
		f->fim = 0;
		f->tam = 0;
	}
	return;
}

void Empty(Fila* f){
	if(f != NULL){
		free(f);
		f = NULL;
	}
	return;
}

int IsEmpty(Fila* f){
	if(f->tam == 0){
		return 1;
	}
	return 0;
}

int IsFull(Fila *f){
	if(f->tam == TamFila){
		return 1;
	}
	return 0;
}

void Entra(Fila* f, TIPO* elem){
	if(f != NULL && !IsFull(f)){
	 	f->vet[f->fim] = &elem;
	 	f->fim = (f->fim+1) % TamFila; 	
	 	f->tam++;
	}	
}

void Sai(Fila* f, TIPO* elem){
	if(f != NULL && !IsEmpty(f)){
		&elem = f->vet[f->ini];
		f->ini = (f->ini+1) % TamFila;
		f->tam--;
	}
	return;
}

