#pragma once
#include "Header.h"


class AppProcessor
{
public :
	static int option;

	static std::vector<Shape*> temp;

	static int sreenWidth;
	
	static int sreenLength;

	static Canvas canvas;

	static Color defaultColor;

	static Shape* pickedShape;

public:
	static void menuCallback(int value);

	static void createMenu(void);

	static void mouseCallback(int button, int state, int x, int y);

	static void normalKeyPressed(unsigned char key, int x, int y);

	static void specialKeyPressed(int key, int x, int y);

	static void display();

	static void changeMouseCursor(int cursorType);

	static void Init();
};

