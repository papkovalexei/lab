#include "FragmentCube.h"

FragmentCube::FragmentCube(float size) : _size(size) {}

int* FragmentCube::getColorFragment()
{
	return _color;
}

unsigned char* FragmentCube::getColor(int i)
{
	_color_byte[0] = _color[i] >> 16;
	_color_byte[1] = _color[i] >> 8;
	_color_byte[2] = _color[i];

	return _color_byte;
}

void FragmentCube::setColorFragment(unsigned int* color_position)
{
	for (int i = 0; i < 6; i++)
		_color[i] = color_position[i];
}

void FragmentCube::setColor(int i, unsigned int color)
{
	_color[i] = color;
}

void FragmentCube::setSize(float size)
{
	_size = size;
}

void FragmentCube::rotateX()
{
	unsigned int tmp = _color[0];
	_color[0] = _color[4];
	_color[4] = _color[1];
	_color[1] = _color[5];
	_color[5] = tmp;
}

void FragmentCube::rotateY()
{
	unsigned int tmp = _color[2];
	_color[2] = _color[1];
	_color[1] = _color[3];
	_color[3] = _color[0];
	_color[0] = tmp;
}

void FragmentCube::rotateZ()
{
	unsigned int tmp = _color[5];
	_color[5] = _color[3];
	_color[3] = _color[4];
	_color[4] = _color[2];
	_color[2] = tmp;
}

void FragmentCube::drawCube()
{
	glPushMatrix();
	glBegin(GL_QUADS);

	glColor3ubv(getColor(0));
	glVertex3f(_size, _size, _size);
	glVertex3f(0, _size, _size);
	glVertex3f(0, 0, _size);
	glVertex3f(_size, 0, _size);

	glColor3ubv(getColor(1));
	glVertex3f(_size, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, _size, 0);
	glVertex3f(_size, _size, 0);

	glColor3ubv(getColor(2));
	glVertex3f(_size, 0, _size);
	glVertex3f(0, 0, _size);
	glVertex3f(0, 0, 0);
	glVertex3f(_size, 0, 0);

	glColor3ubv(getColor(3));
	glVertex3f(_size, _size, 0);
	glVertex3f(0, _size, 0);
	glVertex3f(0, _size, _size);
	glVertex3f(_size, _size, _size);

	glColor3ubv(getColor(4));
	glVertex3f(0, _size, _size);
	glVertex3f(0, _size, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, _size);

	glColor3ubv(getColor(5));
	glVertex3f(_size, _size, 0);
	glVertex3f(_size, _size, _size);
	glVertex3f(_size, 0, _size);
	glVertex3f(_size, 0, 0);

	glEnd();
	glPopMatrix();
}

void FragmentCube::draw(float x, float y, float z)
{
	glPushMatrix();
	glTranslatef(x, y, z);
	drawCube();
	glPopMatrix();
}