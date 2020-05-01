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

std::vector<int> Machine::getAction()
{
	if (_step == 0)
	{
		std::vector<int> answer;

		if (getArgument(_cube._details[0][1][0].getColorFragment(), 0xFF38CA, 0xFFFF00))
		{
			if (_cube._details[0][1][0].getColorFragment()[1] != 0xFFFF00 && _cube._details[0][1][0].getColorFragment()[4] != 0xFF38CA)
			{
				std::cout << "Furu pink\n";

				answer.push_back(4);
				answer.push_back(0);
				answer.push_back(0);
				answer.push_back(0);
				answer.push_back(3);
				answer.push_back(3);
				answer.push_back(3);
				answer.push_back(0);

				return answer;
			}
		}
		else if (getArgument(_cube._details[1][0][0].getColorFragment(), 0xFF38CA, 0xFFFF00))
		{
			answer.push_back(0);
			answer.push_back(0);
			answer.push_back(0);

			return answer;

		}
		else if (getArgument(_cube._details[0][1][2].getColorFragment(), 0xFF38CA, 0xFFFF00))
		{
			answer.push_back(4);
			answer.push_back(4);
			return answer;
		}
		else if (getArgument(_cube._details[1][2][2].getColorFragment(), 0xFF38CA, 0xFFFF00))
		{
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(4);
			return answer;
		}
		else if (getArgument(_cube._details[1][0][2].getColorFragment(), 0xFF38CA, 0xFFFF00))
		{
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(4);

			return answer;
		}
		else if (getArgument(_cube._details[2][1][2].getColorFragment(), 0xFF38CA, 0xFFFF00))
		{
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(4);

			return answer;
		}
		else if (getArgument(_cube._details[2][1][0].getColorFragment(), 0xFF38CA, 0xFFFF00))
		{
			answer.push_back(0);
			answer.push_back(0);

			return answer;
		}
		else if (getArgument(_cube._details[2][0][1].getColorFragment(), 0xFF38CA, 0xFFFF00))
		{
			answer.push_back(5);
			answer.push_back(0);
			answer.push_back(0);

			return answer;
		}
		else if (getArgument(_cube._details[2][2][1].getColorFragment(), 0xFF38CA, 0xFFFF00))
		{
			answer.push_back(3);
			answer.push_back(0);

			return answer;
		}
		else if (getArgument(_cube._details[1][2][0].getColorFragment(), 0xFF38CA, 0xFFFF00))
		{
			answer.push_back(0);

			return answer;
		}
		else if (getArgument(_cube._details[0][2][1].getColorFragment(), 0xFF38CA, 0xFFFF00))
		{
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(4);

			return answer;
		}
		else if (getArgument(_cube._details[0][0][1].getColorFragment(), 0xFF38CA, 0xFFFF00))
		{
			answer.push_back(4);

			return answer;
		}
	}
	else if (_step == 1)
	{
		std::vector<int> answer;

		std::cout << "STEP 1\n";

		if (getArgument(_cube._details[0][1][2].getColorFragment(), 0x00FF00, 0xFFFF00))
		{
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(3);
			return answer;
		}
		else if (getArgument(_cube._details[1][2][2].getColorFragment(), 0x00FF00, 0xFFFF00))
		{
			answer.push_back(3);
			answer.push_back(3);
			return answer;
		}
		else if (getArgument(_cube._details[1][0][2].getColorFragment(), 0x00FF00, 0xFFFF00))
		{
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(3);

			return answer;
		}
		else if (getArgument(_cube._details[2][1][2].getColorFragment(), 0x00FF00, 0xFFFF00))
		{
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(3);

			return answer;
		}
		else if (getArgument(_cube._details[2][1][0].getColorFragment(), 0x00FF00, 0xFFFF00))
		{
			answer.push_back(5);
			answer.push_back(3);

			return answer;
		}
		else if (getArgument(_cube._details[2][0][1].getColorFragment(), 0x00FF00, 0xFFFF00))
		{
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(3);

			return answer;
		}
		else if (getArgument(_cube._details[2][2][1].getColorFragment(), 0x00FF00, 0xFFFF00))
		{
			answer.push_back(3);

			return answer;
		}
		else if (getArgument(_cube._details[1][2][0].getColorFragment(), 0x00FF00, 0xFFFF00))
		{
			if (_cube._details[1][2][0].getColorFragment()[1] != 0xFFFF00 && _cube._details[1][2][0].getColorFragment()[3] != 0x00FF00)
			{
				std::cout << "Furu green\n";
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
		else if (getArgument(_cube._details[0][2][1].getColorFragment(), 0x00FF00, 0xFFFF00))
		{
			answer.push_back(3);
			answer.push_back(3);
			answer.push_back(3);

			return answer;
		}
		else if (getArgument(_cube._details[0][0][1].getColorFragment(), 0x00FF00, 0xFFFF00))
		{
			answer.push_back(2);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(3);
			answer.push_back(3);

			return answer;
		}
		else if (getArgument(_cube._details[1][0][0].getColorFragment(), 0x00FF00, 0xFFFF00))
		{
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(3);

			return answer;
		}
	}
	else if (_step == 2)
	{
		std::vector<int> answer;

		std::cout << "STEP 2\n";

		if (getArgument(_cube._details[0][1][2].getColorFragment(), 0x0000FF, 0xFFFF00))
		{
			answer.push_back(4);
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(2);
			return answer;
		}
		else if (getArgument(_cube._details[1][2][2].getColorFragment(), 0x0000FF, 0xFFFF00))
		{
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(2);
			return answer;
		}
		else if (getArgument(_cube._details[1][0][2].getColorFragment(), 0x0000FF, 0xFFFF00))
		{
			answer.push_back(2);
			answer.push_back(2);

			return answer;
		}
		else if (getArgument(_cube._details[2][1][2].getColorFragment(), 0x0000FF, 0xFFFF00))
		{
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(2);

			return answer;
		}
		else if (getArgument(_cube._details[2][1][0].getColorFragment(), 0x0000FF, 0xFFFF00))
		{
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(2);

			return answer;
		}
		else if (getArgument(_cube._details[2][0][1].getColorFragment(), 0x0000FF, 0xFFFF00))
		{
			answer.push_back(2);

			return answer;
		}
		else if (getArgument(_cube._details[2][2][1].getColorFragment(), 0x0000FF, 0xFFFF00))
		{
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(2);

			return answer;
		}
		else if (getArgument(_cube._details[0][2][1].getColorFragment(), 0x0000FF, 0xFFFF00))
		{
			answer.push_back(4);
			answer.push_back(1);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(4);
			answer.push_back(2);
			answer.push_back(2);

			return answer;
		}
		else if (getArgument(_cube._details[0][0][1].getColorFragment(), 0x0000FF, 0xFFFF00))
		{
			answer.push_back(2);
			answer.push_back(2);
			answer.push_back(2);

			return answer;
		}
		else if (getArgument(_cube._details[1][0][0].getColorFragment(), 0x0000FF, 0xFFFF00))
		{
			if (_cube._details[1][0][0].getColorFragment()[1] != 0xFFFF00 && _cube._details[1][0][0].getColorFragment()[2] != 0x0000FF)
			{
				std::cout << "Furu green\n";

				answer.push_back(2);
				answer.push_back(0);
				answer.push_back(0);
				answer.push_back(0);
				answer.push_back(4);
				answer.push_back(0);
				return answer;
			}
		}
	}
	else if (_step == 3)
	{
	std::vector<int> answer;

	std::cout << "STEP 3\n";

	if (getArgument(_cube._details[0][1][2].getColorFragment(), 0xFF6F00, 0xFFFF00))
	{
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(5);
		answer.push_back(5);
		return answer;
	}
	else if (getArgument(_cube._details[1][2][2].getColorFragment(), 0xFF6F00, 0xFFFF00))
	{
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(5);
		answer.push_back(5);
		return answer;
	}
	else if (getArgument(_cube._details[1][0][2].getColorFragment(), 0xFF6F00, 0xFFFF00))
	{
		answer.push_back(1);
		answer.push_back(5);
		answer.push_back(5);

		return answer;
	}
	else if (getArgument(_cube._details[2][1][2].getColorFragment(), 0xFF6F00, 0xFFFF00))
	{
		answer.push_back(5);
		answer.push_back(5);

		return answer;
	}
	else if (getArgument(_cube._details[2][1][0].getColorFragment(), 0xFF6F00, 0xFFFF00))
	{
		if (_cube._details[2][1][0].getColorFragment()[1] != 0xFFFF00 && _cube._details[2][1][0].getColorFragment()[5] != 0xFF6F00)
		{
			std::cout << "Furu orange\n";

			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(5);
			answer.push_back(0);
			answer.push_back(0);
			answer.push_back(0);
			answer.push_back(2);
			answer.push_back(0);

			return answer;
		}
	}
	else if (getArgument(_cube._details[2][0][1].getColorFragment(), 0xFF6F00, 0xFFFF00))
	{
		answer.push_back(5);

		return answer;
	}
	else if (getArgument(_cube._details[2][2][1].getColorFragment(), 0xFF6F00, 0xFFFF00))
	{
		answer.push_back(5);
		answer.push_back(5);
		answer.push_back(5);

		return answer;
	}
	else if (getArgument(_cube._details[0][2][1].getColorFragment(), 0xFF6F00, 0xFFFF00))
	{
		answer.push_back(3);
		answer.push_back(1);
		answer.push_back(3);
		answer.push_back(3);
		answer.push_back(3);
		answer.push_back(1);
		answer.push_back(1);
		answer.push_back(5);
		answer.push_back(5);

		return answer;
	}
	else if (getArgument(_cube._details[0][0][1].getColorFragment(), 0xFF6F00, 0xFFFF00))
	{
		answer.push_back(2);
		answer.push_back(1);
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(2);
		answer.push_back(5);
		answer.push_back(5);

		return answer;
	}
 }
	else if (_step == 4)
	{

 }
}