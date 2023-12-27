#include "AppProcessor.h"


int AppProcessor::option = -1;
std::vector<Shape*> AppProcessor::temp;
int AppProcessor::sreenWidth = WIN_WIDTH;
int AppProcessor::sreenLength = WIN_LENGTH;
int Shape::layerOder = 0;
Canvas AppProcessor::canvas = Canvas();

Color AppProcessor::defaultColor = Color::m_CYAN;

Shape* AppProcessor::pickedShape = nullptr;

void AppProcessor::menuCallback(int value) {
    option = value;

    if (option >= RED && option <= CYAN) {
        changeMouseCursor(SELECTING);
        defaultColor = Color::colorMap[option];
        if (pickedShape) {
            pickedShape->setColor(defaultColor);
            glutPostRedisplay();
        }
    }
    if (option >= LINE && option <= DEVIDE) {
        changeMouseCursor(DRAWING);
    }
}

void AppProcessor::createMenu(void) {
    int triangle_menu = glutCreateMenu(AppProcessor::menuCallback);
    glutAddMenuEntry("Vuong can", ISO_TRI);
    glutAddMenuEntry("Deu", EQUI_TRI);

    int quad_menu = glutCreateMenu(AppProcessor::menuCallback);
    glutAddMenuEntry("Hinh chu nhat", RECT);
    glutAddMenuEntry("Hinh vuong", SQUARE);

    int oval_menu = glutCreateMenu(AppProcessor::menuCallback);
    glutAddMenuEntry("Hinh tron", CIRCLE);
    glutAddMenuEntry("Elip", ELLIPSE);

    int re_poly_menu = glutCreateMenu(AppProcessor::menuCallback);
    glutAddMenuEntry("Ngu giac deu", PENTA);
    glutAddMenuEntry("Luc giac deu", HEXA);

    int other_menu = glutCreateMenu(AppProcessor::menuCallback);
    glutAddMenuEntry("Mui ten", ARROW);
    glutAddMenuEntry("Ngoi sao", STAR);

    int ope_menu = glutCreateMenu(AppProcessor::menuCallback);
    glutAddMenuEntry("Cong", ADD);
    glutAddMenuEntry("Tru", MINUS);
    glutAddMenuEntry("Nhan", MULTIPLY);
    glutAddMenuEntry("Chia", DEVIDE);

    int color_menu = glutCreateMenu(AppProcessor::menuCallback);
    glutAddMenuEntry("Red", RED);
    glutAddMenuEntry("Green", GREEN);
    glutAddMenuEntry("Blue", BLUE);
    glutAddMenuEntry("Yellow", YELLOW);
    glutAddMenuEntry("Magenta", MAGENTA);
    glutAddMenuEntry("Cyan", CYAN);

    int menu_id = glutCreateMenu(AppProcessor::menuCallback);
    glutAddMenuEntry("Duong thang", LINE);
    // glutAddSubMenu("Pick color", color_menu);
    glutAddSubMenu("Tam giac", triangle_menu);
    glutAddSubMenu("Tu giac", quad_menu);
    glutAddSubMenu("Oval", oval_menu);
    glutAddSubMenu("Da giac deu", re_poly_menu);
    glutAddSubMenu("Hinh khac", other_menu);
    glutAddSubMenu("Dau", ope_menu);
    glutAddSubMenu("To Mau", color_menu);
    glutAddMenuEntry("Chon hinh", PICK_SHAPE);

    glutAddMenuEntry("Quit", QUIT);

    // Attach the menu to the right button
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void AppProcessor::mouseCallback(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (pickedShape) {
            pickedShape->setSelectingShape(false);
            pickedShape = nullptr;
        }
        // std::cout << "Hoho";
        //mouseX = x;
        //mouseY = y;

        GLint viewport[4];
        glGetIntegerv(GL_VIEWPORT, viewport);

        GLint winX = x;
        GLint winY = viewport[3] - y;
        if (option >= LINE && option <= DEVIDE) {
            if (option == LINE) {
                temp.push_back(new Line(Point(winX, winY), defaultColor));
            }
            else if (option == ISO_TRI) {
                temp.push_back(new IsoTriangle(Point(winX, winY), defaultColor));
            }
            else if (option == EQUI_TRI) {
                temp.push_back(new EquilTriangle(Point(winX, winY), defaultColor));
            }
            else if (option == RECT) {
                temp.push_back(new Rectangle(Point(winX, winY), defaultColor));
            }
            else if (option == SQUARE) {
                temp.push_back(new Square(Point(winX, winY), defaultColor));
            }
            else if (option == CIRCLE) {
                temp.push_back(new Circle(Point(winX, winY), defaultColor));
            }
            else if (option == ELLIPSE) {
                temp.push_back(new Ellipse(Point(winX, winY), defaultColor));
            }
            else if (option == PENTA) {
                temp.push_back(new Pentagon(Point(winX, winY), defaultColor));
            }
            else if (option == HEXA) {
                temp.push_back(new Hexagon(Point(winX, winY), defaultColor));
            }
            else if (option == ARROW) {
                temp.push_back(new Arrow(Point(winX, winY), defaultColor));
            }
            else if (option == STAR) {
                temp.push_back(new Star(Point(winX, winY), defaultColor));
            }
            else if (option == ADD) {
                temp.push_back(new Add(Point(winX, winY), defaultColor));
            }
            else if (option == MINUS) {
                temp.push_back(new Minus(Point(winX, winY), defaultColor));
            }
            else if (option == MULTIPLY) {
                temp.push_back(new Multiply(Point(winX, winY), defaultColor));
            }
            else if (option == DEVIDE) {
                temp.push_back(new Devide(Point(winX, winY), defaultColor));
            }
            glutPostRedisplay();
        }
        else if (option == PICK_SHAPE) {
            Cell cell = canvas.getCell(winY, winX);
            Shape* shape = temp[cell.getLayer() - 1];

            // If we click to a "valid" cell (not empty)
            if (shape != nullptr) {
                shape->setSelectingShape(true);
                pickedShape = shape;
            }
            else {
                pickedShape = nullptr;
            }
            glutPostRedisplay();
        }
        
    }
}
void AppProcessor::normalKeyPressed(unsigned char key, int x, int y) {
    if (!pickedShape)
        return;

    double angle = 0.0;
    double sxy = 0.0;
    // L, R, +, - key handlers
    switch (key) {
    case '+':
        sxy = 1.1;
        break;
    case '-':
        sxy = 0.9;
        break;
    case 'l':
        angle = -1;
        break;
    case 'r':
        angle = 1;
        break;
    default:
        return;
    }

    if (angle != 0.0)
        pickedShape->rotate(angle);
    else
        pickedShape->scale(sxy, sxy);

    glutPostRedisplay();
}

