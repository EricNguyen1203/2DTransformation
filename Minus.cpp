#include "Minus.h"

Minus::Minus(Point click, Color colorFill) : Polygon(click, colorFill) {
	this->construct();
}

void Minus::construct() {
	bottomLeft.setX(clickmouse.getX() - length / 2);
	bottomLeft.setY(clickmouse.getY() - width / 2);

	topRight.setX(clickmouse.getX() + length / 2);
	topRight.setY(clickmouse.getY() + width / 2);

	vertices.push_back(bottomLeft);
	vertices.push_back(Point(bottomLeft.getX(), topRight.getY()));
	vertices.push_back(topRight);
	vertices.push_back(Point(topRight.getX(), bottomLeft.getY()));
}

std::string Minus::toString() {
	return "Minus";
}
