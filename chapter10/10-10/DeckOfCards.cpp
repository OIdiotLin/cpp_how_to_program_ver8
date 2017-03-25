#include <algorithm>

#include "DeckOfCards.h"

/**
 * Random Sys
 */

inline int rand(int l, int r) {
	return rand() % (r - l + 1) + l;
}

/**
 * Class DeckOfCards
 */

DeckOfCards::DeckOfCards() {
	initialize();
	currentCard = 0;
}

DeckOfCards::~DeckOfCards() {}

DeckOfCards & DeckOfCards::initialize() {
	deck.clear();

	for (Face face = Ace; face <= King; face++) {
		for (Suit suit = Spade; suit <= Diamond; suit++) {
			deck.push_back(Card(face, suit));
		}
	}

	return *this;
}

DeckOfCards & DeckOfCards::shuffle() {
	for (vector<Card>::iterator c1 = deck.begin();c1 != deck.end();++c1) {
		vector<Card>::iterator c2 = deck.begin() + rand(0, TOTAL_CARD - 1);
		std::swap(*c1, *c2);
	}

	return *this;
}

const Card & DeckOfCards::dealCard() {
	return deck[currentCard++];
}

const bool DeckOfCards::moreCards() const {
	return TOTAL_CARD - currentCard;
}


