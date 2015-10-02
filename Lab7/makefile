# Makefile builds the executable for Lab7 assignment by default
#
KUID = 2298962
LAB_NAME = Lab7

all: Lab7

Lab7: main.o calc.o
	g++ -g main.o calc.o -o Lab7

main.o: calc.h main.cpp
	g++ -g -c main.cpp

calc.o: calc.cpp
	g++ -g -c calc.cpp

clean:
	rm *.o Lab7