void AppProcessor::specialKeyPressed(int key, int x, int y) {
    if (!pickedShape)
        return;

    // Up, down, left, right arrow key handlers
    double dx = 0.0, dy = 0.0;
    switch (key) {
    case GLUT_KEY_LEFT:
        dx = -1;
        break;
    case GLUT_KEY_RIGHT:
        dx = 1;
        break;
    case GLUT_KEY_DOWN:
        dy = -1;
        break;
    case GLUT_KEY_UP:
        dy = 1;
        break;
    default:
        return;
    }

    pickedShape->translate(dx, dy);
    glutPostRedisplay();
}

void AppProcessor::display() {
    glClear(GL_COLOR_BUFFER_BIT);
    canvas.clear();

    glBegin(GL_POINTS);
    if (temp.size() != 0) {
        for (int i = 0; i < temp.size(); i++) {
            temp[i]->draw(canvas);
        }
    }
    glEnd();
    glFlush();
}

void AppProcessor::Init() {
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutInitWindowSize(AppProcessor::sreenWidth, AppProcessor::sreenLength);
    glutInitWindowPosition(200, 200);
    int window = glutCreateWindow("Le Hinh Nhut Thanh - 21120132 - 21CNTN");
}

void AppProcessor::changeMouseCursor(int cursorType) {
    switch (cursorType) {
    case IDLE:
        glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
        break;
    case DRAWING:
        glutSetCursor(GLUT_CURSOR_CROSSHAIR);
        break;
    case SELECTING:
        glutSetCursor(GLUT_CURSOR_TOP_SIDE);
        break;
    default:
        glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
        break;
    }
}