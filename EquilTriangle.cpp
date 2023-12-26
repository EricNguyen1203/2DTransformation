#include "EquilTriangle.h"

EquilTriangle::EquilTriangle(Point click, Color colorFill) : Triangle(click, colorFill) {

	this->construct();
}

void EquilTriangle::construct() {
	// Rotate the other two vertices by 120 and 240 degrees around the center
	double angle60 = M_PI / 3.0;
	this->bottomLeft.setX(clickmouse.getX() - static_cast<int>(distance * std::sin(angle60)));
	this->bottomLeft.setY(clickmouse.getY() - static_cast<int>(distance * std::cos(angle60)));

	this->topRight.setX(clickmouse.getX() + static_cast<int>(distance * std::sin(angle60)));
	this->topRight.setY(clickmouse.getY() + distance);

	vertices.push_back(bottomLeft);
	vertices.push_back(Point(bottomLeft.getX() + ((topRight.getX() - bottomLeft.getX()) / 2), topRight.getY()));
	vertices.push_back(Point(topRight.getX(), bottomLeft.getY()));
}

std::string EquilTriangle::toString() {
	return "EquilTriangle";
}