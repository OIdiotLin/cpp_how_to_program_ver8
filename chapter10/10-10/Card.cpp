#include <sstream>

#include "Card.h"

const string Card::FACE_NAME[Card::TOTAL_FACE] = {
	"Ace", "Deuce", "Three", "Four", "Five", "Six",
	"Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"
};

const string Card::SUIT_NAME[Card::TOTAL_SUIT] = {
	"Spade", "Heart", "Club", "Diamond"
};

Card::Card(Face face, Suit suit) {
	this->face = face;
	this->suit = suit;
}

Card::~Card() {}

Card & Card::setFace(Face face) {
	this->face = face;
	return *this;
}

Card & Card::setSuit(Suit suit) {
	this->suit = suit;
	return *this;
}

const Face Card::getFace() const {
	return this->face;
}

const Suit Card::getSuit() const {
	return this->suit;
}

const string Card::toString() const {
	std::ostringstream oss;
	oss << FACE_NAME[this->face] << " of " << SUIT_NAME[this->suit];
	return oss.str();
}

Face operator++(Face &f, int x) {
	Face old = f;
	f = (Face)(f + 1);
	return old;
}

Suit operator++(Suit &s, int x) {
	Suit old = s;
	s = (Suit)(s + 1);
	return old;
}
