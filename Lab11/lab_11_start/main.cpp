#include <iostream>
#include <cstdlib>
#include <string>
#include "BinaryTree.h"

using namespace std;

int main(int argc, char* argv[])
{

	if(argc < 3) {
		cerr << "Usage: ./lab11 <preorderString> <inorderString>" << endl;
		exit(-1);
	}

	string PreOrderString = argv[1];
	string InOrderString = argv[2];

	//reconstruct the tree from the preorder and inorder strings
	BinaryTree HappyLilTree(InOrderString, PreOrderString);

	//print out the tree using all three methods
	HappyLilTree.printPreorderRoutine();
	HappyLilTree.printInorderRoutine();
	HappyLilTree.printPostorderRoutine();

	return 0;
}

