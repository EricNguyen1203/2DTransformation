#include "Line.h"

Line::Line(Point click, Color colorFill) : Shape(click, colorFill) {
	isEdge = false;

	srand(static_cast<unsigned int>(time(nullptr)));

	int delta_x = rand() % 301 - 150;
	int delta_y = rand() % 301 - 150;

	this->start = click + Point(delta_x, delta_y);
	this->end = click + Point(-delta_x, -delta_y);
}

Line::Line(Point start, Point end, int layer) : Shape(start, end, layer) {
	isEdge = true;
}

void Line::draw(Canvas& canvas) {
	int dx, dy, p;
	int incx, incy, inc1, inc2;
	int x, y;

	glColor3ub(this->colorFill.getRed(), this->colorFill.getGreen(), this->colorFill.getBlue());

	dx = this->end.getX() - this->start.getX();
	dy = this->end.getY() - this->start.getY();

	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	if (this->end.getX() < this->start.getX()) incx = -1;
	incy = 1;
	if (this->end.getY() < this->start.getY()) incy = -1;
	x = this->start.getX(); y = this->start.getY();

	if (dx > dy) {
		Point(x, y).setPixel(canvas, this->colorFill, layer, isEdge);
		p = 2 * dy - dx;
		inc1 = 2 * (dy - dx);
		inc2 = 2 * dy;
		for (int i = 0; i < dx; i++) {
			if (p >= 0) {
				y += incy;
				p += inc1;
			}
			else
				p += inc2;
			x += incx;
			Point(x, y).setPixel(canvas, this->colorFill, layer, isEdge);
		}
	}
	else {
		Point(x, y).setPixel(canvas, this->colorFill, layer, isEdge);
		p = 2 * dx - dy;
		inc1 = 2 * (dx - dy);
		inc2 = 2 * dx;
		for (int i = 0; i < dy; i++) {
			if (p >= 0) {
				x += incx;
				p += inc1;
			}
			else
				p += inc2;
			y += incy;
			Point(x, y).setPixel(canvas, this->colorFill, layer, isEdge);
		}
	}
}

void Line::fill(Canvas& canvas) {
	return;
}

std::string Line::toString() {
	return "Line";
}