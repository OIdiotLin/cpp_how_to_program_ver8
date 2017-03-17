#include "Rectangle.h"

Rectangle::Rectangle(Point p1, Point p2, Point p3, Point p4) {
	/*
	if (p1.getX >= 0 && p1.getX <= 20 && p1.getY >= 0 && p1.getY <= 20)
		this->p1 = p1;
	if (p2.getX >= 0 && p2.getX <= 20 && p2.getY >= 0 && p2.getY <= 20)
		this->p2 = p2;
	if (p3.getX >= 0 && p3.getX <= 20 && p3.getY >= 0 && p3.getY <= 20)
		this->p3 = p3;
	if (p4.getX >= 0 && p4.getX <= 20 && p4.getY >= 0 && p4.getY <= 20)
		this->p4 = p4;
	*/
	if (p1.getY() == p2.getY() && p1.getX() == p4.getX() &&
		p2.getX() == p3.getX() && p3.getY() == p4.getY()) {
		this->p1 = p1;
		this->p2 = p2;
		this->p3 = p3;
		this->p4 = p4;
	}
}

Rectangle::~Rectangle() {

}

Rectangle::Rectangle(const Rectangle &rec) {
	*this = rec;
}

const Rectangle & Rectangle::setFillCharacter(const char ch) {
	this->fillCharacter = ch;
}

const Rectangle & Rectangle::setPerimeterCharacter(const char ch) {
	this->perimeterCharacter = ch;
}

const bool Rectangle::isSquare() const {
	return this->width() == this->length();
}

const double Rectangle::width() const {
	return this->p1.distManhattan(this->p2);
}

const double Rectangle::length() const {
	return this->p1.distManhattan(this->p4);
}

const double Rectangle::area() const {
	return this->width() * this->length();
}

const double Rectangle::perimeter() const {
	return (this->width() + this->length()) * 2;
}

const void Rectangle::draw() const {
	for (int y = CANVAS_SIZE; y >= 0;y--) {
		for (int x = 0; x <= CANVAS_SIZE;x++) {
			/* In Rectangle */
			if (x > p1.getX() && x<p3.getX() && y>p1.getY() && y < p3.getY()) {
				std::cout << this->fillCharacter;
			}
			else if (x<p1.getX() || x>p3.getX() || y<p1.getY() || y>p3.getY()) {
				std::cout << CANVAS_BLANK;
			}
			else std::cout << this->perimeterCharacter;
		}
		std::cout << std::endl;
	}
}
