all: lab11

lab11: BinaryTree.o main.cpp
	g++ -g main.cpp BinaryTree.o -o lab11
BinaryTree.o: BinaryTree.cpp BinaryTree.h
	g++ -g -c BinaryTree.cpp

clean:
	rm -rf *~ *.o lab11
