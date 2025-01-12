CFLAGS = -g -Wall

main: main.o lab1_IO.o
	gcc -o main main.o lab1_IO.o

compile: main.c lab1_IO.c
	gcc -c ${CFLAGS} main.c
	gcc -c ${CFLAGS} lab1_IO.c

clean:
	-rm -f main.o lab1_IO.o main