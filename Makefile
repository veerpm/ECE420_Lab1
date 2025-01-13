CFLAGS = -g -Wall

all: main serial

main: main.o lab1_IO.o
	gcc -o main main.o lab1_IO.o -lm

serial: serial.o lab1_IO.o
	gcc -o serial serial.o lab1_IO.o

main.o: main.c lab1_IO.h
	gcc -c $(CFLAGS) main.c

serial.o: serial.c lab1_IO.h
	gcc -c $(CFLAGS) serial.c

lab1_IO.o: lab1_IO.c lab1_IO.h
	gcc -c $(CFLAGS) lab1_IO.c

clean:
	-rm -f main serial main.o serial.o lab1_IO.o
