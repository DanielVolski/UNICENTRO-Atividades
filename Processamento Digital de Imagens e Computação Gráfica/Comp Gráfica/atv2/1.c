// #define GL_SILENCE_DEPRECATION
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glext.h>
#include "glut.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

GLfloat rotationX = 0.0;
bool perspectiveMode = true;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    if (perspectiveMode)
        gluPerspective(45, 1, 1, 100);
    else
        glOrtho(-2, 2, -2, 2, -10, 10);

    glTranslatef(0.0, 0.0, -5.0);
    glRotatef(rotationX, 1.0, 0.0, 0.0);

    glColor3f(1.0, 1.0, 1.0);

    int numLines = 21;
    float step = 0.2;
    float size = (numLines - 1) * step;

    glBegin(GL_LINES);
    for (int i = 0; i < numLines; i++)
    {
        float pos = -size / 2 + i * step;

        glVertex3f(-size / 2, pos, 0);
        glVertex3f(size / 2, pos, 0);

        glVertex3f(pos, -size / 2, 0);
        glVertex3f(pos, size / 2, 0);
    }
    glEnd();

    glutSwapBuffers();
}

void myKeyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'q':
        exit(0);
        break;
    // Troca o modo de projeção
    case 's':
        perspectiveMode = !perspectiveMode;
        glutPostRedisplay();
        break;
    }
}

void keySpecial(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
        rotationX -= 5.0;
        break;
    case GLUT_KEY_RIGHT:
        rotationX += 5.0;
        break;
    }

    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Atividade 2.1");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutDisplayFunc(display);
    glutKeyboardFunc(myKeyboard);
    glutSpecialFunc(keySpecial);
    glutMainLoop();
    return 0;
}