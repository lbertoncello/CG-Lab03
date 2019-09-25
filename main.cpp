#include <GL/glut.h>
#include <stdio.h>
#include "robo.h"

float coordinate_offset_value = 3.0;
float angle_offset_value = 1.0;
Robo* robo = new Robo();
bool* keyStates = new bool[256];

void keyOperations (void) {  
    if (keyStates['w']) { // If the 'a' key has been pressed  
		robo->incrementGY(coordinate_offset_value);
    }  
    if(keyStates['a']) {
		robo->move(-coordinate_offset_value);
    }
    if(keyStates['s']) {
		robo->incrementGY(-coordinate_offset_value);
    }
    if(keyStates['d']) {
		robo->move(coordinate_offset_value);
    }
	if(keyStates['r']) {
		robo->incrementTheta1(-angle_offset_value);
    }
	if(keyStates['f']) {
		robo->incrementTheta1(angle_offset_value);
    }
	if(keyStates['t']) {
		robo->incrementTheta2(-angle_offset_value);
    }
	if(keyStates['g']) {
		robo->incrementTheta2(angle_offset_value);
    }
	if(keyStates['y']) {
		robo->incrementTheta3(-angle_offset_value);
    }
	if(keyStates['h']) {
		robo->incrementTheta3(angle_offset_value);
    }
} 

void keyPress(unsigned char key, int x, int y) {
    if(key == 'w') {
        keyStates[key] = true;
    }
    if(key == 'a') {
        keyStates[key] = true;
    }
    if(key == 's') {
        keyStates[key] = true;
    }
    if(key == 'd') {
        keyStates[key] = true;
    }
	if(key == 'r') {
        keyStates[key] = true;
    }
	if(key == 'f') {
        keyStates[key] = true;
    }
	if(key == 't') {
        keyStates[key] = true;
    }
	if(key == 'g') {
        keyStates[key] = true;
    }
	if(key == 'y') {
        keyStates[key] = true;
    }
	if(key == 'h') {
        keyStates[key] = true;
    }
}

void keyUp (unsigned char key, int x, int y) {  
    keyStates[key] = false; // Set the state of the current key to not pressed  
}  

void display(void) {
	glClear (GL_COLOR_BUFFER_BIT);
	robo->Desenha();	
	glutSwapBuffers ();
}

void idle(void) {
	keyOperations();

    glutPostRedisplay();
}

void init (void) {
	/* selecionar cor de fundo (preto) */
	glClearColor (0.0, 0.0, 0.0, 0.0);

	/* inicializar sistema de viz. */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-250.0, 250.0, -250.0, 250.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("hello");
	init ();
	glutDisplayFunc(display);

	glutKeyboardFunc(keyPress);
    glutKeyboardUpFunc(keyUp); 

	glutIdleFunc(idle);

	glutMainLoop();

	/* C ANSI requer que main retorne um inteiro */
	return 0;
}
