# Makefile

CPPFLAGS = -Wall -pedantic -std=c++17
LIBS = -lstdc++fs

all: tree_print

tree_print: tree.cpp tree.h tree_print.cpp
	g++ $(CPPFLAGS) tree.cpp tree_print.cpp $(LIBS) -o tree_print

clean:
	rm *.o tree_print