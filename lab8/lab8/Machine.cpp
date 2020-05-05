#include "Machine.h"

Machine::Machine(RubikCube cube) : _cube(cube) {}
 
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

void Machine::cross_step_1(std::vector<int>& answer)
{
	if (getArgument(_cube.getColorDetails(0, 1, 2), YELLOW, PINK))
	{
		answer.push_back(4);
		answer.push_back(4);
	}
	else if (getArgument(_cube.getColorDetails(1, 2, 2), YELLOW, PINK))
	{
		answer.push_back(1);
		answer.push_back(4);
		answer.push_back(4);
	}
	else if (getArgument(_cube.getColorDetails(1, 0, 2), YELLOW, PINK))
	{
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(4);
		answer.push_back(4);
	}
	else if (getArgument(_cube.getColorDetails(2, 1, 2), YELLOW, PINK))
	{
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(0);
		answer.push_back(0);
	}
	else if (getArgument(_cube.getColorDetails(2, 1, 0), YELLOW, PINK))
	{
		answer.push_back(0);
		answer.push_back(0);
	}
	else if (getArgument(_cube.getColorDetails(2, 0, 1), YELLOW, PINK))
	{
		answer.push_back(5);
		answer.push_back(0);
		answer.push_back(0);
	}
	else if (getArgument(_cube.getColorDetails(2, 2, 1), YELLOW, PINK))
	{
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(0);
		answer.push_back(0);
	}
	else if (getArgument(_cube.getColorDetails(1, 0, 0), YELLOW, PINK))
	{
		answer.push_back(0);
		answer.push_back(0);
		answer.push_back(0);
	}
	else if (getArgument(_cube.getColorDetails(0, 1, 0), YELLOW, PINK))
	{
		if (_cube.getColorDetails(0, 1, 0)[1] != YELLOW
			&& _cube.getColorDetails(0, 1, 0)[4] != PINK)
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
	else if (getArgument(_cube.getColorDetails(1, 2, 0), YELLOW, PINK))
	{
		answer.push_back(0);
	}	
	else if (getArgument(_cube.getColorDetails(0, 2, 1), YELLOW, PINK))
	{
		answer.push_back(4);
		answer.push_back(4);
		answer.push_back(4);
	}
	else if (getArgument(_cube.getColorDetails(0, 0, 1), YELLOW, PINK))
	{
		answer.push_back(4);
	}

	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i] == 2 || answer[i] == 3)
			_cube.rotationData(answer[i], 1);
		else
			_cube.rotationData(answer[i], -1);
	}
	
	std::vector<int> buffer;

	if (_cube.getColorDetails(0, 1, 0)[1] != YELLOW 
		&& _cube.getColorDetails(0, 1, 0)[4] != PINK)
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
	}

	for (int i = 0; i < buffer.size(); i++)
	{
		if (buffer[i] == 2 || buffer[i] == 3)
			_cube.rotationData(buffer[i], 1);
		else
			_cube.rotationData(buffer[i], -1);
		answer.push_back(buffer[i]);
	}
}

void Machine::cross_step_2(std::vector<int>& returnAnswer)
{
	std::vector<int> answer;

	if (getArgument(_cube.getColorDetails(0, 1, 2), YELLOW, GREEN))
	{
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(3);
		answer.push_back(3);
	}
	else if (getArgument(_cube.getColorDetails(1, 2, 2), YELLOW, GREEN))
	{
		answer.push_back(3);
		answer.push_back(3);
	}
	else if (getArgument(_cube.getColorDetails(1, 0, 2), YELLOW, GREEN))
	{
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(3);
		answer.push_back(3);
	}
	else if (getArgument(_cube.getColorDetails(2, 1, 2), YELLOW, GREEN))
	{
		answer.push_back(1);
		answer.push_back(3);
		answer.push_back(3);
	}
	else if (getArgument(_cube.getColorDetails(2, 1, 0), 0xFFFF00, GREEN))
	{
		answer.push_back(5);
		answer.push_back(3);
	}
	else if (getArgument(_cube.getColorDetails(2, 0, 1), YELLOW, GREEN))
	{
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(3);
	}
	else if (getArgument(_cube.getColorDetails(2, 2, 1), YELLOW, GREEN))
	{
		answer.push_back(3);
	}
	else if (getArgument(_cube.getColorDetails(1, 0, 0), YELLOW, GREEN))
	{
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(3);
		answer.push_back(3);
	}
	else if (getArgument(_cube.getColorDetails(1, 2, 0), YELLOW, GREEN))
	{
		// FURU
		if (_cube.getColorDetails(1, 2, 0)[1] != YELLOW
			&& _cube.getColorDetails(1, 2, 0)[3] != GREEN)
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
	else if (getArgument(_cube.getColorDetails(0, 2, 1), YELLOW, GREEN))
	{
		answer.push_back(3);
		answer.push_back(3);
		answer.push_back(3);
	}
	else if (getArgument(_cube.getColorDetails(0, 0, 1), YELLOW, GREEN))
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
			_cube.rotationData(answer[i], 1);
		else
			_cube.rotationData(answer[i], -1);
		returnAnswer.push_back(answer[i]);
	}

	answer.clear();	

	if (_cube.getColorDetails(1, 2, 0)[1] != YELLOW 
		&& _cube.getColorDetails(1, 2, 0)[3] != GREEN)
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

		for (int i = 0; i < answer.size(); i++)
		{
			if (answer[i] == 2 || answer[i] == 3)
				_cube.rotationData(answer[i], 1);
			else
				_cube.rotationData(answer[i], -1);
			returnAnswer.push_back(answer[i]);
		}
	}
}

