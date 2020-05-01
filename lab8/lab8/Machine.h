#pragma once
#include <iostream>
#include <vector>

#include "RubikCube.h"

#define CROSS_1 0
#define CROSS_2 1
#define CROSS_3 2
#define CROSS_4 3
#define CROSS_ACTION_1 1
#define CROSS_ACTION_2 2
#define CROSS_ACTION_3 3
#define CROSS_ACTION_4 4
class Machine
{
public:
	Machine(RubikCube& cube, int step);
	int _step;
	std::vector<int> getAction();
private:
	std::vector<int> _state;
	int _whichAction;
	RubikCube _cube;
};

