#include <GL/glut.h>
#include <stdio.h>

// Circle center (xc, yc) and radius r
int xc = 0, yc = 0, r; 


// Function to plot points using 8-way symmetry
void plotPoints(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(xc + x, yc + y); // (+ +)
    glVertex2i(xc - x, yc + y); // (- +)
    glVertex2i(xc + x, yc - y); // (+ -)
    glVertex2i(xc - x, yc - y); // (- -)
    glVertex2i(xc + y, yc + x); // (+ +)
    glVertex2i(xc - y, yc + x); // (- +)
    glVertex2i(xc + y, yc - x); // (+ -)
    glVertex2i(xc - y, yc - x); // (- -)
    glEnd();
}

// Bresenham's Circle Drawing Algorithm
void drawCircle() {
    int x = 0, y = r;
    // Decision parameter
    // 5/4 - r is the formula for decision parameter
    // this is to decide which point is closest to
    // actual circle's path
    int d = 5 / 4 - r;

    while (x <= y) {
        plotPoints(x, y); // Plot the symmetric points
        x++; // Increment the X value

        if (d < 0) {
            d += 4 * x + 6;
        } else {
            y--;
            d += 4 * (x - y) + 10;
        }
    }
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(5.0);
    drawCircle(); 
    glFlush();
}

// OpenGL
void init() {
    glClearColor(0.2, 0.3, 0.5, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200, 200, -200, 200); 
}

// Main
int main(int argc, char** argv) {

    printf("Enter the radius of Circle: ");
    scanf("%d", &r);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Brzzz Circle drawing");

    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
