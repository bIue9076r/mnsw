all: mnsw.o mines

mnsw.o: mnsw.c
	cc -c mnsw.c -o mnsw.o

mines: mnsw.o
	cc mnsw.o -o mines
	
clean:
	rm $(wildcard *.o)
	
remove:
	rm mines