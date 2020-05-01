#include "Machine.h"

Machine::Machine(RubikCube cube, int step) : _cube(cube)
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

void getPinkYellow(RubikCube& cube1, std::vector<int>& answer)
{
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
	
	std::vector<int> buffer;

	if (cube1._details[0][1][0].getColorFragment()[1] != 0xFFFF00 && cube1._details[0][1][0].getColorFragment()[4] != 0xFF38CA)
	{
		//FURU
		buffer.push_back(4);
		buffer.push_back(0);
		buffer.push_back(0);
		buffer.push_back(0);
		buffer.push_back(3);
		buffer.push_back(3);
		buffer.push_back(3);
		buffer.push_back(0);

		answer.push_back(4);
		answer.push_back(0);
		answer.push_back(0);
		answer.push_back(0);
		answer.push_back(3);
		answer.push_back(3);
		answer.push_back(3);
		answer.push_back(0);
	}

	for (int i = 0; i < buffer.size(); i++)
	{
		if (buffer[i] == 2 || buffer[i] == 3)
			cube1.rotationData(buffer[i], 1);
		else
			cube1.rotationData(buffer[i], -1);
	}
}

void getGreenYellow(RubikCube& cube1, std::vector<int>& returnAnswer)
{
	std::vector<int> answer;

	if (getArgument(cube1._details[0][1][2].getColorFragment(), 0xFFFF00, 0x00FF00))
	{
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(3);
		answer.push_back(3);
	}
	else if (getArgument(cube1._details[1][2][2].getColorFragment(), 0xFFFF00, 0x00FF00))
	{
		answer.push_back(3);
		answer.push_back(3);
	}
	else if (getArgument(cube1._details[1][0][2].getColorFragment(), 0xFFFF00, 0x00FF00))
	{
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(3);
		answer.push_back(3);
	}
	else if (getArgument(cube1._details[2][1][2].getColorFragment(), 0xFFFF00, 0x00FF00))
	{
		answer.push_back(1);
		answer.push_back(3);
		answer.push_back(3);
	}
	else if (getArgument(cube1._details[2][1][0].getColorFragment(), 0xFFFF00, 0x00FF00))
	{
		answer.push_back(5);
		answer.push_back(3);
	}
	else if (getArgument(cube1._details[2][0][1].getColorFragment(), 0xFFFF00, 0x00FF00))
	{
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(3);
	}
	else if (getArgument(cube1._details[2][2][1].getColorFragment(), 0xFFFF00, 0x00FF00))
	{
		answer.push_back(3);
	}
	else if (getArgument(cube1._details[1][0][0].getColorFragment(), 0xFFFF00, 0x00FF00))
	{
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(3);
		answer.push_back(3);
	}
	else if (getArgument(cube1._details[1][2][0].getColorFragment(), 0xFFFF00, 0x00FF00))
	{
		// FURU
		if (cube1._details[1][2][0].getColorFragment()[1] != 0xFFFF00 && cube1._details[1][2][0].getColorFragment()[3] != 0x00FF00)
		{
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(0);
			answer.push_back(0);
			answer.push_back(0);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(0);
		}
	}
	else if (getArgument(cube1._details[0][2][1].getColorFragment(), 0xFFFF00, 0x00FF00))
	{
		answer.push_back(3);
		answer.push_back(3);
		answer.push_back(3);
	}
	else if (getArgument(cube1._details[0][0][1].getColorFragment(), 0xFFFF00, 0x00FF00))
	{
		answer.push_back(2);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(3);
		answer.push_back(3);
	}

	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i] == 2 || answer[i] == 3)
			cube1.rotationData(answer[i], 1);
		else
			cube1.rotationData(answer[i], -1);
		returnAnswer.push_back(answer[i]);
	}

	std::vector<int> buffer;

	if (cube1._details[1][2][0].getColorFragment()[1] != 0xFFFF00 && cube1._details[1][2][0].getColorFragment()[3] != 0x00FF00)
	{
		buffer.push_back(3);
		buffer.push_back(3);
		buffer.push_back(3);
		buffer.push_back(0);
		buffer.push_back(0);
		buffer.push_back(0);
		buffer.push_back(5);
		buffer.push_back(5);
		buffer.push_back(5);
		buffer.push_back(0);

		for (int i = 0; i < buffer.size(); i++)
		{
			returnAnswer.push_back(buffer[i]);

			if (buffer[i] == 2 || buffer[i] == 3)
				cube1.rotationData(buffer[i], 1);
			else
				cube1.rotationData(buffer[i], -1);
		}
	}
}

