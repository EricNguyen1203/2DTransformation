#include "Arrow.h"


Arrow::Arrow(Point click, Color colorFill) : Polygon(click, colorFill) {
    this->construct();
}

void Arrow::construct() {
    bottomLeft.setX(clickmouse.getX() - (2 * length / 3));
    bottomLeft.setY(clickmouse.getY() - (width / 2));
    topRight.setX(clickmouse.getX() + (length / 3));
    topRight.setY(clickmouse.getY() + (width / 2));

    int nearDistance = width / 4;

    vertices.push_back(Point(bottomLeft.getX(), clickmouse.getY() + nearDistance));
    vertices.push_back(Point(clickmouse.getX(), clickmouse.getY() + nearDistance));
    vertices.push_back(Point(clickmouse.getX(), topRight.getY()));
    vertices.push_back(Point(topRight.getX(), clickmouse.getY()));
    vertices.push_back(Point(clickmouse.getX(), bottomLeft.getY()));
    vertices.push_back(Point(clickmouse.getX(), clickmouse.getY() - nearDistance));
    vertices.push_back(Point(bottomLeft.getX(), clickmouse.getY() - nearDistance));
}

std::string Arrow::toString() {
    return "Arrow";
}
