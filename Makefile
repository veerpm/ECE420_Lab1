CFLAGS = -g -Wall

main: main.o
	gcc -o main main.o

compile: main.c
	gcc -c ${CFLAGS} main.c

clean:
	-rm -f main.o main