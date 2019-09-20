#include "robo.h"

void Robo::DesenhaRect(GLint height, GLint width, GLfloat R, GLfloat G, GLfloat B) {
    glClear(GL_COLOR_BUFFER_BIT);

    /* Desenhar um polígono branco (retângulo) */
    glColor3f(R, G, B);
    glBegin(GL_POLYGON);
        glVertex3f(500/2 - width/2, 500/2 + height/2, 0.0);
        glVertex3f(500/2 - width/2, 500/2 - height/2, 0.0);
        glVertex3f(500/2 + width/2, 500/2 - height/2, 0.0);
        glVertex3f(500/2 + width/2, 500/2 + height/2, 0.0);
    glEnd();

    /* Não esperar */
    glFlush();
}

void Robo::DesenhaRobo( GLfloat x, GLfloat y, GLfloat thetaWheel, GLfloat theta1, GLfloat theta2, GLfloat theta3) {
    DesenhaRect(baseHeight, baseWidth, 1, 0, 0);
}