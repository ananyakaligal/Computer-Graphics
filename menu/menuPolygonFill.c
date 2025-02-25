#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int numSides = 6;  // Initial polygon: Hexagon
float color[3] = {1.0, 0.0, 0.0};  // Default color: Red
bool fillPolygon = true;  // Flag to toggle fill color

void drawPolygon() {
    float radius = 100.0;
    float centerX = 200, centerY = 150;

    if (fillPolygon) {
        glBegin(GL_POLYGON);
        glColor3f(color[0], color[1], color[2]); // Apply fill color
    } else {
        glBegin(GL_LINE_LOOP);
        glColor3f(0.0, 0.0, 0.0); // Black outline when color is removed
    }

    for (int i = 0; i < numSides; i++) {
        float angle = 2.0 * M_PI * i / numSides;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    gluOrtho2D(0.0, 400.0, 0.0, 300.0);
}

void mymenu(int value) {
    switch (value) {
        case 1: numSides = (numSides < 10) ? numSides + 1 : 10; break; // Increase Sides (Max 10)
        case 2: numSides = (numSides > 3) ? numSides - 1 : 3; break; // Decrease Sides (Min 3)
        case 3: color[0] = 1.0; color[1] = 0.0; color[2] = 0.0; fillPolygon = true; break; // Red
        case 4: color[0] = 0.0; color[1] = 1.0; color[2] = 0.0; fillPolygon = true; break; // Green
        case 5: color[0] = 0.0; color[1] = 0.0; color[2] = 1.0; fillPolygon = true; break; // Blue
        case 6: fillPolygon = false; break; // Remove Color
    }
    glutPostRedisplay();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawPolygon();
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Polygon Menu");

    init();
    glutDisplayFunc(display);

    // Submenu for "Draw Polygon"
    int drawSubMenu = glutCreateMenu(mymenu);
    glutAddMenuEntry("Increase Sides", 1);
    glutAddMenuEntry("Decrease Sides", 2);

    // Submenu for "Fill Color"
    int colorSubMenu = glutCreateMenu(mymenu);
    glutAddMenuEntry("Red", 3);
    glutAddMenuEntry("Green", 4);
    glutAddMenuEntry("Blue", 5);

    // Submenu for "Remove Color"
    int removeColorSubMenu = glutCreateMenu(mymenu);
    glutAddMenuEntry("Remove Fill Color", 6);

    // Main Menu
    glutCreateMenu(mymenu);
    glutAddSubMenu("Draw Polygon", drawSubMenu);
    glutAddSubMenu("Fill Color", colorSubMenu);
    glutAddSubMenu("Remove Color", removeColorSubMenu);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;
}
