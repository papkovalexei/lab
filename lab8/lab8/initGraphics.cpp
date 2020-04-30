#include <time.h>
#include <stdlib.h>

#include <gl/glut.h>

#include "RubikCube.h"

#define SIZE 100

const int width = 600;
const int height = 600;
const int depth = 300;

int timerOn = 0;

unsigned int c[9] = { 0xFFFFFF, 0xFFFF00, 0x0000FF, 0x00FF00, 0xFF38CA, 0xFF6F00 };

RubikCube cube{ SIZE, c };

void display()
{
	glPushMatrix();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glTranslatef(SIZE / -2.0, SIZE / -2.0, SIZE / -2.0);
	cube.draw();
	glPopMatrix();
	glutSwapBuffers();
}

void init()
{
	glClearColor(0.70, 0.70, 0.70, 0.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-width / 2, width / 2, -height / 2, height / 2, -depth / 2, depth / 2);
	glEnable(GL_DEPTH_TEST);
}

void mouse(int key, int state, int, int)
{
	if (key == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		timerOn = 1 - timerOn;
}

void keyboard(unsigned char key, int, int)
{
	if (cube.getBrinkAnimation() == -1 && key >= '0' && key <= '6')
	{
		cube.rotation(key - '0', 3);
		display();
	}
}

void timer(int = 0)
{
	glRotatef(0.1, 1, 1, 1);
	glutTimerFunc(1, timer, 0);
	if (timerOn)
	{
		if (cube.getBrinkAnimation() == -1)
			keyboard(rand() % 6 + '0', 0, 0);
		else
			cube.rotation(cube.getBrinkAnimation(), 3);
	}
	else
	{
		if (cube.getBrinkAnimation() != -1)
			cube.rotation(cube.getBrinkAnimation(), 3);
	}
	display();
}

void initCube(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow("lab8");
	init();
	glutDisplayFunc(display);
	glutTimerFunc(100, timer, 10);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}