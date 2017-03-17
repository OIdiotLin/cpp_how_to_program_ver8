#include "Rectangle.h"


Rectangle::Rectangle(double length, double width) {
	this->setLength(length);
	this->setWidth(width);
}

Rectangle::~Rectangle()
{
}

const double Rectangle::getLength() const {
	return this->length;
}

const double Rectangle::getWidth() const {
	return this->width;
}

const Rectangle & Rectangle::setLength(const double & length) {
	if (length > 0 && length < 20)
		this->length = length;
	return *this;
}

const Rectangle & Rectangle::setWidth(const double & width) {
	if (width > 0 && width < 20)
		this->width = width;
	return *this;
}

const double Rectangle::calcPerimeter() const {
	return (getLength() + getWidth()) * 2;
}

const double Rectangle::calcArea() const {
	return getLength() * getWidth();
}
