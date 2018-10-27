all: ran.o
	gcc -o test ran.c

ran.o: ran.c
	gcc -c ran.c

run:
	./test

clear:
	rm *.o