void Machine::cross_step_3(std::vector<int>& returnAnswer)
{
	std::vector<int> answer;
	
	if (getArgument(_cube.getColorDetails(0, 1, 2), YELLOW, ORANGE))
	{
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(5);
		answer.push_back(5);
	}
	else if (getArgument(_cube.getColorDetails(1, 2, 2), YELLOW, ORANGE))
	{
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(5);
		answer.push_back(5);
	}
	else if (getArgument(_cube.getColorDetails(1, 0, 2), YELLOW, ORANGE))
	{
		answer.push_back(1);
		answer.push_back(5);
		answer.push_back(5);
	}
	else if (getArgument(_cube.getColorDetails(2, 1, 2), YELLOW, ORANGE))
	{
		answer.push_back(5);
		answer.push_back(5);
	}
	else if (getArgument(_cube.getColorDetails(2, 1, 0), YELLOW, ORANGE))
	{
		if (_cube.getColorDetails(2, 1, 0)[1] != YELLOW
			&& _cube.getColorDetails(2, 1, 0)[5] != ORANGE)
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
	else if (getArgument(_cube.getColorDetails(2, 0, 1), YELLOW, ORANGE))
	{
		answer.push_back(5);
	}
	else if (getArgument(_cube.getColorDetails(2, 2, 1), YELLOW, ORANGE))
	{
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(5);
	}
	else if (getArgument(_cube.getColorDetails(1, 0, 0), YELLOW, ORANGE))
	{
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(5);
	}
	else if (getArgument(_cube.getColorDetails(0, 2, 1), YELLOW, ORANGE))
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
	else if (getArgument(_cube.getColorDetails(0, 0, 1), YELLOW, ORANGE))
	{
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(5);
	}

	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i] == 2 || answer[i] == 3)
			_cube.rotationData(answer[i], 1);
		else
			_cube.rotationData(answer[i], -1);
		returnAnswer.push_back(answer[i]);
	}

	std::vector<int> buffer;

	if (_cube.getColorDetails(2, 1, 0)[1] != YELLOW
		&& _cube.getColorDetails(2, 1, 0)[5] != ORANGE)
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
				_cube.rotationData(buffer[i], 1);
			else
				_cube.rotationData(buffer[i], -1);
		}
	}
}

