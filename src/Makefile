CC=g++ # compilador
CFLAGS=-Wall -Wextra # compiler flags
EXEC=./tp02 # nome do executavel

# === REGRAS =====

$(EXEC): main.cpp grafo.o
	$(CC) $(CFLAGS) main.cpp grafo.o -o $(EXEC)

main.o: main.cpp
	g++ -c main.cpp

grafo.o: grafo.cpp headers/grafo.h
	g++ -c grafo.cpp

clean:
	rm -rf main.o grafo.o