#include "Color.h"


// Khởi tạo các màu sắc
Color Color::m_BLACK = Color(0, 0, 0);
Color Color::m_WHITE = Color(255, 255, 255);
Color Color::m_RED = Color(255, 0, 0);
Color Color::m_GREEN = Color(0, 255, 0);
Color Color::m_BLUE = Color(0, 0, 255);
Color Color::m_YELLOW = Color(255, 255, 0);
Color Color::m_MAGENTA = Color(255, 0, 255);
Color Color::m_CYAN = Color(0, 255, 255);


std::unordered_map<int, Color> Color::colorMap = {
    {RED, Color::m_RED},
    {GREEN, Color::m_GREEN},
    {BLUE, Color::m_BLUE},
    {YELLOW, Color::m_YELLOW},
    {MAGENTA, Color::m_MAGENTA},
    {CYAN, Color::m_CYAN}
};

Color::Color() {
    r = g = b = 0;
}

void Color::setColor(int r, int g, int b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

int Color::getRed() {
    return r;
}

int Color::getGreen() {
    return g;
}

int Color::getBlue() {
    return b;
}