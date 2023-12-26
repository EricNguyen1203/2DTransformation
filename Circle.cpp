#include "Circle.h"
#include "ColorFilling.h"

Circle::Circle(Point click, Color colorFill) : Shape(click, colorFill) {}

void Circle::fill(Canvas& canvas) {
	ColorFilling::boundaryFill(this->getCenter().getX(), this->getCenter().getY(), layer, colorFill, canvas);
	return;
}

void Circle::draw(Canvas& canvas) {
	float x = 0, y = radius;
	float p = 1 - radius;

	glColor3ub(Color::m_BLACK.getRed(), Color::m_BLACK.getGreen(), Color::m_BLACK.getBlue());

	while (x <= y) {
		clickmouse.change(x, y).setPixel(canvas, Color::m_BLACK, layer, true);
		clickmouse.change(x, -y).setPixel(canvas, Color::m_BLACK, layer, true);
		clickmouse.change(-x, y).setPixel(canvas, Color::m_BLACK, layer, true);
		clickmouse.change(-x, -y).setPixel(canvas, Color::m_BLACK, layer, true);
		if (p < 0) {
			p += 2 * (x + 1) + 1;
		}
		else {
			p += 2 * (x + 1) + 1 - 2 * (y - 1);
			y -= 1;
		}
		x += 1;
	}
	x = radius, y = 0;
	p = 1 - radius;
	while (x >= y) {
		clickmouse.change(x, y).setPixel(canvas, Color::m_BLACK, layer, true);
		clickmouse.change(x, -y).setPixel(canvas, Color::m_BLACK, layer, true);
		clickmouse.change(-x, y).setPixel(canvas, Color::m_BLACK, layer, true);
		clickmouse.change(-x, -y).setPixel(canvas, Color::m_BLACK, layer, true);
		if (p < 0) {
			p += 2 * (y + 1) + 1;
		}
		else {
			p += 2 * (y + 1) + 1 - 2 * (x - 1);
			x -= 1;
		}
		y += 1;
	}
	this->fill(canvas);
}

std::string Circle::toString() {
	return "Circle";
}
