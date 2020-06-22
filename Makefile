all:
	gcc -o	Main	src/fila.c	src/lista.c	src/grafo.c	src/main.c

run:
	./Main

clean:
	rm	bin/* Main

