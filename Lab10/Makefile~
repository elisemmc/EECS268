all: lab10

lab10: main.o
	g++ -g main.o -o lab10

main.o: main.cpp Sorts.h
	g++ -g -c main.cpp

clean:
	rm -rf *~ *.o lab10
