#include <iostream>
#include <vector>
#include <fstream>

#include "initGraphics.h"

using namespace std;

int main(int argc, char** argv)
{
	if (argc > 2)
	{
		ifstream input_file(argv[1]);
		bool ok = true;

		unsigned int color_position[162];

		int count_color[6] = { 0, 0, 0, 0, 0, 0 };

		for (int i = 0; i < 162; i++)
		{
			input_file >> color_position[i];

			switch (color_position[i])
			{
			case WHITE:
				count_color[0]++;
				break;
			case GREEN:
				count_color[1]++;
				break;
			case ORANGE:
				count_color[2]++;
				break;
			case BLUE:
				count_color[3]++;
				break;
			case PINK:
				count_color[4]++;
				break;
			case YELLOW:
				count_color[5]++;
				break;
			default:
				break;
			}
		}

		for (int i = 0; i < 6; i++)
			if (count_color[i] != 9)
			{
				ok = false;
				break;
			}

		unsigned int color_brik[9] = { WHITE, YELLOW, BLUE, GREEN, PINK, ORANGE };

		RubikCube cube;

		cube.init(SIZE, color_brik, color_position);

		Machine machine(cube);

		vector<int> check_correct = machine.getAction();

		if (check_correct.size() == 1)
		{
			if (check_correct[0] == -1)
				ok = false;
		}

		if (ok)
			initCube(argc, argv, color_position);
		else
		{
			std::cerr << "Incorrect cube\n";
			return 1;
		}
	}
	else
		initCube(argc, argv);

	glutMainLoop();

	return 0;
}