void Machine::cross_step_4(std::vector<int>& returnAnswer)
{
	std::vector<int> answer;

	if (getArgument(_cube.getColorDetails(0, 1, 2), YELLOW, BLUE))
	{
		answer.push_back(1);
		answer.push_back(2);
		answer.push_back(2);
	}
	else if (getArgument(_cube.getColorDetails(1, 2, 2), YELLOW, BLUE))
	{
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(2);
		answer.push_back(2);
	}
	else if (getArgument(_cube.getColorDetails(1, 0, 2), YELLOW, BLUE))
	{
		answer.push_back(2);
		answer.push_back(2);
	}
	else if (getArgument(_cube.getColorDetails(2, 1, 2), YELLOW, BLUE))
	{
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(2);
		answer.push_back(2);
	}
	else if (getArgument(_cube.getColorDetails(2, 0, 1), YELLOW, BLUE))
	{
		answer.push_back(2);
	}
	else if (getArgument(_cube.getColorDetails(2, 2, 1), YELLOW, BLUE))
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
	else if (getArgument(_cube.getColorDetails(1, 0, 0), YELLOW, BLUE))
	{
		// FURU
		if (_cube.getColorDetails(1, 0, 0)[1] != YELLOW 
			&& _cube.getColorDetails(1, 0, 0)[2] != BLUE)
		{
			answer.push_back(2);
			answer.push_back(0);
			answer.push_back(0);
			answer.push_back(0);
			answer.push_back(4);
			answer.push_back(0);
		}
	}
	else if (getArgument(_cube.getColorDetails(0, 2, 1), YELLOW, BLUE))
	{
		answer.push_back(4);
		answer.push_back(1);
		answer.push_back(4);
		answer.push_back(4);
		answer.push_back(4);
		answer.push_back(2);
		answer.push_back(2);
	}
	else if (getArgument(_cube.getColorDetails(0, 0, 1), YELLOW, BLUE))
	{
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(2);
	}

	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i] == 2 || answer[i] == 3)
			_cube.rotationData(answer[i], 1);
		else
			_cube.rotationData(answer[i], -1);
		returnAnswer.push_back(answer[i]);
	}

	std::vector<int> buffer;

	if (_cube.getColorDetails(1, 0, 0)[1] != YELLOW 
		&& _cube.getColorDetails(1, 0, 0)[2] != BLUE)
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
				_cube.rotationData(buffer[i], 1);
			else
				_cube.rotationData(buffer[i], -1);
		}
	}
}

void Machine::layer_1_step_1(std::vector<int>& returnAnswer)
{
	std::vector<int> answer;

	if (getArgument(_cube.getColorDetails(0, 0, 2), YELLOW, PINK, GREEN))
	{
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(3);
		answer.push_back(1);
		answer.push_back(3);
		answer.push_back(3);
		answer.push_back(3);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
	}
	else if (getArgument(_cube.getColorDetails(2, 0, 2), YELLOW, PINK, GREEN))
	{
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(3);
		answer.push_back(1);
		answer.push_back(3);
		answer.push_back(3);
		answer.push_back(3);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
	}
	else if (getArgument(_cube.getColorDetails(0, 2, 2), YELLOW, PINK, GREEN))
	{
		answer.push_back(3);
		answer.push_back(1);
		answer.push_back(3);
		answer.push_back(3);
		answer.push_back(3);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
	}
	else if (getArgument(_cube.getColorDetails(2, 2, 2), YELLOW, PINK, GREEN))
	{
		answer.push_back(1);
		answer.push_back(3);
		answer.push_back(1);
		answer.push_back(3);
		answer.push_back(3);
		answer.push_back(3);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
	}
	else if (getArgument(_cube.getColorDetails(0, 2, 0), YELLOW, PINK, GREEN))
	{
		// if
		if (_cube.getColorDetails(0, 2, 0)[1] != YELLOW && _cube.getColorDetails(0, 2, 0)[3] != GREEN && _cube.getColorDetails(0, 2, 0)[5] != PINK)
		{
			answer.push_back(3);
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
		}
	}
	else if (getArgument(_cube.getColorDetails(0, 0, 0), YELLOW, PINK, GREEN))
	{
		answer.push_back(4);
		answer.push_back(4);
		answer.push_back(4);
		answer.push_back(1);
		answer.push_back(4);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(3);
		answer.push_back(1);
		answer.push_back(3);
		answer.push_back(3);
		answer.push_back(3);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
	}
	else if (getArgument(_cube.getColorDetails(2, 2, 0), YELLOW, PINK, GREEN))
	{
		answer.push_back(5);
		answer.push_back(1);
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(3);
		answer.push_back(1);
		answer.push_back(3);
		answer.push_back(3);
		answer.push_back(3);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
	}
	else if (getArgument(_cube.getColorDetails(2, 0, 0), YELLOW, PINK, GREEN))
	{
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(1);
		answer.push_back(2);
		answer.push_back(1);
		answer.push_back(3);
		answer.push_back(1);
		answer.push_back(3);
		answer.push_back(3);
		answer.push_back(3);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
	}

	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i] == 2 || answer[i] == 3)
			_cube.rotationData(answer[i], 1);
		else
			_cube.rotationData(answer[i], -1);
		returnAnswer.push_back(answer[i]);
	}

	while (_cube.getColorDetails(0, 2, 0)[1] != YELLOW && _cube.getColorDetails(0, 2, 0)[3] != GREEN && _cube.getColorDetails(0, 2, 0)[5] != PINK)
	{
		answer.clear();

		answer.push_back(3);
		answer.push_back(1);
		answer.push_back(3);
		answer.push_back(3);
		answer.push_back(3);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(3);
		answer.push_back(1);
		answer.push_back(3);
		answer.push_back(3);
		answer.push_back(3);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);

		for (int i = 0; i < answer.size(); i++)
		{
			if (answer[i] == 2 || answer[i] == 3)
				_cube.rotationData(answer[i], 1);
			else
				_cube.rotationData(answer[i], -1);
			returnAnswer.push_back(answer[i]);
		}
	}
}

