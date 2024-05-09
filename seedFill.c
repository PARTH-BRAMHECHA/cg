#include <GL/glut.h>
#include <GL/gl.h>
#include<stdio.h>

typedef struct pixel
{
    float r, g, b;
}pixel;
pixel f_clr, b_clr;

void dda(float x1, float y1, float x2, float y2) {
    double dx = (x2 - x1);
    double dy = (y2 - y1);
    double steps;
    float xInc, yInc, x = x1, y = y1;

    steps = (abs(dx) > abs(dy)) ? (abs(dx)) : (abs(dy));
    xInc = dx / (float)steps;
    yInc = dy / (float)steps;
    glBegin(GL_POINTS);
    glVertex2d(x, y);
    for (int i = 0; i < steps; i++) {
        x += xInc;
        y += yInc;
        glVertex2d(x, y);
    }
    glEnd();
}

void boundary_fill(int x, int y)
{
    pixel c;
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, &c);
    if ((c.r != b_clr.r || c.g != b_clr.g || c.b != b_clr.b) && (c.r != f_clr.r || c.g != f_clr.g || c.b != f_clr.b))
    {
        glBegin(GL_POINTS);
        glColor3f(f_clr.r, f_clr.g, f_clr.b);
        glVertex2i(x, y);
        glEnd();
        glFlush();
        boundary_fill(x - 1, y);
        boundary_fill(x + 1, y);
        boundary_fill(x, y - 1);
        boundary_fill(x, y + 1);
    }
    glFlush();
}


void square() {

    dda(100, 100, 100, -100);
    dda(-100, 100, -100, -100);
    dda(100, 100, -100, 100);
    dda(100, -100, -100, -100);
}

void render() {
    int xmax, ymax, i;
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    gluOrtho2D(0, 500, 0, 500);
    dda(100, 400, 400, 400);
    dda(100, 450, 400, 450);
    dda(100, 400, 100, 450);
    dda(400, 400, 400, 450);
    /*for(i=1;i<=4;i++)
    {
        dda(100+i*60,400,100+i*60,450);
    }*/
    //coloring color palette
    f_clr.r = 1.0f;
    f_clr.g = 0.0f;
    f_clr.b = 0.0f;
    boundary_fill(130, 425);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("seedfill");
    glutDisplayFunc(render);
    glutMainLoop();
    return 0;
}