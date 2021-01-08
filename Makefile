CC := g++ -g -Wall -Werror -std=c++17

all: main kmap.o

main: main.cpp kmap.o
	$(CC) -o $@ $^

kmap.o: min_kmap_solver.cpp kmap.h
	$(CC) -o $@ -c $<


clean:
	rm main kmap.o
