#include <stdio.h>
#include <iostream>
#include <string.h>
 
#include <GL/glew.h>
#include <GL/freeglut.h>
 
void display(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
 
    glLoadIdentity();
 
    glBegin(GL_QUADS);
    glVertex3f(-0.5f, -0.5f, 0.0f);
    glVertex3f(-0.5f,  0.5f, 0.0f);
    glVertex3f( 0.5f,  0.5f, 0.0f);
    glVertex3f( 0.5f, -0.5f, 0.0f);
    glEnd();
 
    glutSwapBuffers();
}
 
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
 
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
 
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Square");
 
    glutDisplayFunc(display);
 
    glutMainLoop();
    return 0;
}