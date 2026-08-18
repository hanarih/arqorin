default: main

busca.o: busca.c busca.h
	gcc -c busca.c -o busca.o

main.o: main.c
	gcc -c main.c -o main.o

main: main.o busca.o
	gcc main.o busca.o -o main

clean:
	rm *.o main