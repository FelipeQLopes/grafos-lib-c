all: estruturas grafos main
	gcc build/*.o -o build/main

run: all
	./main

limpar:
	rm -f build/*

estruturas:
	gcc src/estruturas.c -c -o build/estruturas.o

grafos:
	gcc src/grafos.c -c -o build/grafos.o

main:
	gcc src/main.c -c -o build/main.o