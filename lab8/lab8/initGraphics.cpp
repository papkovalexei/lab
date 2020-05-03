#include <time.h>
#include <stdlib.h>
#include <iostream>

#include "RubikCube.h"
#include "Machine.h"
#include "Color.h"


#define SIZE 100
int TIME = 4;

const int width = 600;
const int height = 600;
const int depth = 300;

int _step = 0;

float xrot = 0;
float yrot = 0;
float xdiff = 0;
float ydiff = 0;

bool mouseDown = false;

int timerOn = 0;
int automat = 0;

unsigned int color_brik[9] = { WHITE, YELLOW, BLUE, GREEN, PINK, ORANGE };

RubikCube cube{ SIZE, color_brik };

void display()
{
	glPushMatrix();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	gluLookAt(
		0.0f, 0.0f, 3.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);

	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);

	glColor3f(1, 0, 0);

	glTranslatef(SIZE / -2.0, SIZE / -2.0, SIZE / -2.0);

	cube.draw();
	glPopMatrix();
	glutSwapBuffers();
}

void init()
{
	glClearColor(0.70, 0.70, 0.70, 0.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glOrtho(-width / 2, width / 2, -height / 2, height / 2, -depth / 2, depth / 2);
	glEnable(GL_DEPTH_TEST);
}

void keyboard(unsigned char key, int, int)
{
	if (cube.getBrinkAnimation() == -1 && key >= '0' && key <= '6')
	{
		cube.rotation(key - '0');
		display();
	}
	else if (key == 'r')
	{
		_step = 0;
		Machine machine(cube);

		std::vector<int> rotate = machine.getAction();

		for (int i = 0; i < rotate.size(); i++)
			cube.pushMove(rotate[i]);
		automat = 1 - automat;
	}
	else if (key == 'c')
	{
		for (int i = 0; i < 6; i++)
		{
			std::cout << cube._details[2][2][0].getColorFragment()[i] << std::endl;
		}
	}
}

void timer(int = 0)
{
	glutTimerFunc(TIME, timer, 0);
	if (timerOn)
	{
		if (cube.getBrinkAnimation() == -1)
			keyboard(rand() % 6 + '0', 0, 0);
		else
			cube.rotation(cube.getBrinkAnimation());
	}
	else
	{
		if (cube.getBrinkAnimation() != -1)
			cube.rotation(cube.getBrinkAnimation());
	}

	if (automat)
	{
		if (cube.getBrinkAnimation() == -1)
		{
			cube.rotation();
		}
		else if (cube.emptyQueue())
			automat = 1 - automat;
	}

	display();
}

void mouseMotion(int x, int y)
{
	if (mouseDown)
	{
		yrot = x - xdiff;
		xrot = y + ydiff;

		glutPostRedisplay();
	}
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = true;

		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else
		mouseDown = false;

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		timerOn = 1 - timerOn;
		
}

void initCube(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow("lab8");
	init();
	glutDisplayFunc(display);
	glutTimerFunc(TIME, timer, 10);
	glutKeyboardFunc(keyboard);
	glutMotionFunc(mouseMotion);
	glutMouseFunc(mouse);
}