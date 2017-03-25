#ifndef DECK_OF_CARDS_H
#define DECK_OF_CARDS_H

#include <vector>

#include "Card.h"

using std::vector;

class DeckOfCards {
private:
	vector<Card> deck;
	int currentCard;

public:
	static const int TOTAL_CARD = 52;
	DeckOfCards();
	~DeckOfCards();

	DeckOfCards & initialize();
	DeckOfCards & shuffle();
	const Card & dealCard();
	const bool moreCards() const;
};

#endif // !DECK_OF_CARDS_H
