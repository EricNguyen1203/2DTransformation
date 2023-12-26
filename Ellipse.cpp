#include "Ellipse.h"
#include "ColorFilling.h"

Ellipse::Ellipse(Point click, Color colorFill) : Shape(click, colorFill) {}

void Ellipse::draw(Canvas& canvas) {
	float x = 0, y = this->b;
	float p = (b * b) - (a * a * b) + (a * a * 0.25);
	float dx = 0, dy = 2 * a * a * y;

	glColor3ub(Color::m_BLACK.getRed(), Color::m_BLACK.getGreen(), Color::m_BLACK.getBlue());

	while (dx <= dy) {
		clickmouse.change(x, y).setPixel(canvas, Color::m_BLACK, layer, true);
		clickmouse.change(x, -y).setPixel(canvas, Color::m_BLACK, layer, true);
		clickmouse.change(-x, y).setPixel(canvas, Color::m_BLACK, layer, true);
		clickmouse.change(-x, -y).setPixel(canvas, Color::m_BLACK, layer, true);
		if (p < 0) {
			p += b * b * (2 * x + 3);
		}
		else {
			p += b * b * (2 * x + 3) - 2 * a * a * (y - 1);
			y -= 1;
			dy = 2 * a * a * y;
		}
		x += 1;
		dx = 2 * b * b * x;
	}
	p = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b;
	while (y >= 0) {
		clickmouse.change(x, y).setPixel(canvas, Color::m_BLACK, layer, true);
		clickmouse.change(x, -y).setPixel(canvas, Color::m_BLACK, layer, true);
		clickmouse.change(-x, y).setPixel(canvas, Color::m_BLACK, layer, true);
		clickmouse.change(-x, -y).setPixel(canvas, Color::m_BLACK, layer, true);
		if (p > 0) {
			p += a * a * (3 - 2 * y);
		}
		else {
			p += 2 * b * b * (x + 1) + a * a * (3 - 2 * y);
			x += 1;
		}
		y -= 1;
	}

	this->fill(canvas);
}


void Ellipse::fill(Canvas& canvas) {
	ColorFilling::boundaryFill(this->getCenter().getX(), this->getCenter().getY(), layer, colorFill, canvas);
	return;
}

std::string Ellipse::toString() {
	return "Ellipse";
}
