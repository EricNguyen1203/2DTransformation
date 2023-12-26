#include "Devide.h"

Devide::Devide(Point click, Color colorFill) : Polygon(click, colorFill) {
	this->construct();
}

void Devide::construct() {
	bottomLeft.setX(clickmouse.getX() - length);
	bottomLeft.setY(clickmouse.getY() - width / 2);

	topRight.setX(clickmouse.getX() + length);
	topRight.setY(clickmouse.getY() + width / 2);

	vertices.push_back(bottomLeft);
	vertices.push_back(Point(clickmouse.getX(), topRight.getY()));
	vertices.push_back(topRight);
	vertices.push_back(Point(clickmouse.getX(), bottomLeft.getY()));
}

std::string Devide::toString() {
	return "Devide";
}