#include <GL/glut.h>

float xd1, yd1, xd2, yd2;
int xmin = -100;
int ymin = -100;
int xmax = 100;
int ymax = 100;

int getcode(int x, int y)
{
    int c = 0;
    if (y > ymax)
        c = c | 8;
    if (y < ymin)
        c = c | 4;
    if (x > xmax)
        c = c | 2;
    if (x < xmin)
        c = c | 1;
    return c;
}

void display();
void plot(float x, float y)
{
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}
void cohen(float x1, float y1, float x2, float y2)
{
    int c1 = getcode(x1, y1);
    int c2 = getcode(x2, y2);
    float m = (y2 - y1) / (x2 - x1);
    while ((c1 | c2) > 0)
    {
        if (c1 == 0 && c2 == 0)
            return;
        int c;
        float x, y;
        if (c1)
            c = c1;
        else
            c = c2;
        if ((c & 8) != 0)
        {
            y = ymax;
            x = x1 + (1.0 / m) * (ymax - y1);
        }
        if ((c & 4) != 0)
        {
            y = ymin;
            x = x1 + (1.0 / m) * (ymin - y1);
        }
        if ((c & 2) != 0)
        {
            x = xmax;
            y = y1 + m * (xmax - x1);
        }
        if ((c & 1) != 0)
        {
            x = xmin;
            y = y1 + m * (xmin - x1);
        }
        if (c1 == c)
        {
            xd1 = x;
            yd1 = y;
            c1 = getcode(xd1, yd1);
        }
        if (c2 == c)
        {
            xd2 = x;
            yd2 = y;
            c2 = getcode(xd2, yd2);
        }
    }
    display();
}

void dda(float x1, float y1, float x2, float y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    float x = x1;
    float y = y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float x_inc = dx / (float)steps;
    float y_inc = dy / (float)steps;
    plot(x, y);
    for (int i = 0; i < steps; i++)
    {
        plot(x, y);
        x += x_inc;
        y += y_inc;
        glFlush();
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 1);
    dda(xmin, ymin, xmax, ymin);
    dda(xmax, ymin, xmax, ymax);
    dda(xmax, ymax, xmin, ymax);
    dda(xmin, ymax, xmin, ymin);

    glColor3f(0, 1, 1);
    dda(xd1, yd1, xd2, yd2);
    glFlush();
    glEnd();
}

void init()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0, 0, 0, 0);
    gluOrtho2D(-300, 300, -300, 300);
    glMatrixMode(GL_PROJECTION);
}

void key(unsigned char ch, int x, int y)
{
    if (ch == 'c')
    {
        glutPostRedisplay();
        cohen(xd1, yd1, xd2, yd2);
        glFlush();
    }
}

int main(int argc, char** argv)
{
    xd1 = -240;
    yd1 = -120;
    xd2 = 100;
    yd2 = 50;
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_SINGLE);
    glutCreateWindow("abc");
    init();
    glutKeyboardFunc(key);
    glutDisplayFunc(display);
    glutMainLoop();
}