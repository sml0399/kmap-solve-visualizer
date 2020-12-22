CC := g++ -g -Wall -Werror

all: main kmap.o

main: main.c kmap.o
	$(CC) -o $@ $^

kmap.o: min_kmap_solver.cpp kmap.h
	$(CC) -o $@ -c $<


clean:
	rm main kmap.o
