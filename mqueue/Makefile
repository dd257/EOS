all: read send	
	./read
	./send

read: read.c
	gcc -o read read.c -lrt

send: send.c
	gcc -o send send.c -lrt