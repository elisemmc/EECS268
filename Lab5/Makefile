all: lab5

lab5: main.cpp triangle.o
	g++ -g main.cpp triangle.o -o lab5

triangle.o: triangle.cpp triangle.h
	g++ -c -g triangle.cpp

clean:
	rm -f *.o *~ lab5
