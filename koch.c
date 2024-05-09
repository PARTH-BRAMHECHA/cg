#include <gl/GLUT.h>
#include <math.h>
#define radian (3.14/180)

void drawKoch(float xa, float ya, float xb, float yb, int n) {
    float xc, yc, xd, yd;
    xc = (2 * xa + xb) / 3;
    yc = (2 * ya + yb) / 3;
    xd = (2 * xb + xa) / 3;
    yd = (2 * yb + ya) / 3;

    float midx = xc + ((xd - xc) * cos(60 * radian)) + ((yd - yc) * sin(60 * radian));
    float midy = yc - ((xd - xc) * sin(60 * radian)) + ((yd - yc) * cos(60 * radian));

    if (n > 0) {
        drawKoch(xa, ya, xc, yc, n - 1);
        drawKoch(xc, yc, midx, midy, n - 1);
        drawKoch(midx, midy, xd, yd, n - 1);
        drawKoch(xd, yd, xb, yb, n - 1);
    }
    else {
        glBegin(GL_LINES);
        glVertex2f(xa, ya);
        glVertex2f(xc, yc);
        glVertex2f(xc, yc);
        glVertex2f(midx, midy);
        glVertex2f(midx, midy);
        glVertex2f(xd, yd);
        glVertex2f(xd, yd);
        glVertex2f(xb, yb);
        glEnd();
    }
    glFlush();
}

void draw() {
    int n = 5;
    glBegin(GL_LINES);
    drawKoch(600, 100, 800, 400, n);
    drawKoch(800, 400, 400, 400, n);
    drawKoch(400, 400, 600, 100, n);
    glEnd();
}

void init() {
    glClearColor(1, 0, 0, 0);
    glColor3f(1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 1400, 0, 900);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1400, 900);
    glutCreateWindow("abc");
    init();
    glutDisplayFunc(draw);
    glutMainLoop();
}