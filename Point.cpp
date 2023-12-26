#include "Point.h"

// Default constructor
Point::Point() : x(0), y(0) {}

// Parameterized constructor
Point::Point(int x, int y) : x(x), y(y) {}

void Point::setX(int xNew) {
	this->x = xNew;
}

void Point::setY(int yNew) {
	this->y = yNew;
}

// Getter functions
int Point::getX() const{
    return x;
}

int Point::getY() const {
    return y;
}

void Point::setPixel(Canvas& canvas, Color color, int layer, bool boundary) {
    if (canvas.setCell(y, x, color, layer, boundary)) {
        glVertex2i(x, y);
    }
}

// Overloaded + operator for adding two points
Point Point::operator+(const Point& other) {
    return Point(x + other.x, y + other.y);
}

Point Point::change(int x, int y) {
	return Point(this->x + x, this->y + y);
}