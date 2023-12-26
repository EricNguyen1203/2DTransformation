#pragma once
#include "Cell.h"
#include <vector>

class Canvas
{

private:
    int width;
    int length;
    std::vector<std::vector<Cell>> cells;

public:
    Canvas();

    Canvas(int width, int length);

public:
    // NOTICE: x and y are n_row and n_column of the array, not the actual coordinate

    Cell getCell(int x, int y);

    bool setCell(int x, int y, Color color, int layer, bool boundary);

    void clear();
};

