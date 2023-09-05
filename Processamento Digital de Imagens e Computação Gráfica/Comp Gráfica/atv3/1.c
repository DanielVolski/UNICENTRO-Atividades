// #define GL_SILENCE_DEPRECATION
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glext.h>
#include "glut.h"
#include <stdlib.h>
#include <stdio.h>

GLfloat distance = 4;
GLfloat azimuth = 0;
GLfloat incidence = 0;
GLfloat twist = 0;

GLfloat planet1Rotation = 0.0;
GLfloat planet2Rotation = 0.0;

void polarView(GLfloat distance, GLfloat azimuth, GLfloat incidence, GLfloat twist) {
    glTranslatef(0.0, 0.0, -distance);
    glRotatef(-twist, 0.0, 0.0, 1.0);
    glRotatef(-incidence, 1.0, 0.0, 0.0);
    glRotatef(-azimuth, 0.0, 0.0, 1.0);
}

void display()
{
    const double a = glutGet(GLUT_ELAPSED_TIME) / 100;

    /* Limpa todos os pixels da tela */
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

    polarView(distance, azimuth, incidence, twist);

    glColor3f(1, 1, 0);
    glPushMatrix();
    glRotatef(a, 0, 0, 1);
    glutWireSphere(0.3, 30, 30);
    glPopMatrix();

    glColor3f(1, 0, 0);
    glPushMatrix();
    glRotatef(a, 0, 0, 1);
    glTranslatef(0.8, 0, 0);
    glRotatef(-a * 10, 0, 0, 1);
    glutWireSphere(0.2, 10, 10);
    glPopMatrix();


    glColor3f(0, 0, 1); 
    glPushMatrix();
    glRotatef(a, 0, 1, 0); 
    glTranslatef(1.5, 0, 0); 
    glRotatef(planet1Rotation, 0, 1, 0);
    glutWireSphere(0.15, 20, 20);
    glPopMatrix();

    glPopMatrix();

    /* Troca buffers – double-buffering */
    glutSwapBuffers();
}

void myReshape(int winWidth, int winHeight)
{
    int tam = winWidth < winHeight ? winWidth : winHeight;
    glViewport(0, 0, tam, tam);
}

void myKeyboard(unsigned char c, int x, int y)
{
    switch (c) {
    case 27:
        exit(0);
        break; // ESC
    case 'a':
        azimuth -= 0.5;
        break;
    case 'd':
        azimuth += 0.5;
        break;
    case 'w':
        incidence -= 0.5;
        break;
    case 's':
        incidence += 0.5;
        break;
    case 'q':
        twist -= 0.5;
        break;
    case 'e':
        twist += 0.5;
        break;
    case 'z':
        distance -= 0.1;
        break;
    case 'x':
        distance += 0.1;
        break;
    }
    glutPostRedisplay();
}

void keySpecial(int key, int x, int y)
{
    switch (key) {
    case GLUT_KEY_LEFT:
        azimuth -= 0.5;
        break;
    case GLUT_KEY_RIGHT:
        azimuth += 0.5;
        break;
    case GLUT_KEY_UP:
        incidence -= 0.5;
        break;
    case GLUT_KEY_DOWN:
        incidence += 0.5;
        break;
    }
    glutPostRedisplay();
}

void myMouse(int b, int s, int x, int y)
{
    switch (b) {
    case GLUT_LEFT_BUTTON:
        printf("(%d, %d)\n", x, y);
    }
}

void myMotion(int x, int y)
{
    printf("Motion: (%d, %d)\n", x, y);
}

void idle()
{
    planet1Rotation += 0.1;
    planet2Rotation += 1.0;
    glutPostRedisplay();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1, 1, 10);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Atividad 3.1");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(myReshape);
    glutKeyboardFunc(myKeyboard);
    glutSpecialFunc(keySpecial);
    glutMouseFunc(myMouse);
    glutMotionFunc(myMotion);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}