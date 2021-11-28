all: func

func: main.o libarith.a
	gcc -o func main.o libarith.a

main.o: main.c
	gcc -c -o main.o main.c

clean:
	rm -rf func
