all:	grafo	lista fila
	gcc -o	Main	Fila.o	Lista.o	Grafo.o	src/Main.c

lista:
	gcc	-c	src/lista.c

grafo:
	gcc	-c	src/grafo.c

fila:
	gcc	-c	src/fila.c

run:
	./Main

clean:
	rm	*.o bin/* Main

