all: estruturas grafos main
	mkdir -p build
	gcc build/*.o -o build/main

run:
	./build/main

limpar:
	rm -f build/*

estruturas:
	gcc src/estruturas.c -c -o build/estruturas.o

grafos:
	gcc src/grafos.c -c -o build/grafos.o

main:
	gcc src/main.c -c -o build/main.o