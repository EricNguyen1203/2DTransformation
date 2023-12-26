#include "Canvas.h"

Canvas::Canvas() {
    width = 0;
    length = 0;
}

Canvas::Canvas(int width, int length) : width(width), length(length) {
    for (int i = 0; i < length; i++) {
        cells.push_back(std::vector<Cell>(width, Cell()));
    }
}


// NOTICE: x and y are n_row and n_column of the array, not the actual coordinate

Cell Canvas::getCell(int x, int y) {
    if (x < 0 || x >= length || y < 0 || y >= width) {
        return Cell();
    }
    return cells[x][y];
}

bool Canvas::setCell(int x, int y, Color color, int layer, bool boundary) {
    if (x < 0 || x >= length || y < 0 || y >= width) {
        return false;
    }

    if (layer >= cells[x][y].getLayer()) {
        cells[x][y].setCell(color, layer, boundary);
        return true;
    }
    return false;
}

void Canvas::clear() {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            cells[i][j].clear();
        }
    }
}