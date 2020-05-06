#pragma once
#include <queue>

#include "FragmentCube.h"

class RubikCube
{
public:
	RubikCube();
	
	void init(float size, unsigned int* color, unsigned int* position_color);
	void init(float size, unsigned int* color);

	void draw();
	void rotation(int brink);
	void rotation();

	void pushMove(int brink);

	int getBrinkAnimation();

	bool emptyQueue();

	int* getColorDetails(int i, int j, int k);


	void rotationData(int brink, int vec);

	void operator=(const RubikCube copy_cube);
private:
	FragmentCube _details[3][3][3];
	float _size;
	unsigned int _color[6];
	float _brink_rotate[6];
	short _brink_animation;
	const int _ANGLE_ROTATE = 30;
	std::queue<int> _queueMove;

	FragmentCube tmp[4][4];
};

