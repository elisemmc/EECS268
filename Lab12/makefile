testDriver: TestDriver.o BST.o
	g++ -g TestDriver.o BST.o -o testDriver
TestDriver.o: TestDriver.cpp BST.h BST.o
	g++ -c -g TestDriver.cpp
BST.o: BST.cpp BST.h TreeNode.h KeyedItem.h
	g++ -c -g BST.cpp
clean:
	rm -f *.o testDriver *~
