all:	grafo	lista
	gcc -o	Main	Lista.o	Grafo.o	src/Main.c

lista:
	gcc	-c	src/lista.c

grafo:
	gcc	-c	src/grafo.c

run:
	./Main

clean:
	rm	*.o bin/* Main

