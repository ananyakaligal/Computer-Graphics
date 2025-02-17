#include <GL/glut.h>
#include <string.h>

// To display text
void displayText(float x, float y, const char* text) {
    glRasterPos2f(x, y);
    for (int i = 0; i < strlen(text); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);  

    // Display Name
    glColor3f(0.9, 0.8, 0.7);  // White font
    displayText(0, 0, "Ananya S Kaligal");

    // USN
    displayText(0, -0.25, "BTech SEction A");

    // Section
    displayText(0, -0.5, "1RVU22CSE023");

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);  // Set coordinate system
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(750, 750);
    glutCreateWindow("CIE-Assignment Rasterisation");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
