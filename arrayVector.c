#include <GL/glut.h>
#include <stdio.h>

GLfloat points[][2] = {
    {0.0, 0.0},   // Center of the fan
    {0.5, 0.0},   // Right
    {0.35, 0.35}, // Top-right
    {0.0, 0.5},   // Top
    {-0.35, 0.35},// Top-left
    {-0.5, 0.0},  // Left
    {-0.35, -0.35},// Bottom-left
    {0.0, -0.5},   // Bottom
    {0.35, -0.35}, // Bottom-right
    {0.5, 0.0}    // Closing back to the first outer point
};


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(1.0, 0.0, 0.0); // Set point color to red
    glPointSize(5.0); // Set point size
    
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < sizeof(points) / sizeof(points[0]); i++) {
        glVertex2f(points[i][0], points[i][1]);
    }
    glEnd();
    
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL Points Example");
    
    glClearColor(0.0, 0.0, 0.0, 1.0); // Set background color to black
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Set coordinate system
    
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}