#include "suit.h"
using namespace std;

suit::suit()
{

	//cout << "Constructor called" << endl;

	//we initially have no cards in this suit
	for(unsigned int i = 0; i < 13; i++)
		rank[i] = false;
}

suit::~suit()
{
	//cout << "Deconstructor called" << endl;
}

//this function sets a card to true in the rank[] array
void suit::set_card(char card)
{

	switch(card)
	{
		case 'A':
			rank[ACE] = true;
			break;

		case 'K':
			rank[KING] = true;
			break;

		case 'Q':
			rank[QUEEN] = true;
			break;

		case 'J':
			rank[JACK] = true;
			break;

		case 'T':
			rank[TEN] = true;
			break;

		case '9':
			rank[NINE] = true;
			break;

		case '8':
			rank[EIGHT] = true;
			break;

		case '7':
			rank[SEVEN] = true;
			break;

		case '6':
			rank[SIX] = true;
			break;

		case '5':
			rank[FIVE] = true;
			break;

		case '4':
			rank[FOUR] = true;
			break;

		case '3':
			rank[THREE] = true;
			break;
			
		case '2':
			rank[TWO] = true;
			break;

		default:
			break;
	}
}

//Used to write the cards in a suit to a file
void suit::write_suit(ofstream &file)
{
	for(int i = 0; i < 13; i++){
		if(rank[i] == true){
			switch(i){
				case 0:
					file << "A\t";
					break;

				case 1:
					file << "K\t";
					break;

				case 2:
					file << "Q\t";
					break;

				case 3:
					file << "J\t";
					break;

				case 4:
					file << "T\t";
					break;

				case 5:
					file << "9\t";
					break;

				case 6:
					file << "8\t";
					break;

				case 7:
					file << "7\t";
					break;

				case 8:
					file << "6\t";
					break;

				case 9:
					file << "5\t";
					break;

				case 10:
					file << "4\t";
					break;

				case 11:
					file << "3\t";
					break;

				case 12:
					file << "2\t";
					break;

				default:
					break;
			}
		}
	}

}