void Machine::layer_1_step_2(std::vector<int>& returnAnswer)
{
	std::vector<int> answer;

	if (getArgument(_cube.getColorDetails(0, 0, 2), YELLOW, PINK, BLUE))
	{
		answer.push_back(4);
		answer.push_back(4);
		answer.push_back(4);
		answer.push_back(1);
		answer.push_back(4);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
	}
	else if (getArgument(_cube.getColorDetails(2, 0, 2), YELLOW, PINK, BLUE))
	{
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(4);
		answer.push_back(4);
		answer.push_back(4);
		answer.push_back(1);
		answer.push_back(4);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
	}
	else if (getArgument(_cube.getColorDetails(0, 2, 2), YELLOW, PINK, BLUE))
	{
		answer.push_back(1);
		answer.push_back(4);
		answer.push_back(4);
		answer.push_back(4);
		answer.push_back(1);
		answer.push_back(4);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
	}
	else if (getArgument(_cube.getColorDetails(2, 2, 2), YELLOW, PINK, BLUE))
	{
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(4);
		answer.push_back(4);
		answer.push_back(4);
		answer.push_back(1);
		answer.push_back(4);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
	}
	else if (getArgument(_cube.getColorDetails(0, 0, 0), YELLOW, PINK, BLUE))
	{
		if (_cube.getColorDetails(0, 0, 0)[1] != YELLOW && _cube.getColorDetails(0, 0, 0)[2] != BLUE && _cube.getColorDetails(0, 0, 0)[4] != PINK)
		{
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
		}
	}
	else if (getArgument(_cube.getColorDetails(2, 2, 0), YELLOW, PINK, BLUE))
	{
		answer.push_back(5);
		answer.push_back(1);
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(1);
		answer.push_back(4);
		answer.push_back(4);
		answer.push_back(4);
		answer.push_back(1);
		answer.push_back(4);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
	}
	else if (getArgument(_cube.getColorDetails(2, 0, 0), YELLOW, PINK, BLUE))
	{
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(1);
		answer.push_back(2);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(4);
		answer.push_back(4);
		answer.push_back(4);
		answer.push_back(1);
		answer.push_back(4);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
	}

	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i] == 2 || answer[i] == 3)
			_cube.rotationData(answer[i], 1);
		else
			_cube.rotationData(answer[i], -1);
		returnAnswer.push_back(answer[i]);
	}

	while (_cube.getColorDetails(0, 0, 0)[1] != YELLOW && _cube.getColorDetails(0, 0, 0)[2] != BLUE && _cube.getColorDetails(0, 0, 0)[4] != PINK)
	{
		answer.clear();

		answer.push_back(4);
		answer.push_back(4);
		answer.push_back(4);
		answer.push_back(1);
		answer.push_back(4);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(4);
		answer.push_back(4);
		answer.push_back(4);
		answer.push_back(1);
		answer.push_back(4);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);

		for (int i = 0; i < answer.size(); i++)
		{
			if (answer[i] == 2 || answer[i] == 3)
				_cube.rotationData(answer[i], 1);
			else
				_cube.rotationData(answer[i], -1);
			returnAnswer.push_back(answer[i]);
		}
	}
}

