#include <iostream>

#include "Point.h"

#ifndef RECTANGLE_H
#define RECTANGLE_H

#define CANVAS_SIZE 25
#define CANVAS_BLANK '.'

class Rectangle {
private:
	Point p1;
	Point p2;
	Point p3;
	Point p4;
	char fillCharacter;
	char perimeterCharacter;

public:
	Rectangle(Point p1, Point p2, Point p3, Point p4);
	Rectangle(const Rectangle &rec);
	~Rectangle();

	const Rectangle & setFillCharacter(const char ch = '*');
	const Rectangle & setPerimeterCharacter(const char ch = '#');

	const bool isSquare() const;
	const double width() const;
	const double length() const;
	const double area() const;
	const double perimeter() const;

	const void draw() const;

};


#endif // !RECTANGLE_H
