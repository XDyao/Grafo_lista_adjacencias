/*
 *	Esse modulo contem a implementacao do TAD Fila, inspirada no modelo passado em aula, mas com alteracoes. 
 */

#ifndef FILA_H
#define FILA_H

#define TIPO int
#define TamFila 100

//Struct da fila.
typedef struct fila{
	TIPO vet[TamFila];
	int ini;
	int fim;
	int tam;
}Fila;

//Criacao da fila.
Fila *Create();

//Deleta a fila.
void Empty(Fila* f);

//Checa se a fila esta vazia.
int IsEmpty(Fila* f);

//Checa se a fila esta cheia.
int IsFull(Fila* f);

//Insere elemento na fila.
void Entra(Fila* f, TIPO* elem);

//Remove elemento da fila.
void Sai(Fila* f, TIPO* elem);

#endif
