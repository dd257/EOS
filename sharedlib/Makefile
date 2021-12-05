all: main
	./main

main: main.o libarith.so
	gcc -o main main.o -larith -L.

main.o:main.c
	export LD_LIBRARY_PATH=.
	gcc -o libarith.so -fPIC add.o sub.o
	gcc -c -o main.o main.c

add.o:add.c
	gcc -c -o add.o add.c

sub.o:sub.c
	gcc -c -o sub.o sub.c


	
