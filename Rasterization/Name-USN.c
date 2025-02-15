#include <GL/glut.h>
#include <string.h>

// Function to display text using rasterization
void renderBitmapString(float x, float y, void *font, char *string) {
    glRasterPos2f(x, y);  // Set position for text
    for (char *c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set text color (White)
    glColor3f(1.0, 1.0, 1.0);

    // Display Name
    renderBitmapString(-0.3, 0.2, GLUT_BITMAP_HELVETICA_18, "NAME: ANANYA");

    // Display USN
    renderBitmapString(-0.3, -0.1, GLUT_BITMAP_HELVETICA_18, "USN: 1RVU22CSE023");

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);  // Black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);  // Set 2D coordinate system
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Raster Text");

    init();
    glutDisplayFunc(display);
    
    glutMainLoop();
    return 0;
}
