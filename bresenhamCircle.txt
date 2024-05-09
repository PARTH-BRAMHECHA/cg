// #include<stdio.h>
// #include<stdlib.h>
// #include<math.h>
// #include<GL/glut.h>

// void plot(int x, int y) {
//     // glColor3f(1, 1, 1);
//     glBegin(GL_POINTS);
//     glVertex2i(x, y);
//     glEnd();
// }

// void bresenhamCircle(int xc, int yc, int rad) {
//     int x = 0;
//     int y = rad;
//     int d = 3 - 2 * rad;
//     while (x <= y) {
//         x++;
//         if (d <= 0) {
//             d = d + 4 * x + 6;
//         }
//         else {
//             y--;
//             d = d + 4 * (x - y) + 10;
//         }
//         plot(xc + x, yc + y);
//         plot(xc - x, yc + y);
//         plot(xc + x, yc - y);
//         plot(xc - x, yc - y);
//         plot(xc + y, yc + x);
//         plot(xc - y, yc + x);
//         plot(xc + y, yc - x);
//         plot(xc - y, yc - x);

//     }

// }
// void render()
// {
//     glClearColor(0.0, 0.0, 0.0, 0.0);
//     // glPointSize(3.0);
//     glClear(GL_COLOR_BUFFER_BIT);
//     // glMatrixMode(GL_PROJECTION);
//     // glLoadIdentity();
//     gluOrtho2D(-500, 500, -500, 500);
//     glColor3f(0.5, 1.0, 0.0);


//     bresenhamCircle(0, 0, 100);
//     glFlush();
// }
// int main(int argc, char** argv)
// {
//     glutInit(&argc, argv);
//     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//     glutInitWindowSize(700, 700);
//     glutInitWindowPosition(100, 100);
//     glutCreateWindow("Bresenham Circle Drawing Algorithm");
//     glutDisplayFunc(render);
//     glutMainLoop();
//     return 0;
// }

#include <GL/glut.h>

void plot(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void circle(int xc, int yc, int rad) {
    int x = 0;
    int y = rad;
    int d = 3 - 2 * rad;
    while (x <= y) {
        x++;
        if (d <= 0) {
            d = d + 4 * x + 6;
        }
        else {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        plot(xc + x, yc + y);
        plot(xc - x, yc + y);
        plot(xc + x, yc - y);
        plot(xc - x, yc - y);
        plot(xc + y, yc + x);
        plot(xc - y, yc + x);
        plot(xc + y, yc - x);
        plot(xc - y, yc - x);
        glFlush();
    }
}

void init() {
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 500, 0, 500);
}

void draw() {
    glClearColor(0, 0, 0, 0);
    circle(250, 150, 50);
    circle(250, 80, 20);
    circle(250, 50, 10);

    circle(322, 180, 30);
    circle(355, 223, 25);
    circle(375, 263, 20);
    circle(390, 293, 15);


    circle(176, 180, 30);
    circle(145, 223, 25);
    circle(128, 263, 20);
    circle(113, 293, 15);

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham Circle Drawing Algorithm");
    init();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}

// #include <gl/GLUT.h>

// // int xc, yc, radius;
// void plot(int x, int y) {
//     glBegin(GL_POINTS);
//     glVertex2i(x, y);
//     glEnd();
// }

// void circle(int xc, int yc, int rad) {
//     int x = 0;
//     int y = rad;
//     int d = 3 - 2 * rad;
//     while (x <= y) {
//         x++;
//         if (d <= 0) {
//             d = d + 4 * x + 6;
//         }
//         else {
//             y--;
//             d = d + 4 * (x - y) + 10;
//         }
//         plot(xc + x, yc + y);
//         plot(xc - x, yc + y);
//         plot(xc + x, yc - y);
//         plot(xc - x, yc - y);
//         plot(xc + y, yc + x);
//         plot(xc - y, yc + x);
//         plot(xc + y, yc - x);
//         plot(xc - y, yc - x);
//         glFlush();
//     }
// }

// void init() {
//     glClear(GL_COLOR_BUFFER_BIT);
//     gluOrtho2D(0, 500, 0, 500);
// }

// void draw() {
//     glClearColor(0, 0, 0, 0);
//     circle(250, 250, 200);
//     circle(250, 250, 80);

//     circle(250, 350, 100);
//     circle(150, 250, 100);
//     circle(250, 150, 100);
//     circle(350, 250, 100);

//     circle(180, 320, 100);
//     circle(320, 320, 100);
//     circle(180, 180, 100);
//     circle(320, 180, 100);




// }

// int main(int argc, char** argv)
// {
//     glutInit(&argc, argv);
//     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//     glutInitWindowSize(500, 500);
//     glutInitWindowPosition(100, 100);
//     glutCreateWindow("Bresenham Circle Drawing Algorithm");
//     init();
//     glutDisplayFunc(draw);
//     glutMainLoop();
//     return 0;
// }