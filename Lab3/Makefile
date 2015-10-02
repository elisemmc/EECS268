all: lab3

lab3: main.o suit.o
	g++ -g main.o suit.o -o lab3

main.o: main.cpp suit.h
	g++ -c -g main.cpp

suit.o: suit.cpp suit.h
	g++ -c -g suit.cpp

clean:
	rm -f *.o *~ lab3
