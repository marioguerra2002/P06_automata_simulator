CC=g++
CFLAGS=-O0 -g -Wall
DEPS = alphabet.h chain.h symbol.h state.h state.cc nfa.cc
OBJ = main.o

SRC = './src/'

compilar:
	g++ $(CFLAGS) $(SRC)*.cc -o P06_nfa


%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
all: nfa

language: main.o
	g++ -o nfa main.cc alphabet.cc chain.cc symbol.cc state.cc nfa.cc

clean:
	rm -f *.o