#include "Polygon.h"
#include "logic.h"
#include "ColorFilling.h"

void Polygon::draw(Canvas& canvas) {
    int n = this->vertices.size();
    for (int i = 0; i < n; i++) {
        Point p1 = this->vertices[i];
        Point p2 = this->vertices[(i + 1) % n];
        Line(p1, p2, this->layer).draw(canvas);
    }
    this->fill(canvas);
}

void Polygon::fill(Canvas& canvas) {
    if (this->vertices.size() == 0)
        return;
    this->findFillPoint();
    ColorFilling::boundaryFill(this->clickmouse.getX(), this->clickmouse.getY(), layer, colorFill, canvas);
    return;
}

void Polygon::construct() {
    vertices = matrix.TransformPoints(vertices);
}

std::string Polygon::toString() {
	return "Polygon";
}