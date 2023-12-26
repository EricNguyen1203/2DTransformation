#include "Square.h"

Square::Square(Point click, Color colorFill) : Polygon(click, colorFill) {
	this->construct();
}

void Square::construct() {
	bottomLeft.setX(clickmouse.getX() - side / 2);
	bottomLeft.setY(clickmouse.getY() - side / 2);

	topRight.setX(clickmouse.getX() + side / 2);
	topRight.setY(clickmouse.getY() + side / 2);

	vertices.push_back(bottomLeft);
	vertices.push_back(Point(bottomLeft.getX(), topRight.getY()));
	vertices.push_back(topRight);
	vertices.push_back(Point(topRight.getX(), bottomLeft.getY()));
}

std::string Square::toString() {
	return "Square";
}