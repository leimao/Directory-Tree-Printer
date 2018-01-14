# Makefile

CPPFLAGS = -Wall -pedantic -std=c++17

all: tree_print

tree_print: tree.cpp tree.h tree_print.cpp
	g++ $(CPPFLAGS) tree.cpp tree_print.cpp -o tree_print

clean:
	rm *.o tree_print