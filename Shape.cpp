// Shape.cpp
#include "Shape.h"
#include <iostream>

// Parameterized constructor
Shape::Shape(Point click, Color colorFill) : clickmouse(click), colorFill(colorFill){
    layerOder++;
    layer = layerOder;
}

Shape::Shape(Point start, Point end, int layer, Color colorFill) : start(start), end(end), layer(layer) {
}

// Getter functions
Point Shape::getBottomLeft() const {
    return bottomLeft;
}

Point Shape::getTopRight() const {
    return topRight;
}

Point Shape::getCenter() const {
    return clickmouse;
}

Point Shape::getStart() const {
    return start;
}

Point Shape::getEnd() const {
    return end;
}

int Shape::getLayer() const {
    return layer;
}

Color Shape::getColor() const {
    return colorFill;
}

void Shape::setSelectingShape(bool isSelected){
    this->isSelecting = isSelected;
}

void Shape::setColor(Color color) {
    this->colorFill = color;
}

std::string Shape::toStrong() {
    return "Shape";
}

void Shape::translate(double dx, double dy) {
    matrix.Translate(dx, dy);

    construct();
}

void Shape::rotate(double angle) {
    matrix.Translate(-clickmouse.getX(), -clickmouse.getY());
    matrix.Rotate(angle);
    matrix.Translate(clickmouse.getX(), clickmouse.getY());

    construct();
}

void Shape::scale(double sx, double sy) {
    int newXC = sx * clickmouse.getX();
    int newYC = sy * clickmouse.getY();

    matrix.Scale(sx, sy);
    matrix.Translate(clickmouse.getX() - newXC, clickmouse.getX() - newYC);

    construct();
}
