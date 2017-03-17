#ifndef RECTANGLE_H
#define RECTANGLE_H


class Rectangle {
private:
	double length;
	double width;
public:
	Rectangle(double length = 1, double width = 1);
	~Rectangle();

	const double getLength() const;
	const double getWidth() const;
	const Rectangle & setLength(const double& length);
	const Rectangle & setWidth(const double& width);

	const double calcPerimeter() const;
	const double calcArea() const;
};


#endif // !RECTANGLE_H
