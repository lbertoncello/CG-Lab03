#include "robo.h"


void Robo::DesenhaRect (GLint height, GLint width, GLfloat red, GLfloat green, GLfloat blue) {
    glColor3f (red, green, blue);
	glBegin(GL_QUADS);
		glVertex3f (-width / 2.0, 0, 0.0);
		glVertex3f (width / 2.0, 0, 0.0);
		glVertex3f (width / 2.0, height, 0.0);
		glVertex3f (-width / 2.0, height, 0.0);
	glEnd();
}

void Robo::DesenhaRobo (GLfloat x, GLfloat y, GLfloat thetaWheel, GLfloat theta1, GLfloat theta2, GLfloat theta3) {
	glPushMatrix();
		glTranslatef(x, y, 0.0);
		DesenhaRect(baseHeight, baseWidth, 1.0, 0.0, 0.0);
		DesenhaBraco(0, baseHeight, theta1, theta2, theta3);
	glPopMatrix();
}

void Robo::DesenhaBraco (GLfloat x, GLfloat y, GLfloat theta1, GLfloat theta2, GLfloat theta3) {
	glPushMatrix();
		glTranslatef(x, y, 0.0);
		glRotatef(theta1, 0.0, 0.0, 1.0);
		DesenhaRect(paddleHeight, paddleWidth, 1.0, 1.0, 0.0);

		glTranslatef(x, paddleHeight, 0.0);
		glRotatef(theta2, 0.0, 0.0, 1.0);
		DesenhaRect(paddleHeight, paddleWidth, 1.0, 0.0, 1.0);

		glTranslatef(x, paddleHeight, 0.0);
		glRotatef(theta3, 0.0, 0.0, 1.0);
		DesenhaRect(paddleHeight, paddleWidth, 0.0, 1.0, 1.0);
	glPopMatrix();		
}
