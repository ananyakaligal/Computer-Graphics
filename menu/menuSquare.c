#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>

float squareSize = 50.0;  // Initial square size

void drawSquare() {
    float x = 200, y = 150;  // Square center
    float halfSize = squareSize / 2.0;

    glBegin(GL_QUADS);
    glVertex2f(x - halfSize, y - halfSize);
    glVertex2f(x + halfSize, y - halfSize);
    glVertex2f(x + halfSize, y + halfSize);
    glVertex2f(x - halfSize, y + halfSize);
    glEnd();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    gluOrtho2D(0.0, 400.0, 0.0, 300.0);
}

void mymenu(int value) {
    switch (value) {
        case 1: squareSize += 10.0; break; // Increase square size
        case 2: if (squareSize > 10.0) squareSize -= 10.0; break; // Decrease square size
    }
    glutPostRedisplay();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);  // Red square
    drawSquare();
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Square Menu");

    init();
    glutDisplayFunc(display);

    int squareSubMenu = glutCreateMenu(mymenu);
    glutAddMenuEntry("Increase Square Size", 1);
    glutAddMenuEntry("Decrease Square Size", 2);

    glutCreateMenu(mymenu);
    glutAddSubMenu("Square", squareSubMenu);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;
}
