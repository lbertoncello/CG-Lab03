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
	glTranslatef(x, y, 0.0);
	DesenhaRect(baseHeight, baseWidth, 1.0, 0.0, 0.0);

}

