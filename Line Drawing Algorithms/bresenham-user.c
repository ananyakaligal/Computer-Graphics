#include <GL/glut.h>
#include <stdio.h>

int x1, y_start, x2, y_end;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    int dx = abs(x2 - x1), dy = abs(y_end - y_start);
    int sx = (x1 < x2) ? 1 : -1, sy = (y_start < y_end) ? 1 : -1;
    int error = dx - dy, x = x1, y = y_start;

    while (1) {
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        glFlush();

        if (x == x2 && y == y_end) break;

        int e2 = 2 * error;
        if (e2 > -dy) { error -= dy; x += sx; }
        if (e2 < dx) { error += dx; y += sy; }
    }
}

int main(int argc, char** argv) {
    printf("Enter x1: ");
    scanf("%d", &x1);
    printf("Enter y_start: ");
    scanf("%d", &y_start);
    printf("Enter x2: ");
    scanf("%d", &x2);
    printf("Enter y_end: ");
    scanf("%d", &y_end);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bresenham's Line");

    glClearColor(0, 0, 0, 1);
    gluOrtho2D(0, 500, 0, 500);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