void Machine::layer_1_step_3(std::vector<int>& returnAnswer)
{
	std::vector<int> answer;

	if (getArgument(_cube.getColorDetails(0, 0, 2), YELLOW, ORANGE, BLUE))
	{
		answer.push_back(1);
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(1);
		answer.push_back(2);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
	}
	else if (getArgument(_cube.getColorDetails(2, 0, 2), YELLOW, ORANGE, BLUE))
	{
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(1);
		answer.push_back(2);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
	}
	else if (getArgument(_cube.getColorDetails(0, 2, 2), YELLOW, ORANGE, BLUE))
	{
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(1);
		answer.push_back(2);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
	}
	else if (getArgument(_cube.getColorDetails(2, 2, 2), YELLOW, ORANGE, BLUE))
	{
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(1);
		answer.push_back(2);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
	}
	else if (getArgument(_cube.getColorDetails(2, 2, 0), YELLOW, ORANGE, BLUE))
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
		answer.push_back(2);
		answer.push_back(1);
		answer.push_back(2);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
	}
	else if (getArgument(_cube.getColorDetails(2, 0, 0), YELLOW, ORANGE, BLUE))
	{
		if (_cube.getColorDetails(2, 0, 0)[1] != YELLOW && _cube.getColorDetails(2, 0, 0)[2] != BLUE && _cube.getColorDetails(2, 0, 0)[5] != ORANGE)
		{
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
		}
	}


	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i] == 2 || answer[i] == 3)
			_cube.rotationData(answer[i], 1);
		else
			_cube.rotationData(answer[i], -1);
		returnAnswer.push_back(answer[i]);
	}

	while (_cube.getColorDetails(2, 0, 0)[1] != YELLOW && _cube.getColorDetails(2, 0, 0)[2] != BLUE && _cube.getColorDetails(2, 0, 0)[5] != ORANGE)
	{
		answer.clear();

		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(1);
		answer.push_back(2);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(1);
		answer.push_back(2);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);

		for (int i = 0; i < answer.size(); i++)
		{
			if (answer[i] == 2 || answer[i] == 3)
				_cube.rotationData(answer[i], 1);
			else
				_cube.rotationData(answer[i], -1);
			returnAnswer.push_back(answer[i]);
		}
	}
}

void Machine::layer_1_step_4(std::vector<int>& returnAnswer)
{
	std::vector<int> answer;

	if (getArgument(_cube.getColorDetails(0, 0, 2), YELLOW, ORANGE, GREEN))
	{
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(5);
		answer.push_back(1);
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
	}
	else if (getArgument(_cube.getColorDetails(2, 0, 2), YELLOW, ORANGE, GREEN))
	{
		answer.push_back(1);
		answer.push_back(5);
		answer.push_back(1);
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
	}
	else if (getArgument(_cube.getColorDetails(0, 2, 2), YELLOW, ORANGE, GREEN))
	{
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(5);
		answer.push_back(1);
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
	}
	else if (getArgument(_cube.getColorDetails(2, 2, 2), YELLOW, ORANGE, GREEN))
	{
		answer.push_back(5);
		answer.push_back(1);
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
	}
	else if (getArgument(_cube.getColorDetails(2, 2, 0), YELLOW, ORANGE, GREEN))
	{
		if (_cube.getColorDetails(2, 2, 0)[1] != YELLOW && _cube.getColorDetails(2, 2, 0)[3] != GREEN && _cube.getColorDetails(2, 2, 0)[5] != ORANGE)
		{
			answer.push_back(5);
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
		}
	}

	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i] == 2 || answer[i] == 3)
			_cube.rotationData(answer[i], 1);
		else
			_cube.rotationData(answer[i], -1);
		returnAnswer.push_back(answer[i]);
	}

	while (_cube.getColorDetails(2, 2, 0)[1] != YELLOW && _cube.getColorDetails(2, 2, 0)[3] != GREEN && _cube.getColorDetails(2, 2, 0)[5] != ORANGE)
	{
		answer.clear();

		answer.push_back(5);
		answer.push_back(1);
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(5);
		answer.push_back(1);
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);

		for (int i = 0; i < answer.size(); i++)
		{
			if (answer[i] == 2 || answer[i] == 3)
				_cube.rotationData(answer[i], 1);
			else
				_cube.rotationData(answer[i], -1);
			returnAnswer.push_back(answer[i]);
		}
	}
}

