#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

float angle = 0.0;
float pivotX = 0.0, pivotY = 0.0;

void drawTriangle() {
    glBegin(GL_TRIANGLES);
    glVertex2f(2.0, 1.0);
    glVertex2f(4.0, 1.0);
    glVertex2f(3.0, 4.0);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Draw original triangle in white
    glColor3f(1.0, 1.0, 1.0);
    drawTriangle();

    // Apply rotation transformation
    glPushMatrix();
    glTranslatef(pivotX, pivotY, 0.0);
    glRotatef(angle, 0.0, 0.0, 1.0);
    glTranslatef(-pivotX, -pivotY, 0.0);
    
    // Draw rotated triangle in red
    glColor3f(1.0, 0.0, 0.0);
    drawTriangle();
    glPopMatrix();

    glutSwapBuffers();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 5, -1, 5);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    printf("Enter rotation angle: ");
    scanf("%f", &angle);
    printf("Enter pivot point (x y): ");
    scanf("%f %f", &pivotX, &pivotY);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Rotating Triangle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
