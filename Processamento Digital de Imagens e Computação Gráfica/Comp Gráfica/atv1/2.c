#define GL_SILENCE_DEPRECATION
//#include<GL/glut.h>
//#include<GL/freeglut.h>
//#include<OpenGL/glut.h>
//#include<GLUT/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glext.h>
#include "glut.h"
#include<stdlib.h>
#include<stdio.h>

void display()
{
    /* Limpa todos os pixels da tela */
    glClear(GL_COLOR_BUFFER_BIT);

    /* Desenha um poligono branco (retangulo) */
    glBegin(GL_POLYGON);
        glColor3f(1, 0, 0);
        glVertex3f(-0.1, -0.1, 0);
        glVertex3f(-0.3, 0.1, 0);
        glVertex3f(-0.6, -0.1, 0);
        glColor3f(0, 0, 1);
        glVertex3f(-0.6, -0.6, 0);
        glVertex3f(-0.1, -0.6, 0);
    glEnd();

    glColor3f(1,1,1);
    //glutSolidSphere(0.5, 30, 10);
    //glutWireTeapot(0.5);
    //glutWireTeacup(0.5);

    /* Troca buffers (double-buffering) */
    glutSwapBuffers();
}

void myReshape(int winWidth, int winHeight) // reshape window
{
    int tam = winWidth < winHeight ? winWidth : winHeight;
    glViewport(20, 20, tam, tam); // reset the viewport
}

void myKeyboard(unsigned char c, int x, int y)
{
    switch(c){
        case 'q':
            exit(0);
            break;
    }
}

void keySpecial(int key, int x, int y) {
    printf("(%d, %d)\n", x, y);
    switch(key){
        case GLUT_KEY_LEFT:
            printf("Left pressed\n");
            break;
        case GLUT_KEY_UP:
            printf("Up pressed\n");
            if(glutGetModifiers() == GLUT_ACTIVE_CTRL)
                printf("CTRL pressed\n");
            break;
        case GLUT_ACTIVE_CTRL:
            if(glutGetModifiers() == GLUT_ACTIVE_CTRL)
                printf("CTRL pressed\n");
            break;
    }
}

void myMouse(int b, int s, int x, int y)
{
    switch(b){
        case GLUT_LEFT_BUTTON:
            printf("(%d, %d)\n", x, y);
    }
}

void myMotion(int x, int y){
    printf("Motion: (%d, %d)\n", x, y);
}

void init()
{
    /* Define a cor de fundo (amarelo) */
    glClearColor(1, 1, 0.0, 1);

    /* Inicializa as Matrizes do OpenGL */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0 , 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(300, 200);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Atividade 1.2");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(myReshape);
    glutKeyboardFunc(myKeyboard);
    glutSpecialFunc(keySpecial);
    glutMouseFunc(myMouse);
    glutMotionFunc(myMotion);
    glutMainLoop();

    return 0;
}