void Machine::layer_2_step_1(std::vector<int>& returnAnswer)
{
	std::vector<int> answer;

	if (getArgument(_cube.getColorDetails(0, 1, 2), GREEN, PINK))
	{
		if (_cube.getColorDetails(0, 1, 2)[0] == GREEN && _cube.getColorDetails(0, 1, 2)[4] == PINK)
		{
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(4);
		}
		else if (_cube.getColorDetails(0, 1, 2)[0] == PINK && _cube.getColorDetails(0, 1, 2)[4] == GREEN)
		{
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			//
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(3);
		}
	}
	else if (getArgument(_cube.getColorDetails(1, 2, 2), GREEN, PINK))
	{
		if (_cube.getColorDetails(1, 2, 2)[0] == PINK && _cube.getColorDetails(1, 2, 2)[3] == GREEN)
		{
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(3);
		}
		else if (_cube.getColorDetails(1, 2, 2)[0] == GREEN && _cube.getColorDetails(1, 2, 2)[3] == PINK)
		{
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(4);
		}
	}
	else if (getArgument(_cube.getColorDetails(1, 0, 2), GREEN, PINK))
	{
		if (_cube.getColorDetails(1, 0, 2)[0] == GREEN && _cube.getColorDetails(1, 0, 2)[2] == PINK)
		{
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			//
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(4);
		}
		else if (_cube.getColorDetails(1, 0, 2)[0] == PINK && _cube.getColorDetails(1, 0, 2)[2] == GREEN)
		{
			answer.push_back(1);
			answer.push_back(1);
			//
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(3);
		}
	}
	else if (getArgument(_cube.getColorDetails(2, 1, 2), GREEN, PINK))
	{
		if (_cube.getColorDetails(2, 1, 2)[0] == PINK && _cube.getColorDetails(2, 1, 2)[5] == GREEN)
		{
			answer.push_back(1);
			//
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(3);
		}
		else if (_cube.getColorDetails(2, 1, 2)[0] == GREEN && _cube.getColorDetails(2, 1, 2)[5] == PINK)
		{
			answer.push_back(1);
			answer.push_back(1);
			//
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(4);
		}
	}
	else if (getArgument(_cube.getColorDetails(2, 0, 1), GREEN, PINK))
	{
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(1);
		answer.push_back(5);
		answer.push_back(1);
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(2);
	}
	else if (getArgument(_cube.getColorDetails(2, 2, 1), GREEN, PINK))
	{
		answer.push_back(1);
		answer.push_back(5);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(3);
		answer.push_back(3);
		answer.push_back(3);
		answer.push_back(1);
		answer.push_back(3);
	}
	else if (getArgument(_cube.getColorDetails(0, 2, 1), GREEN, PINK))
	{
		if (_cube.getColorDetails(0, 2, 1)[3] != GREEN && _cube.getColorDetails(0, 2, 1)[4] != PINK)
		{
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(4);
		}
	}
	else if (getArgument(_cube.getColorDetails(0, 0, 1), GREEN, PINK))
	{
		answer.push_back(1);
		answer.push_back(4);
		answer.push_back(4);
		answer.push_back(4);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(4);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(2);
		answer.push_back(1);
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(2);
	}

	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i] == 2 || answer[i] == 3)
			_cube.rotationData(answer[i], 1);
		else
			_cube.rotationData(answer[i], -1);
		returnAnswer.push_back(answer[i]);
	}

	if (_cube.getColorDetails(0, 2, 1)[3] != GREEN && _cube.getColorDetails(0, 2, 1)[4] != PINK)
		layer_2_step_1(returnAnswer);
}

