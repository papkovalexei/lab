#include "Machine.h"

Machine::Machine(RubikCube& cube, int step) : _cube(cube)
{
	_whichAction = 0;
	_step = step;
}

/*
	[0][1][2] - white/pink
	[1][2][2] - white/green
	[1][0][2] - white/blue
	[2][1][2] - white/orange
	[2][1][0] - orange/yellow
	[2][0][1] - orange/blue
	[2][2][1] - orange/green
	[1][0][0] - yellow/blue
	[0][1][0] - yellow/pink
	[1][2][0] - yellow/green
	[0][2][1] - pink/green
	[0][0][1] - pink/blue
	*/

bool getArgument(int* color, int first, int second)
{
	bool first_color, second_color, check = true;

	for (int i = 0; i < 6; i++)
	{
		if (color[i] == first)
			first_color = true;
		else if (color[i] == second)
			second_color = true;
		else if (color[i] != 0)
			return false;
	}
	return true;
}

bool getArgument(int* color, int first, int second, int third)
{
	bool first_color, second_color, third_color, check = true;

	for (int i = 0; i < 6; i++)
	{
		if (color[i] == first)
			first_color = true;
		else if (color[i] == second)
			second_color = true;
		else if (color[i] == third)
			third_color = true;
		else if (color[i] != 0)
			return false;
	}
	return true;
}

std::vector<int> getPinkYellow(RubikCube cube1)
{
	std::vector<int> answer;

	if (getArgument(cube1._details[0][1][2].getColorFragment(), 0xFFFF00, 0xFF38CA))
	{
		answer.push_back(4);
		answer.push_back(4);
	}
	else if (getArgument(cube1._details[1][2][2].getColorFragment(), 0xFFFF00, 0xFF38CA))
	{
		answer.push_back(1);
		answer.push_back(4);
		answer.push_back(4);
	}
	else if (getArgument(cube1._details[1][0][2].getColorFragment(), 0xFFFF00, 0xFF38CA))
	{
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(4);
		answer.push_back(4);
	}
	else if (getArgument(cube1._details[2][1][2].getColorFragment(), 0xFFFF00, 0xFF38CA))
	{
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(0);
		answer.push_back(0);
	}
	else if (getArgument(cube1._details[2][1][0].getColorFragment(), 0xFFFF00, 0xFF38CA))
	{
		answer.push_back(0);
		answer.push_back(0);
	}
	else if (getArgument(cube1._details[2][0][1].getColorFragment(), 0xFFFF00, 0xFF38CA))
	{
		answer.push_back(5);
		answer.push_back(0);
		answer.push_back(0);
	}
	else if (getArgument(cube1._details[2][2][1].getColorFragment(), 0xFFFF00, 0xFF38CA))
	{
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(0);
		answer.push_back(0);
	}
	else if (getArgument(cube1._details[1][0][0].getColorFragment(), 0xFFFF00, 0xFF38CA))
	{
		answer.push_back(0);
		answer.push_back(0);
		answer.push_back(0);
	}
	else if (getArgument(cube1._details[0][1][0].getColorFragment(), 0xFFFF00, 0xFF38CA))
	{
		if (cube1._details[0][1][0].getColorFragment()[1] != 0xFFFF00 && cube1._details[0][1][0].getColorFragment()[4] != 0xFF38CA)
		{
			//FURU
			answer.push_back(4);
			answer.push_back(0);
			answer.push_back(0);
			answer.push_back(0);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(0);
		}
	}
	else if (getArgument(cube1._details[1][2][0].getColorFragment(), 0xFFFF00, 0xFF38CA))
	{
		answer.push_back(0);
	}
	else if (getArgument(cube1._details[0][2][1].getColorFragment(), 0xFFFF00, 0xFF38CA))
	{
		answer.push_back(4);
		answer.push_back(4);
		answer.push_back(4);
	}
	else if (getArgument(cube1._details[0][0][1].getColorFragment(), 0xFFFF00, 0xFF38CA))
	{
		answer.push_back(4);
	}

	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i] == 2 || answer[i] == 3)
			cube1.rotationData(answer[i], 1);
		else
			cube1.rotationData(answer[i], -1);
	}

	if (cube1._details[0][1][0].getColorFragment()[1] != 0xFFFF00 && cube1._details[0][1][0].getColorFragment()[4] != 0xFF38CA)
	{
		//FURU
		answer.push_back(4);
		answer.push_back(0);
		answer.push_back(0);
		answer.push_back(0);
		answer.push_back(3);
		answer.push_back(3);
		answer.push_back(3);
		answer.push_back(0);
	}

	return answer;
}

std::vector<int> Machine::getAction()
{
	return getPinkYellow(_cube);
}