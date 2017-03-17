#include <cmath>


#ifndef POINT_H
#define POINT_H

class Point {
private:
	double x;
	double y;
public:
	Point();
	Point(double x, double y);
	Point(const Point &p);
	~Point();

	const double getX() const;
	const double getY() const;
	const Point & setX(double x);
	const Point & setY(double y);

	const double distManhattan(const Point &p) const;
};

#endif // !POINT_H