void Machine::layer_2_step_2(std::vector<int>& returnAnswer)
{
	std::vector<int> answer;

	if (getArgument(_cube.getColorDetails(0, 1, 2), GREEN, ORANGE))
	{
		if (_cube.getColorDetails(0, 1, 2)[0] == ORANGE && _cube.getColorDetails(0, 1, 2)[4] == GREEN)
		{
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			//
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(1);
			answer.push_back(3);
		}
		if (_cube.getColorDetails(0, 1, 2)[0] == GREEN && _cube.getColorDetails(0, 1, 2)[4] == ORANGE)
		{
			answer.push_back(1);
			answer.push_back(1);
			//
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(5);
		}
	}
	else if (getArgument(_cube.getColorDetails(1, 2, 2), GREEN, ORANGE))
	{
		if (_cube.getColorDetails(1, 2, 2)[0] == GREEN && _cube.getColorDetails(1, 2, 2)[3] == ORANGE)
		{
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			//
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(5);
		}
		else if (_cube.getColorDetails(1, 2, 2)[0] == ORANGE && _cube.getColorDetails(1, 2, 2)[3] == GREEN)
		{
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(1);
			answer.push_back(3);
		}
	}
	else if (getArgument(_cube.getColorDetails(1, 0, 2), GREEN, ORANGE))
	{
		if (_cube.getColorDetails(1, 0, 2)[0] == GREEN && _cube.getColorDetails(1, 0, 2)[2] == ORANGE)
		{
			answer.push_back(1);
			//
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(5);
		}
		else if (_cube.getColorDetails(1, 0, 2)[0] == ORANGE && _cube.getColorDetails(1, 0, 2)[2] == GREEN)
		{
			answer.push_back(1);
			answer.push_back(1);
			//
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(1);
			answer.push_back(3);
		}
	}
	else if (getArgument(_cube.getColorDetails(2, 1, 2), GREEN, ORANGE))
	{
		if (_cube.getColorDetails(2, 1, 2)[0] == GREEN && _cube.getColorDetails(2, 1, 2)[5] == ORANGE)
		{
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(5);
		}
		else if (_cube.getColorDetails(2, 1, 2)[0] == ORANGE && _cube.getColorDetails(2, 1, 2)[5] == GREEN)
		{
			answer.push_back(1);
			//
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(1);
			answer.push_back(3);
		}
	}
	else if (getArgument(_cube.getColorDetails(2, 0, 1), GREEN, ORANGE))
	{
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(1);
		answer.push_back(5);
		answer.push_back(1);
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(2);
	}
	else if (getArgument(_cube.getColorDetails(2, 2, 1), GREEN, ORANGE))
	{
		if (_cube.getColorDetails(2, 2, 1)[3] != GREEN && _cube.getColorDetails(2, 2, 1)[5] != ORANGE)
		{
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(5);
		}
	}
	else if (getArgument(_cube.getColorDetails(0, 0, 1), GREEN, ORANGE))
	{
		answer.push_back(1);
		answer.push_back(4);
		answer.push_back(4);
		answer.push_back(4);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(4);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(2);
		answer.push_back(1);
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(2);
	}

	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i] == 2 || answer[i] == 3)
			_cube.rotationData(answer[i], 1);
		else
			_cube.rotationData(answer[i], -1);
		returnAnswer.push_back(answer[i]);
	}

	if (_cube.getColorDetails(2, 2, 1)[3] != GREEN && _cube.getColorDetails(2, 2, 1)[5] != ORANGE)
		layer_2_step_2(returnAnswer);
}

void Machine::layer_2_step_3(std::vector<int>& returnAnswer)
{
	std::vector<int> answer;

	if (getArgument(_cube.getColorDetails(0, 1, 2), BLUE, PINK))
	{
		if (_cube.getColorDetails(0, 1, 2)[0] == BLUE && _cube.getColorDetails(0, 1, 2)[4] == PINK)
		{
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(4);
		}
		else if (_cube.getColorDetails(0, 1, 2)[0] == PINK && _cube.getColorDetails(0, 1, 2)[4] == BLUE)
		{
			answer.push_back(1);
			//
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(2);
		}
	}
	else if (getArgument(_cube.getColorDetails(1, 2, 2), BLUE, PINK))
	{
		if (_cube.getColorDetails(1, 2, 2)[0] == BLUE && _cube.getColorDetails(1, 2, 2)[3] == PINK)
		{
			answer.push_back(1);
			//
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(4);
		}
		if (_cube.getColorDetails(1, 2, 2)[0] == PINK && _cube.getColorDetails(1, 2, 2)[3] == BLUE)
		{
			answer.push_back(1);
			answer.push_back(1);
			//
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(2);
		}
	}
	else if (getArgument(_cube.getColorDetails(1, 0, 2), BLUE, PINK))
	{
		if (_cube.getColorDetails(1, 0, 2)[0] == BLUE && _cube.getColorDetails(1, 0, 2)[2] == PINK)
		{
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			//
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(4);
		}
		else if (_cube.getColorDetails(1, 0, 2)[0] == PINK && _cube.getColorDetails(1, 0, 2)[2] == BLUE)
		{
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(2);
		}
	}
	else if (getArgument(_cube.getColorDetails(2, 1, 2), BLUE, PINK))
	{
		if (_cube.getColorDetails(2, 1, 2)[0] == PINK && _cube.getColorDetails(2, 1, 2)[5] == BLUE)
		{
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			//
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(2);
		}
		else if (_cube.getColorDetails(2, 1, 2)[0] == BLUE && _cube.getColorDetails(2, 1, 2)[5] == PINK)
		{
			answer.push_back(1);
			answer.push_back(1);
			//
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(4);
		}
	}
	else if (getArgument(_cube.getColorDetails(2, 0, 1), BLUE, PINK))
	{
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(1);
		answer.push_back(5);
		answer.push_back(1);
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(2);

	}
	else if (getArgument(_cube.getColorDetails(0, 0, 1), BLUE, PINK))
	{
		if (_cube.getColorDetails(0, 0, 1)[2] != BLUE && _cube.getColorDetails(0, 0, 1)[4] != PINK)
		{
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(2);
		}
	}

	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i] == 2 || answer[i] == 3)
			_cube.rotationData(answer[i], 1);
		else
			_cube.rotationData(answer[i], -1);
		returnAnswer.push_back(answer[i]);
	}

	if (_cube.getColorDetails(0, 0, 1)[2] != BLUE && _cube.getColorDetails(0, 0, 1)[4] != PINK)
		layer_2_step_3(returnAnswer);
}

