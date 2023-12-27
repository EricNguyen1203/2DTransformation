#include "IsoTriangle.h"

IsoTriangle::IsoTriangle(Point click, Color colorFill) : Triangle(click, colorFill) {
	this->construct();
}

void IsoTriangle::construct() {
	vertices.clear();

	double angle45 = M_PI / 4.0;

	this->bottomLeft.setX(clickmouse.getX() - static_cast<int>(distance * std::sin(angle45)));
	this->bottomLeft.setY(clickmouse.getY() - static_cast<int>(distance * std::cos(angle45)));

	this->topRight.setX(clickmouse.getX() + distance * 3 / 2);
	this->topRight.setY(clickmouse.getY() + distance * 3 / 2);

	vertices.push_back(bottomLeft);
	vertices.push_back(Point(bottomLeft.getX(), topRight.getY()));
	vertices.push_back(Point(topRight.getX(), bottomLeft.getY()));

	Polygon::construct();
}

std::string IsoTriangle::toString() {
	return "IsoTriangle";
}
