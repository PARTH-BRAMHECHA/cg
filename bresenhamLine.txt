#include<GL/glut.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void bresenham1(int x1, int y1, int x2, int y2) {
    if (x2 < x1) {
        swap(&x1, &x2);
        swap(&y1, &y2);
    }
    int dx = x2 - x1;
    int dy = y2 - y1;
    int p = 2 * dy - dx;
    glBegin(GL_POINTS);

    int x = x1, y = y1;
    glVertex2d(x, y);
    int yi = 1;

    if (dy < 0) {
        yi = -1;
        dy = -dy;
    }

    for (int k = 1; k <= dx; k++, x++) {
        if (p > 0) {
            y += yi;
            p += 2 * (dy - dx);
        }
        else {
            p += 2 * dy;
        }
        glVertex2d(x, y);
    }
    glEnd();
}

void bresenham2(int x1, int y1, int x2, int y2) {
    if (y2 < y1) {
        swap(&x1, &x2);
        swap(&y1, &y2);
    }
    int dx = x2 - x1;
    int dy = y2 - y1;
    int p = 2 * dx - dy;
    glBegin(GL_POINTS);

    int x = x1, y = y1;
    glVertex2d(x, y);
    int xi = 1;

    if (dx < 0) {
        xi = -1;
        dx = -dx;
    }

    for (int k = 1; k <= dy; k++, y++) {
        if (p > 0) {
            x += xi;
            p += 2 * (dx - dy);
        }
        else {
            p += 2 * dx;
        }
        glVertex2d(x, y);
    }
    glEnd();
}

void bresenham1_dash(int x1, int y1, int x2, int y2) {
    if (x2 < x1) {
        swap(&x1, &x2);
        swap(&y1, &y2);
    }
    int dx = x2 - x1;
    int dy = y2 - y1;
    int p = 2 * dy - dx;
    glBegin(GL_POINTS);

    int x = x1, y = y1;
    glVertex2d(x, y);
    int yi = 1;

    if (dy < 0) {
        yi = -1;
        dy = -dy;
    }

    for (int k = 1; k <= dx; k++, x++) {
        if (p > 0) {
            y += yi;
            p += 2 * (dy - dx);
        }
        else {
            p += 2 * dy;
        }
        if (k % 10 < 5) {
            glVertex2d(x, y);
        }
    }
    glEnd();
}

void bresenham2_dash(int x1, int y1, int x2, int y2) {
    if (y2 < y1) {
        swap(&x1, &x2);
        swap(&y1, &y2);
    }
    int dx = x2 - x1;
    int dy = y2 - y1;
    int p = 2 * dx - dy;
    glBegin(GL_POINTS);

    int x = x1, y = y1;
    glVertex2d(x, y);
    int xi = 1;

    if (dx < 0) {
        xi = -1;
        dx = -dx;
    }

    for (int k = 1; k <= dy; k++, y++) {
        if (p > 0) {
            x += xi;
            p += 2 * (dx - dy);
        }
        else {
            p += 2 * dx;
        }
        if (k % 10 < 5) {
            glVertex2d(x, y);
        }
    }
    glEnd();
}


void bresenham(int x1, int y1, int x2, int y2, int ch) {
    if (ch == 0) {
        if (abs(y2 - y1) > abs(x2 - x1)) {
            bresenham2(x1, y1, x2, y2);
        }
        else {
            bresenham1(x1, y1, x2, y2);
        }
    }
    else {
        if (abs(y2 - y1) > abs(x2 - x1)) {
            bresenham2_dash(x1, y1, x2, y2);
        }
        else {
            bresenham1_dash(x1, y1, x2, y2);
        }
    }
}


void drawMonitor() {
    bresenham(-200, 200, -200, -200, 0);
    bresenham(-200, 200, 200, 200, 0);
    bresenham(200, -200, 70, -200, 0);
    bresenham(-200, -200, -70, -200, 0);
    bresenham(200, -200, 200, 200, 0);

    bresenham(-180, 180, -180, -180, 0);
    bresenham(-180, 180, 180, 180, 0);
    bresenham(180, -180, -180, -180, 0);
    bresenham(180, -180, 180, 180, 0);

    bresenham(-180, -180, -80, 10, 0);
    bresenham(-80, 10, 20, -180, 0);
    bresenham(20, -180, 100, -10, 0);
    bresenham(100, -10, 180, -180, 0);

    bresenham(-70, -200, -90, -250, 0);
    bresenham(70, -200, 90, -250, 0);
    bresenham(-90, -250, 90, -250, 0);

    bresenham(-300, -300, 300, -300, 1);
    bresenham(-300, -350, 300, -350, 1);
}

void render() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-400, 400, -400, 400);
    glPointSize(2.0);
    glColor3f(0.0, 0.0, 0.0);
    drawMonitor();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(900, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham line");
    glutDisplayFunc(render);
    glutMainLoop();
    return 0;
}