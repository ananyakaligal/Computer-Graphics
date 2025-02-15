#include <GL/glut.h>

int x1 = 200, y_start = 250, x2 = 100, y_end = 100;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    int dx = abs(x2 - x1);
    int dy = abs(y_end - y_start);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y_start < y_end) ? 1 : -1;
    int error = dx - dy;
    int x = x1, y = y_start;

    while (1) {
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        glFlush();

        if (x == x2 && y == y_end) break;

        int e2 = 2 * error;
        if (e2 > -dy) { 
            error -= dy; 
            x += sx; 
            }
        if (e2 < dx) { 
            error += dx; 
            y += sy; 
            }
    }
}

int main(int argc, char** argv) {
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
