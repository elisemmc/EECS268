#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
using namespace std;

//card indexes in the private rank array
#define ACE			0
#define KING		1
#define QUEEN		2
#define JACK		3
#define TEN			4
#define NINE		5
#define EIGHT		6
#define SEVEN		7
#define SIX			8
#define FIVE		9
#define FOUR		10
#define THREE		11
#define TWO			12

//define card suits
#define HEARTS			'H'
#define DIAMONDS		'D'
#define CLUBS			'C'
#define SPADES			'S'

//score definitions
#define SINGLETON_SCORE			2
#define DOUBLETON_SCORE			1
#define VOID_SCORE				3

#define ACE_SCORE					4
#define KING_SCORE				3
#define QUEEN_SCORE				2
#define JACK_SCORE				1

class suit
{

private:
	bool rank[13];
	
public:
	suit();
	~suit();
	void set_card(char card);
	void write_suit(ofstream &file);
};
