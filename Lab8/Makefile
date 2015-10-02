all: lab8

lab8: main.o
	g++ -g main.o -o lab8

main.o: main.cpp PriorityQueue.h
	g++ -g -c main.cpp

clean:
	rm -rf *~ *.o lab8
