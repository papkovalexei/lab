#pragma once
#include <queue>

#include "FragmentCube.h"

class RubikCube
{
public:
	RubikCube(float size, unsigned int* color);

	void draw();
	void rotation(int brink, float angle);
	void rotation();

	void pushMove(int brink);

	int getBrinkAnimation();
	bool emptyQueue();

	FragmentCube _details[3][3][3];

	void rotationData(int brink, int vec);
private:

	float _size;
	unsigned int _color[6];
	float _brink_rotate[6];
	short _brink_animation;
	std::queue<int> _queueMove;

	FragmentCube tmp[4][4];
};

