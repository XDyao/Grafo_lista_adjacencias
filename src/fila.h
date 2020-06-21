#ifndef FILA_H
#define FILA_H

#define TIPO int
#define TamFila 100

typedef struct fila{
	TIPO vet[TamFila];
	int ini;
	int fim;
	int tam;
}Fila;

void Create(Fila* f);
void Empty(Fila* f);
int IsEmpty(Fila* f);
int IsFull(Fila* f);
void Entra(Fila* f, TIPO* elem);
void Sai(Fila* f, TIPO* elem);

#endif