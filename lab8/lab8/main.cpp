#include <iostream>
#include <vector>
#include <fstream>

#include "initGraphics.h"

using namespace std;

int main(int argc, char** argv)
{
	if (argc > 1)
	{
		ifstream input_file(argv[1]);

		unsigned int color_position[162];

		for (int i = 0; i < 162; i++)
			input_file >> color_position[i];
		initCube(argc, argv, color_position);
	}
	else
		initCube(argc, argv);

	glutMainLoop();

	return 0;
}