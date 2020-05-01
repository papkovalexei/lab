#include <time.h>
#include <stdlib.h>
#include <iostream>

#include "RubikCube.h"
#include "Machine.h"


#define SIZE 100
#define TIME 10

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

unsigned int color_brik[9] = { 0xFFFFFF, 0xFFFF00, 0x0000FF, 0x00FF00, 0xFF38CA, 0xFF6F00 };

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
		cube.rotation(key - '0', 3);
		display();
	}
	else if (key == 'c')
	{
		for (int i = 0; i < 6; i++)
			std::cout << cube._details[2][1][0].getColorFragment()[i] << std::endl;
		std::cout << "_____________\n";
	}
	else if (key == 'r')
	{
		automat = 1 - automat;
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
			cube.rotation(cube.getBrinkAnimation(), 3);
	}
	else
	{
		if (cube.getBrinkAnimation() != -1)
			cube.rotation(cube.getBrinkAnimation(), 3);
	}

	if (automat)
	{
		if (cube.emptyQueue())
		{
			Machine machine(cube, _step);

			std::cout << _step << std::endl;

			std::vector<int> rotate = machine.getAction();

			if (rotate.size() == 0)
			{
				//std::cout << "Ste++\n";
				_step++;
			}

			for (int i = 0; i < rotate.size(); i++)
			{
				//std::cout << rotate[i] << std::endl;
				cube.pushMove(rotate[i]);
			}

			cube.rotation();
		}
		else if (cube.getBrinkAnimation() == -1)
			cube.rotation();
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