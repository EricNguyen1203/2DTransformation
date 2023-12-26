#pragma once
#include "Color.h"

class Cell
{
private:
    Color color;
    int layer;
    bool boundary;

public:
    Cell(Color color = Color::m_WHITE);

public:
    void setCell(Color color, int layer = 0, bool boundary = false);

    void setColor(Color color);

    void setLayer(int layer);

    Color getColor();

    int getLayer();

    bool isBoundary();

    void clear();
};

