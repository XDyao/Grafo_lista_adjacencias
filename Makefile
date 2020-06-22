all:
	gcc -o	Main	src/Fila.c	src/Lista.c	src/Grafo.c	src/Main.c

run:
	./Main

clean:
	rm	bin/* Main

