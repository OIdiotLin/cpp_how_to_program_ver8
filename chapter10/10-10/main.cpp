// Author:	LHD
// System:	Win 10
// Problem:	10.10 (Card Shuffling and Dealing)

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "DeckOfCards.h"

using namespace std;

int main() {
	srand(time(NULL));
	
	DeckOfCards deck;

	deck.shuffle();
	int count = 0;
	while (deck.moreCards()) {
		cout << "round " << ++count << ":\t" 
			 << deck.dealCard().toString() << endl;
	}

	return 0;
}
