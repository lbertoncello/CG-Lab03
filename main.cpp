#include <stdlib.h>
#include <stdio.h> 
#include <GL/glut.h>

#include "robo.h"

int x_window_size = 500;
int y_windows_size = 500;
int x_windows_initial_position = 100;
int y_windows_initial_position = 100;

Robo robo;

void display (void) {
    robo.Desenha();
}

void idle(void) {
    glutPostRedisplay();
}

void init(void) 
{
    /* selecionar cor de fundo (preto) */
    glClearColor(0.0, 0.0, 0.0, 0.0);

    /* Inicializa sistema de viz */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, x_window_size, 0.0, y_windows_size, -1.0, 1.0);
}


int main(int argc, char** argv) 
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(x_window_size, y_windows_size);
    glutInitWindowPosition(x_windows_initial_position, y_windows_initial_position);
    glutCreateWindow("Hello");
    init();
    glutDisplayFunc(display);

    glutIdleFunc(idle);
    glutMainLoop();

    //robo.DesenhaRect(1, 1, 0.5, 0.5, 0.5);

    return 0;
}
