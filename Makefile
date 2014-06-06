# Make file

CXX = g++ -O2 -Wall
CXXDBG = g++ -Wall -D_MEASURE_PERFORMANCE_ -DDEBUG

all: trieExample

trieExample: 
	$(CXX) Main.cpp Node.cpp Trie.cpp -o trieExample
	$(CXXDBG) Main.cpp Node.cpp Trie.cpp -o trieExample.debug

clean:
	rm -rf trieExample trieExample.debug