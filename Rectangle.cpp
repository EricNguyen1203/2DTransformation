#include "Rectangle.h"

Rectangle::Rectangle(Point click, Color colorFill = Color::m_BLACK) : Polygon(click, colorFill) {
	this->construct();
}

void Rectangle::construct() {
	vertices.clear();

	bottomLeft.setX(clickmouse.getX() - length / 2);
	bottomLeft.setY(clickmouse.getY() - width / 2);

	topRight.setX(clickmouse.getX() + length / 2);
	topRight.setY(clickmouse.getY() + width / 2);

	vertices.push_back(bottomLeft);
	vertices.push_back(Point(bottomLeft.getX(), topRight.getY()));
	vertices.push_back(topRight);
	vertices.push_back(Point(topRight.getX(), bottomLeft.getY()));

	Polygon::construct();
}

std::string Rectangle::toString() {
	return "Rectangle";
}