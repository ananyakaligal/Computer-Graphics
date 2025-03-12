#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

float angle = 0.0;

void applyRotation(float *x, float *y, float centerX, float centerY) {
    float rad = angle * PI / 180.0;
    float cosA = cos(rad);
    float sinA = sin(rad);
    float newX, newY;
    
    *x -= centerX;
    *y -= centerY;
    
    newX = *x * cosA - *y * sinA;
    newY = *x * sinA + *y * cosA;
    
    *x = newX + centerX;
    *y = newY + centerY;
}

void drawTriangle(int rotated) {
    float vertices[3][2] = {
        {2.0, 1.0},
        {4.0, 1.0},
        {3.0, 4.0}
    };

    float centerX = (vertices[0][0] + vertices[1][0] + vertices[2][0]) / 3.0;
    float centerY = (vertices[0][1] + vertices[1][1] + vertices[2][1]) / 3.0;

    if (rotated) {
        for (int i = 0; i < 3; i++) {
            applyRotation(&vertices[i][0], &vertices[i][1], centerX, centerY);
        }
    }

    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 3; i++) {
        glVertex2f(vertices[i][0], vertices[i][1]);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glColor3f(1.0, 1.0, 1.0);
    drawTriangle(0);

    glColor3f(1.0, 0.0, 0.0);
    drawTriangle(1);

    glutSwapBuffers();
}

void update(int value) {
    angle += 1.0; // Increment angle for rotation
    if (angle >= 360.0) {
        angle -= 360.0;
    }
    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // Refresh at ~60 FPS
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 5, -1, 5);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    printf("Enter initial rotation angle: ");
    scanf("%f", &angle);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Rotating Triangle");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0); // Start rotation updates
    glutMainLoop();
    return 0;
}

