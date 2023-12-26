#include "AppProcessor.h"

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    std::cout << "Le Hinh Nhut Thanh - 21120132 - 21CNTN" << std::endl;
    std::cout << "Computer graphics - Lab 2: 2D Filling Color" << std::endl;
    std::cout << "-----------------------------------------------------------------" << std::endl;

    AppProcessor::Init();

    AppProcessor::canvas = Canvas(AppProcessor::sreenWidth, AppProcessor::sreenLength);

    AppProcessor::createMenu();

    glClearColor(1.0, 1.0, 1.0, 0.0);
    gluOrtho2D(0.0, AppProcessor::sreenWidth, 0.0, AppProcessor::sreenLength);

    // Đăng ký hàm callback cho sự kiện nhấn chuột
    glutMouseFunc(AppProcessor::mouseCallback);

    // Đăng ký hàm display để vẽ
    glutDisplayFunc(AppProcessor::display);

    glutMainLoop();
    return 0;
}