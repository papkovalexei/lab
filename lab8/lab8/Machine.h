#pragma once
#include <iostream>
#include <vector>

#include "RubikCube.h"
#include "Color.h"

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
	Machine(RubikCube cube);
	std::vector<int> getAction();
private:
	void cross_step_1(std::vector<int>& answer);
	void cross_step_2(std::vector<int>& answer);
	void cross_step_3(std::vector<int>& answer);
	void cross_step_4(std::vector<int>& answer);

	void layer_1_step_1(std::vector<int>& answer);
	void layer_1_step_2(std::vector<int>& answer);
	void layer_1_step_3(std::vector<int>& answer);
	void layer_1_step_4(std::vector<int>& answer);

	RubikCube _cube;
};

