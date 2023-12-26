#include "Polygon.h"
#include "utils.h"
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

void Polygon::findFillPoint() {
    int x = 0, y = 0;
    if (vertices.size() > 0) {
        for (int i = 0; i < vertices.size(); i++) {
            x += vertices[i].getX();
            y += vertices[i].getY();
        }
        x /= vertices.size();
        y /= vertices.size();
    }
    else {
        x = clickmouse.getX();
        y = clickmouse.getY();
    }

    fillPoint = Point(clip(x, 0, WIN_WIDTH - 1), clip(y, 0, WIN_LENGTH - 1));
}

void Polygon::fill(Canvas& canvas) {
    if (this->vertices.size() == 0)
        return;
    this->findFillPoint();
    ColorFilling::boundaryFill(this->fillPoint.getX(), this->fillPoint.getY(), layer, colorFill, canvas);
    return;
}

std::string Polygon::toString() {
	return "Polygon";
}