void Machine::layer_2_step_4(std::vector<int>& returnAnswer)
{
	std::vector<int> answer;

	if (getArgument(_cube.getColorDetails(0, 1, 2), BLUE, ORANGE))
	{
		if (_cube.getColorDetails(0, 1, 2)[0] == BLUE && _cube.getColorDetails(0, 1, 2)[4] == ORANGE)
		{
			answer.push_back(1);
			answer.push_back(1);
			//
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(1);
			answer.push_back(5);
		}
		else if (_cube.getColorDetails(0, 1, 2)[0] == ORANGE && _cube.getColorDetails(0, 1, 2)[4] == BLUE)
		{
			answer.push_back(1);
			//
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(2);
		}
	}
	else if (getArgument(_cube.getColorDetails(1, 2, 2), BLUE, ORANGE))
	{
		if (_cube.getColorDetails(1, 2, 2)[0] == BLUE && _cube.getColorDetails(1, 2, 2)[3] == ORANGE)
		{
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			//
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(1);
			answer.push_back(5);
		}
		else if (_cube.getColorDetails(1, 2, 2)[0] == ORANGE && _cube.getColorDetails(1, 2, 2)[3] == BLUE)
		{
			answer.push_back(1);
			answer.push_back(1);
			//
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(2);
		}
	}
	else if (getArgument(_cube.getColorDetails(1, 0, 2), BLUE, ORANGE))
	{
		if (_cube.getColorDetails(1, 0, 2)[0] == BLUE && _cube.getColorDetails(1, 0, 2)[2] == ORANGE)
		{
			answer.push_back(1);
			//
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(1);
			answer.push_back(5);
		}
		else if (_cube.getColorDetails(1, 0, 2)[0] == ORANGE && _cube.getColorDetails(1, 0, 2)[2] == BLUE)
		{
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(2);
		}
	}
	else if (getArgument(_cube.getColorDetails(2, 1, 2), BLUE, ORANGE))
	{
		if (_cube.getColorDetails(2, 1, 2)[0] == BLUE && _cube.getColorDetails(2, 1, 2)[5] == ORANGE)
		{
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(1);
			answer.push_back(5);
		}
		else if (_cube.getColorDetails(2, 1, 2)[0] == ORANGE && _cube.getColorDetails(2, 1, 2)[5] == BLUE)
		{
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			//
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(2);
		}
	}
	else if (getArgument(_cube.getColorDetails(2, 0, 1), BLUE, ORANGE))
	{
		if (_cube.getColorDetails(2, 0, 1)[2] != BLUE && _cube.getColorDetails(2, 0, 1)[5] != ORANGE)
		{
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(1);
			answer.push_back(5);
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(2);
		}
	}

	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i] == 2 || answer[i] == 3)
			_cube.rotationData(answer[i], 1);
		else
			_cube.rotationData(answer[i], -1);
		returnAnswer.push_back(answer[i]);
	}

	if (_cube.getColorDetails(2, 0, 1)[2] != BLUE && _cube.getColorDetails(2, 0, 1)[5] != ORANGE)
		layer_2_step_4(returnAnswer);
}

std::vector<int> Machine::getAction()
{
	std::vector<int> answer;

	cross_step_1(answer);
	cross_step_2(answer);
	cross_step_3(answer);
	cross_step_4(answer);

	layer_1_step_1(answer);
	layer_1_step_2(answer);
	layer_1_step_3(answer);
	layer_1_step_4(answer);

	layer_2_step_1(answer);
	layer_2_step_2(answer);
	layer_2_step_3(answer);
	layer_2_step_4(answer);

	std::cout << "Size: " << answer.size() << std::endl;

	return answer;
}