void getOrangeYellow(RubikCube& cube1, std::vector<int>& returnAnswer)
{
	std::vector<int> answer;

	if (getArgument(cube1._details[0][1][2].getColorFragment(), 0xFFFF00, 0xFF6F00))
	{
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(5);
		answer.push_back(5);
	}
	else if (getArgument(cube1._details[1][2][2].getColorFragment(), 0xFFFF00, 0xFF6F00))
	{
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(5);
		answer.push_back(5);
	}
	else if (getArgument(cube1._details[1][0][2].getColorFragment(), 0xFFFF00, 0xFF6F00))
	{
		answer.push_back(1);
		answer.push_back(5);
		answer.push_back(5);
	}
	else if (getArgument(cube1._details[2][1][2].getColorFragment(), 0xFFFF00, 0xFF6F00))
	{
		answer.push_back(5);
		answer.push_back(5);
	}
	else if (getArgument(cube1._details[2][1][0].getColorFragment(), 0xFFFF00, 0xFF6F00))
	{
		if (cube1._details[2][1][0].getColorFragment()[1] != 0xFFFF00 && cube1._details[2][1][0].getColorFragment()[5] != 0xFF6F00)
		{
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(0);
			answer.push_back(0);
			answer.push_back(0);
			answer.push_back(2);
			answer.push_back(0);
		}
	}
	else if (getArgument(cube1._details[2][0][1].getColorFragment(), 0xFFFF00, 0xFF6F00))
	{
		answer.push_back(5);
	}
	else if (getArgument(cube1._details[2][2][1].getColorFragment(), 0xFFFF00, 0xFF6F00))
	{
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(5);
	}
	else if (getArgument(cube1._details[1][0][0].getColorFragment(), 0xFFFF00, 0xFF6F00))
	{
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(5);
	}
	else if (getArgument(cube1._details[0][2][1].getColorFragment(), 0xFFFF00, 0xFF6F00))
	{
		answer.push_back(4);
		answer.push_back(1);
		answer.push_back(4);
		answer.push_back(4);
		answer.push_back(4);
		answer.push_back(1);
		answer.push_back(5);
		answer.push_back(5);
	}
	else if (getArgument(cube1._details[0][0][1].getColorFragment(), 0xFFFF00, 0xFF6F00))
	{
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(5);
	}

	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i] == 2 || answer[i] == 3)
			cube1.rotationData(answer[i], 1);
		else
			cube1.rotationData(answer[i], -1);
		returnAnswer.push_back(answer[i]);
	}

	std::vector<int> buffer;

	if (cube1._details[2][1][0].getColorFragment()[1] != 0xFFFF00 && cube1._details[2][1][0].getColorFragment()[5] != 0xFF6F00)
	{
		buffer.push_back(5);
		buffer.push_back(5);
		buffer.push_back(5);
		buffer.push_back(0);
		buffer.push_back(0);
		buffer.push_back(0);
		buffer.push_back(2);
		buffer.push_back(0);

		for (int i = 0; i < buffer.size(); i++)
		{
			returnAnswer.push_back(buffer[i]);

			if (buffer[i] == 2 || buffer[i] == 3)
				cube1.rotationData(buffer[i], 1);
			else
				cube1.rotationData(buffer[i], -1);
		}
	}
}

void getBlueYellow(RubikCube& cube1, std::vector<int>& returnAnswer)
{
	std::vector<int> answer;

	if (getArgument(cube1._details[0][1][2].getColorFragment(), 0xFFFF00, 0x0000FF))
	{
		answer.push_back(1);
		answer.push_back(2);
		answer.push_back(2);
	}
	else if (getArgument(cube1._details[1][2][2].getColorFragment(), 0xFFFF00, 0x0000FF))
	{
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(2);
		answer.push_back(2);
	}
	else if (getArgument(cube1._details[1][0][2].getColorFragment(), 0xFFFF00, 0x0000FF))
	{
		answer.push_back(2);
		answer.push_back(2);
	}
	else if (getArgument(cube1._details[2][1][2].getColorFragment(), 0xFFFF00, 0x0000FF))
	{
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(2);
		answer.push_back(2);
	}
	else if (getArgument(cube1._details[2][0][1].getColorFragment(), 0xFFFF00, 0x0000FF))
	{
		answer.push_back(2);
	}
	else if (getArgument(cube1._details[2][2][1].getColorFragment(), 0xFFFF00, 0x0000FF))
	{
		answer.push_back(5);
		answer.push_back(1);
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(2);
		answer.push_back(2);
	}
	else if (getArgument(cube1._details[1][0][0].getColorFragment(), 0xFFFF00, 0x0000FF))
	{
		// FURU
		if (cube1._details[1][0][0].getColorFragment()[1] != 0xFFFF00 && cube1._details[1][0][0].getColorFragment()[2] != 0x0000FF)
		{
			answer.push_back(2);
			answer.push_back(0);
			answer.push_back(0);
			answer.push_back(0);
			answer.push_back(4);
			answer.push_back(0);
		}
	}
	else if (getArgument(cube1._details[0][2][1].getColorFragment(), 0xFFFF00, 0x0000FF))
	{
		answer.push_back(4);
		answer.push_back(1);
		answer.push_back(4);
		answer.push_back(4);
		answer.push_back(4);
		answer.push_back(2);
		answer.push_back(2);
	}
	else if (getArgument(cube1._details[0][0][1].getColorFragment(), 0xFFFF00, 0x0000FF))
	{
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(2);
	}

	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i] == 2 || answer[i] == 3)
			cube1.rotationData(answer[i], 1);
		else
			cube1.rotationData(answer[i], -1);
		returnAnswer.push_back(answer[i]);
	}

	std::vector<int> buffer;

	if (cube1._details[1][0][0].getColorFragment()[1] != 0xFFFF00 && cube1._details[1][0][0].getColorFragment()[2] != 0x0000FF)
	{
		buffer.push_back(2);
		buffer.push_back(0);
		buffer.push_back(0);
		buffer.push_back(0);
		buffer.push_back(4);
		buffer.push_back(0);

		for (int i = 0; i < buffer.size(); i++)
		{
			returnAnswer.push_back(buffer[i]);

			if (buffer[i] == 2 || buffer[i] == 3)
				cube1.rotationData(buffer[i], 1);
			else
				cube1.rotationData(buffer[i], -1);
		}
	}
}


std::vector<int> Machine::getAction()
{
	std::vector<int> answer;

	getPinkYellow(_cube, answer);
	getGreenYellow(_cube, answer);
	getOrangeYellow(_cube, answer);
	getBlueYellow(_cube, answer);

	return answer;
}