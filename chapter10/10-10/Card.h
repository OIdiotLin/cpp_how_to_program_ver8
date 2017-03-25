#ifndef CARD_H
#define CARD_H

#include <string>

using std::string;

enum Face {
	Ace, Deuce, Three, Four, Five, Six,
	Seven, Eight, Nine, Ten, Jack, Queen, King
};
Face operator++(Face&, int x);
enum Suit {
	Spade, Heart, Club, Diamond
};
Suit operator++(Suit&, int x);



class Card {
private:
	Face face;
	Suit suit;

public:
	static const int TOTAL_FACE = 13;
	static const int TOTAL_SUIT = 4;
	static const string FACE_NAME[TOTAL_FACE];
	static const string SUIT_NAME[TOTAL_SUIT];

	Card(Face face, Suit suit);
	~Card();

	Card & setFace(Face face);
	Card & setSuit(Suit suit);
	const Face getFace() const;
	const Suit getSuit() const;

	const string toString() const;
};

#endif // !CARD_H
