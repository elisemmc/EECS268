#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <assert.h>

#include "PriorityQueue.h"

using namespace std;

//test function for integer priority queue
void test1();
//test function for float priority queue
void test2();
//test function for char priority queue
void test3();

int main(int argc, char* argv[])
{

	//Uncomment the tests to test your implementation
	test1();
 	test2();
 	test3();

}

void test1()
{
	PriorityQueue<int> Q1;
	int test = 0;

	cout <<  "********** TEST 1 ***********************************************"<< endl;

	Q1.enqueue(1);
	Q1.enqueue(10);
	Q1.enqueue(5);

	cout << "Printing Q1" << endl;
	cout << Q1 << endl;

	assert(Q1.getSize() == 3);

	Q1.peek(test);

	assert(test == 10);

	cout << "Test 1 PASSED" << endl;
}


void test2()
{
	PriorityQueue<float> Q2;
	float temp;
	int Q_size;

	cout <<  "********** TEST 2 ***********************************************"<< endl;

	for(float i = 1200.0; i > 0.0; i -=0.5)
		Q2.enqueue(i);

	Q_size = Q2.getSize();
	cout << "Q2 size: " << Q_size << endl;

	for(int i = 0; i < 1200; i++)
		Q2.dequeue();

	Q_size = Q2.getSize();
	cout << "Q2 size: " << Q_size << endl;

	for(float i = 600.0; i > 0.0; i -=0.5){
		Q2.dequeue(temp);
		assert(temp == i);
	}

	Q_size = Q2.getSize();
	cout << "Q2 size: " << Q_size << endl;

	assert(Q2.getSize() == 0);

 	cout<< "Test2 Passed" << endl;
}

void test3()
{
	PriorityQueue<char> Q3;
	PriorityQueue<char> Q4;

	char item;

	cout <<  "********** TEST 3 ***********************************************"<< endl;

	Q3.enqueue('a');
	Q3.enqueue('p');
	Q3.enqueue('p');
	Q3.enqueue('l');
	Q3.enqueue('e');
	Q3.enqueue('s');


	Q3.peek(item);
	assert(item == 's');

	cout << "Printing Q3" << endl;
	cout << Q3 << endl;

	Q3.dequeue();

	assert(Q3.getSize() == 5);

	Q4 = Q3;

	Q4.enqueue('s');
	
	cout << "Printing Q4" << endl;
	cout << Q4 << endl;

	Q4.peek(item);
	assert(item == 's');

	assert(Q4.getSize() == 6);
	
	cout << "Test3 Passed" << endl;

}

