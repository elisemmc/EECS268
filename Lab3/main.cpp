#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "suit.h"
using namespace std;

string readFile(char* fileName);

//This program should accept a single argument
//the argument is the name of the card file
int main(int argc, char* argv[])	//change to char** type
{
	suit hearts;
	suit diamonds;
	suit spades;
	suit clubs;
	string cards;
	int hand_score = 0;
	
	//check that the one required argument was supplied
	cout << "Program given " << (argc-1) << " arguments!" << endl;
	if( argc != 2)
	{
		cout << "Program expects a single argument, the input file name!" << endl;
		exit(1);
	}
	
	//get the string from the cards file
	cards = readFile(argv[1]);
	/* DO NOT MODIFY CODE ABOVE THIS LINE ------------------------------------*/

	
	/*********** YOUR CODE STARTS HERE *****************************************/
	//parse the string and store the cards in the correct classes

	//the cards are stored in the string
	//uncomment the line below to print the string for your viewing
	//cout << cards << endl;

	int hcount = 0;
	int scount = 0;
	int ccount = 0;
	int dcount = 0;

       for(int i=1; i<=37; i = i+3){

	 char suit = cards[i];
         char v = cards[i-1];

         if(suit == 'H'){
	    hearts.set_card(v);
	    hcount++;
	  }

	  if(suit == 'D'){
	    diamonds.set_card(v);
	    dcount++;
	  }

	  if(suit == 'S'){
	    spades.set_card(v);
	    scount++;
	  }

	  if(suit == 'C'){
	    clubs.set_card(v);
	    ccount++;
	  }

	  if(v == 'A'){
	    hand_score += 4;
	  }

	  if(v == 'K'){
	    hand_score += 3;
	  }

	  if(v == 'Q'){
	    hand_score += 2;
	  }

	  if(v == 'J'){
	    hand_score += 1;
	  }
	}

	//voids

	if(hcount == 0){
	  hand_score += 3;
	}

	if(dcount == 0){
	  hand_score += 3;
	}

	if(ccount == 0){
	  hand_score += 3;
	}

	if(scount == 0){
	  hand_score += 3;
	}

	//singletons

	if(hcount == 1){
	  hand_score += 2;
	}

	if(dcount == 1){
	  hand_score += 2;
	}

	if(ccount == 1){
	  hand_score += 2;
	}

	if(scount == 1){
	  hand_score += 2;
	}

	//doubletons

	if(hcount == 2){
	  hand_score += 1;
	}

	if(dcount == 2){
	  hand_score += 1;
	}

	if(ccount == 2){
	  hand_score += 1;
	}

	if(scount == 2){
	  hand_score += 1;
	}

	//long suits

	if(hcount > 5){
	  hand_score += (hcount - 5);
	}

	if(dcount > 5){
	  hand_score += (dcount - 5);
	}

	if(ccount > 5){
	  hand_score += (ccount - 5);
	}

	if(scount > 5){
	  hand_score += (scount - 5);
	}


	//now that you have the cards stored correctly, you need to score each hand
	/*********** YOUR CODE STOPS HERE ***********************/

	/* DO NOT MODIFY CODE BELOW THIS LINE---------------------------------------
	 The code below writes the scored hand to a file called scored_hand.txt
	*/
		
	//save the scored hand to a file
	ofstream outFile;	//create file output stream
	outFile.open("scored_cards.txt", (ios::out | ios::trunc));	//open the file
	//explanation of flags
	//		-- ios::out -- opens for output operations
	// 	-- ios::trunc -- if the file previously existed, delete its contents on open

	//if opening file is a success, write the scored hand
	if(outFile.is_open()) {
		outFile << endl << "HEARTS:\t\t";
		hearts.write_suit(outFile);
		outFile << endl << "DIAMONDS:\t";
		diamonds.write_suit(outFile);
		outFile << endl << "SPADES:\t\t";
		spades.write_suit(outFile);
		outFile << endl << "CLUBS:\t\t";
		clubs.write_suit(outFile);
		outFile << endl <<  "SCORE: " << hand_score << endl << endl;
	}

	//save file by closing it
	outFile.close();

	return 0;
}

/* This function is supplied to you.
it opens the file specified by fileName and
reads the reads in the first line of the file */
string readFile(char* fileName)
{
	string cards;
	ifstream cardFile;

	//open the file with the cards
	cardFile.open(fileName, ios::in);

	//check that we correctly opened the file
	if(!cardFile)
	{
		cout << "Unable to open file" << endl;
		exit(1);
	}
	else
	{
		cout << "File Opened!" << endl;
	}

	std::getline( cardFile, cards);

	return cards;
}
