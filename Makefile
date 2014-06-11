# Make file

CXX = g++ -O2 -Wall
CXXDBG = g++ -Wall -D_MEASURE_PERFORMANCE_ -DDEBUG

all: clean release debug test

release: 
	$(CXX) Main.cpp Node.cpp Trie.cpp -o trieExample

debug:
	$(CXXDBG) Main.cpp Node.cpp Trie.cpp -o trieExample.debug

clean:
	rm -rf trieExample trieExample.debug
	rm -f out.txt

test:
	./trieExample test.txt > out.txt
	diff out.txt testOutput.txt
