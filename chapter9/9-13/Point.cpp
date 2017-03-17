#include "Point.h"


Point::Point() {

}

Point::Point(double x, double y){
	this->x = x;
	this->y = y;
}

Point::Point(const Point &p) {
	this->x = p.x;
	this->y = p.y;
}

Point::~Point() {
}

const double Point::getX() const {
	return this->x;
}

const double Point::getY() const {
	return this->y;
}

const Point & Point::setX(double x) {
	this->x = x;
	return *this;
}

const Point & Point::setY(double y) {
	this->y = y;
	return *this;
}

const double Point::distManhattan(const Point &p) const {
	return fabs(this->getX() - p.getX()) + fabs(this->getY() - p.getY());
}
