#pragma once
#include "FragmentCube.h"

class RubikCube
{
public:
	RubikCube(float size, unsigned int* color);

	void draw();
	void rotation(int brink, float angle);

	int getBrinkAnimation();
private:
	void rotationData(int brink, int vec);

	float _size;
	unsigned int _color[6];
	float _brink_rotate[6];
	short _brink_animation;

	FragmentCube _details[3][3][3];
	FragmentCube tmp[4][4];
};

