#pragma once

#include <gl/glut.h>

class FragmentCube
{
public:
	FragmentCube(float size);
	FragmentCube() {}

	void draw(float x, float y, float z);

	int* getColorFragment();
	void setColorFragment(unsigned int* color_position);

	void setColor(int i, unsigned int color);
	void setSize(float size);

	void rotateX();
	void rotateY();
	void rotateZ();
private:
	unsigned char* getColor(int i);
	void drawCube();

	float _size;
	int _color[6];
	unsigned char _color_byte[4];
};

