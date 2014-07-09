#include <iostream>
#include <cmath>
#include <GL/glut.h>
using namespace std;

float turningAngle = 180;
float turningSpeed = 10;

void display(void) 
{ 
	float lpos[4]={0., 10., 10., 1.0};  //light's position

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(-5, 5, 8, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);  //Camera position and orientation

	glLightfv(GL_LIGHT0,GL_POSITION, lpos);   //Set light position

	glEnable(GL_LIGHTING);			//Enable lighting for the teapot
	glColor3f(0.0, 1.0, 1.0);

	for (int x = -1; x <= 1; x++) {
		for (int y = -1; y <= 1; y++) {
			for (int z = -1; z <= 1; z++) {
				if (!(x || y || z)) continue; // Skip middle
				glPushMatrix();
					glColor3f((x+1.0)/3.0,(y+1.0)/3.0,(z+1.0)/3.0);
					if (z == 1)
						glRotatef(turningAngle, 0, 0, 1);
					glTranslated(x, y, z);
					glutSolidCube(1);
				glPopMatrix();
			}
		}
	}
						
	glFlush(); 
} 

void turningTimer(int data)
{
	if (turningAngle > turningSpeed*2) {
		turningAngle -= turningSpeed;
	} else if (turningAngle < -turningSpeed*2) {
		turningAngle += turningSpeed;
	} else if (fabs(turningAngle) > turningSpeed / 8) {
		turningAngle *= 0.6;
	} else {
		turningAngle = 0;
	}

	glutPostRedisplay();
	glutTimerFunc(25, turningTimer, 0);
}

void special(int key, int x, int y)
{
	if (key == GLUT_KEY_RIGHT)
		turningAngle += 90;
	if (key == GLUT_KEY_LEFT)
		turningAngle -= 90;
	
	glutPostRedisplay();
}

void initialize(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glEnable(GL_LIGHTING);		//Enable OpenGL states
	glEnable(GL_LIGHT0);
 	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 2.0, 200.0);   //Camera Frustum
}

int main(int argc, char **argv) 
{ 
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);  
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Teapot");
	initialize();
	glutDisplayFunc(display);
	glutTimerFunc(25, turningTimer, 0);
	glutSpecialFunc(special);
	glutMainLoop();
	return 0; 
}

