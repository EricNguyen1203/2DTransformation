#include "Cell.h"

Cell::Cell(Color color) {
    this->color = color;
    layer = 0;
    boundary = false;
}


void Cell::setCell(Color color, int layer, bool boundary) {
    this->color.setColor(color.getRed(), color.getGreen(), color.getBlue());
    this->layer = layer;
    this->boundary = boundary;
}

void Cell::setColor(Color color) {
    this->color = color;
}

void Cell::setLayer(int layer) {
    this->layer = layer;
}

Color Cell::getColor() {
    return color;
}

int Cell::getLayer() {
    return layer;
}

bool Cell::isBoundary() {
    return boundary;
}

void Cell::clear() {
    color = Color::m_WHITE;
    layer = 0;
    boundary = false;
}