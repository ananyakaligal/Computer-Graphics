#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

int choice = 0;
int fillType = 0; // 0 for filled, 1 for hollow

void edgedetect(float x1, float y1, float x2, float y2, int *le, int *re)
{
    float mx, x, temp;
    int i;
    if ((y2 - y1) < 0)
    {
        temp = y1;
        y1 = y2;
        y2 = temp;
        temp = x1;
        x1 = x2;
        x2 = temp;
    }
    if ((y2 - y1) != 0)
        mx = (x2 - x1) / (y2 - y1);
    else
        mx = x2 - x1;
    x = x1;
    for (i = y1; i <= y2; i++)
    {
        if (x < (float)le[i])
            le[i] = (int)x;
        if (x > (float)re[i])
            re[i] = (int)x;
        x += mx;
    }
}

void draw_pixel(int x, int y)
{
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void scanfill(int n, float vertices[][2])
{
    int le[500], re[500];
    int i, y;
    for (i = 0; i < 500; i++)
    {
        le[i] = 500;
        re[i] = 0;
    }
    for (i = 0; i < n; i++)
        edgedetect(vertices[i][0], vertices[i][1], vertices[(i + 1) % n][0], vertices[(i + 1) % n][1], le, re);
    
    for (y = 0; y < 500; y++)
    {
        if (le[y] <= re[y])
            for (i = (int)le[y]; i < (int)re[y]; i++)
                draw_pixel(i, y);
    }
}

void drawHollowPolygon(int n, float vertices[][2])
{
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < n; i++)
        glVertex2f(vertices[i][0], vertices[i][1]);
    glEnd();
}

void menu(int num)
{
    if (num == 1)
        choice = 1;
    else if (num == 2)
        choice = 2;
    else if (num == 3)
        choice = 3;
    else if (num == 4)
        choice = 4;
    else if (num == 5)
        exit(0);
    else if (num == 6)
        fillType = 0; // Filled
    else if (num == 7)
        fillType = 1; // Hollow
    glutPostRedisplay();
}

void createMenu(void)
{
    int sub_menu, fill_menu;
    sub_menu = glutCreateMenu(menu);
    glutAddMenuEntry("Triangle", 1);
    glutAddMenuEntry("Rectangle", 2);
    glutAddMenuEntry("Pentagon", 3);
    glutAddMenuEntry("Hexagon", 4);

    fill_menu = glutCreateMenu(menu);
    glutAddMenuEntry("Filled", 6);
    glutAddMenuEntry("Hollow", 7);

    glutCreateMenu(menu);
    glutAddSubMenu("Shapes", sub_menu);
    glutAddSubMenu("Fill Type", fill_menu);
    glutAddMenuEntry("Exit", 5);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    float triangle[3][2] = {{200, 200}, {100, 300}, {300, 300}};
    float rectangle[4][2] = {{100, 100}, {100, 300}, {300, 300}, {300, 100}};
    float pentagon[5][2] = {{200, 100}, {125, 200}, {160, 300}, {240, 300}, {275, 200}};
    float hexagon[6][2] = {{200, 100}, {125, 150}, {125, 250}, {200, 300}, {275, 250}, {275, 150}};
    
    if (choice == 1)
    {
        if (fillType == 0)
            scanfill(3, triangle);
        else
            drawHollowPolygon(3, triangle);
    }
    else if (choice == 2)
    {
        if (fillType == 0)
            scanfill(4, rectangle);
        else
            drawHollowPolygon(4, rectangle);
    }
    else if (choice == 3)
    {
        if (fillType == 0)
            scanfill(5, pentagon);
        else
            drawHollowPolygon(5, pentagon);
    }
    else if (choice == 4)
    {
        if (fillType == 0)
            scanfill(6, hexagon);
        else
            drawHollowPolygon(6, hexagon);
    }
    glFlush();
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Scanline Fill Algorithm");
    init();
    createMenu();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}