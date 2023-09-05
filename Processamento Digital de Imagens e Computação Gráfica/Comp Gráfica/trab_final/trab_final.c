// #define GL_SILENCE_DEPRECATION
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glext.h>
#include "glut.h"
#include <stdlib.h>
#include <stdio.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int camera = 1;
int wireframe = 1;

GLfloat car_pos_x = 0.0;
GLfloat car_dir = 0.0;
GLfloat wheel_rot = 0.0;

GLfloat character_pos_x = 0.0;
GLfloat character_pos_y = 0.0;
GLfloat character_dir = 0.0;

// Funções de incialização
void init();
void display();
void reshape(int width, int height);
void keyboard(unsigned char key, int x, int y);
// Funções de desenho
void drawPlane();
void drawCar();
void drawSun();
void drawCharacter();

int main(int argc, char **argv) 
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Trabalho final");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    // Iluminação
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glShadeModel(GL_SMOOTH); 
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    
    return 0;
}

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

void display() 
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    if (camera)
        gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    else
        gluLookAt(2.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    
    if (wireframe)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    //drawPlane();
    drawSun();
    drawCar();
    drawCharacter();
    glutSwapBuffers();
}

void reshape(int width, int height) 
{
    int size = width < height ? width : height;
    glViewport(0, 0, width, height);
}

void keyboard(unsigned char key, int x, int y)
{
    int timeElapsed = glutGet(GLUT_ELAPSED_TIME);

    switch (key) {
        case 'w':
            car_pos_x += 0.1;
            wheel_rot = timeElapsed * 1.0;
            break;
        case 's':
            car_pos_x -= 0.1;
            wheel_rot = timeElapsed * -1.0;
            break;
        case 'a':
            car_dir += 5.0;
            wheel_rot = timeElapsed * 1.0;
            break;
        case 'd':
            car_dir -= 5.0;
            wheel_rot = timeElapsed * 1.0;
            break;

        case 'i':
            character_pos_x += 0.1;
            break;
        case 'k':
            character_pos_x -= 0.1;
            break;
        case 'j':
            character_dir += 1.0;
            break;
        case 'l':
            character_dir -= 1.0;
            break;

        case 'e':
            character_pos_y += 0.1;
            break;

        case 'c':
            camera = camera ? 0 : 1;
            break;
        
        case 'x':
            wireframe = wireframe ? 0 : 1;
            break;
    }
    glutPostRedisplay();
}

void drawPlane()
{
    glColor3f(0.5, 0.5, 0.5);

    glPushMatrix();
    
    glScalef(10.0, 1.0, 10.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);

    glBegin(GL_POLYGON);
        glVertex3f(-1.0, -1.0, 0.0);
        glVertex3f(1.0, -1.0, 0.0);
        glVertex3f(1.0, 1.0, 0.0);
        glVertex3f(-1.0, 1.0, 0.0);
    glEnd();

    glPopMatrix();
}

void drawCar() 
{
    glColor3f(1.0, 0.0, 0.0);

    glPushMatrix();
    glRotatef(car_dir, 0.0, 1.0, 0.0);
    glTranslatef(car_pos_x, 0.0, 0.0);
    glScalef(2.0, 0.5, 0.5);
    glutSolidCube(1.0);
    glPopMatrix();

    // As rodas
    glColor3f(0.0, 1, 0.0);

    glPushMatrix();
    glRotatef(car_dir, 0.0, 1.0, 0.0);
    glTranslatef(-0.8 + car_pos_x, -0.4, -0.4);
    glRotatef(wheel_rot, 0, 0, 1.0);
    glutSolidTorus(0.2, 0.3, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glRotatef(car_dir, 0.0, 1.0, 0.0);
    glTranslatef(-0.8 + car_pos_x, -0.4, 0.4);
    glRotatef(wheel_rot, 0, 0, 1.0);
    glutSolidTorus(0.2, 0.3, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glRotatef(car_dir, 0.0, 1.0, 0.0);
    glTranslatef(0.8 + car_pos_x, -0.4, -0.4);
    glRotatef(wheel_rot, 0, 0, 1.0);
    glutSolidTorus(0.2, 0.3, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glRotatef(car_dir, 0.0, 1.0, 0.0);
    glTranslatef(0.8 + car_pos_x, -0.4, 0.4);
    glRotatef(wheel_rot, 0, 0, 1.0);
    glutSolidTorus(0.2, 0.3, 20, 20);
    glPopMatrix();

    //glPushMatrix();
    //glRotatef(car_dir, 0.0, 1.0, 0.0);
    //glPopMatrix();
}

void drawSun() 
{
    GLfloat sun_pos[4] = {2.0, 3.0, -2.0, 1.0};
    GLfloat sun_color[4] = {1.0, 1.0, 1.0, 1.0};

    glLightfv(GL_LIGHT0, GL_POSITION, sun_pos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, sun_color);
    glEnable(GL_LIGHT0);

    glColor3f(1.0, 1.0, 0.0);
    glPushMatrix();
    glTranslatef(2.0, 3.0, -2.0);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();
}

void drawCharacter()
{
    glPushMatrix();
    glTranslatef(character_pos_x, character_pos_y, 0.0);
    glRotatef(character_dir, 0.0, 1.0, 0.0);
    
    // Cabeça
    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(character_pos_x, 1.5 + character_pos_y, 0.0);
    glutSolidSphere(0.2, 20, 20);
    glPopMatrix();

    // Corpo
    glColor3f(0.0, 0.0, 1.0);
    glPushMatrix();
    glTranslatef(0.0 + character_pos_x, 1.0 + character_pos_y, 0.0);
    glScalef(0.2, 0.4, 0.2);
    glutSolidCube(1.0);
    glPopMatrix();

    // Membros
    glColor3f(0.0, 1.0, 0.0);
    glPushMatrix();
    
    // Braço esquerdo
    glTranslatef(-0.3 + character_pos_x, 1.0 + character_pos_y, 0.0);
    glScalef(0.05, 0.3, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();

    // Braço direito
    glPushMatrix();
    glTranslatef(0.3 + character_pos_x, 1.0 + character_pos_y, 0.0);
    glScalef(0.05, 0.3, 0.05); 
    glutSolidCube(1.0);
    glPopMatrix();

    // Perna esquerda
    glPushMatrix();
    glTranslatef(-0.1 + character_pos_x, 0.0 + character_pos_y, 0.0);
    glScalef(0.05, 0.3, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();

    // Perna direita
    glPushMatrix();
    glTranslatef(0.1 + character_pos_x, 0.0 + character_pos_y, 0.0);
    glScalef(0.05, 0.3, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();

    glPopMatrix();

    character_pos_y = 0;
    glutPostRedisplay();
}
