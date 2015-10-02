all: list_example

list_example: Node.o main.o
	g++ -g main.o Node.o -o list_example

main.o: Node.h main.cpp
	g++ -g -c main.cpp

Node.o: Node.h Node.cpp
	g++ -g -c Node.cpp

test1: clean all
	./list_example infile1 infile2

clean:
	rm -f *~ *.o list_example
