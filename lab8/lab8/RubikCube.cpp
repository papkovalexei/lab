#include <iostream>

#include "RubikCube.h"

RubikCube::RubikCube(float size, unsigned int* color) : _size(size)
{
	_brink_animation = -1;

	for (int i = 0; i < 6; i++)
		_brink_rotate[i] = 0;

	for (int i = 0; i < 6; i++)
		_color[i] = color[i];

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			_details[i][j][2].setColor(0, _color[0]);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			_details[i][j][0].setColor(1, _color[1]);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			_details[j][0][i].setColor(2, _color[2]);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			_details[j][2][i].setColor(3, _color[3]);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			_details[0][j][i].setColor(4, _color[4]);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			_details[2][j][i].setColor(5, _color[5]);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				_details[i][j][k].setSize((_size / 3.0) * 0.95);
}

int RubikCube::getBrinkAnimation()
{
	return _brink_animation;
}

void RubikCube::rotationData(int brink, int vec)
{
	if (vec == -1)
		vec = 3;
	while (vec--)
	{
		if (brink == 0 || brink == 1)
		{
			int k = (brink & 1) * 2;

			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					tmp[j][2 - i] = _details[i][j][k];
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					tmp[i][j].rotateZ(), _details[i][j][k] = tmp[i][j];
		}
		else if (brink == 2 || brink == 3)
		{
			int j = (brink & 1) * 2;
			for (int i = 0; i < 3; i++)
				for (int k = 0; k < 3; k++)
					tmp[k][2 - i] = _details[i][j][k];
			for (int i = 0; i < 3; i++)
				for (int k = 0; k < 3; k++)
					tmp[i][k].rotateX(), _details[i][j][k] = tmp[i][k];
		}
		else if (brink == 4 || brink == 5)
		{
			int i = (brink & 1) * 2;
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++)
					tmp[k][2 - j] = _details[i][j][k];
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++)
					tmp[j][k].rotateY(), _details[i][j][k] = tmp[j][k];
		}
	}
}

void RubikCube::rotation(int brink, float angle)
{
	if (_brink_animation == -1 || _brink_animation == brink)
	{
		_brink_rotate[brink] += angle;

		if (static_cast<int>(_brink_rotate[brink]) % 90 != 0)
		{
			_brink_animation = brink;
		}
		else
		{
			if ((_brink_rotate[brink] < 0) ^ (_brink_animation == 2 || brink == 3))
				rotationData(brink, 1);
			else
				rotationData(brink, -1);
			_brink_rotate[brink] = 0;
			_brink_animation = -1;
		}
	}
}

void RubikCube::draw()
{
	bool check_status[4][4][4];
	memset(check_status, true, sizeof(check_status));
	
	if (_brink_animation != -1)
	{
		glPushMatrix();

		if (_brink_animation == 0 || _brink_animation == 1)
		{
			int k = (_brink_animation & 1) * 2;

			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					check_status[i][j][k] = false;

			glTranslated(_size / 2, _size / 2, 0);
			glRotatef(_brink_rotate[_brink_animation], 0, 0, 1);
			glTranslated(-_size / 2, -_size / 2, 0); 
			
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					_details[i][j][k].draw(_size / 3 * i, _size / 3 * j, _size / 3 * k);
		}
		else if (_brink_animation == 2 || _brink_animation == 3)
		{
			int j = (_brink_animation & 1) * 2;
			for (int i = 0; i < 3; i++)
				for (int k = 0; k < 3; k++)
					check_status[i][j][k] = false;

			glTranslated(_size / 2, 0, _size / 2);
			glRotatef(_brink_rotate[_brink_animation], 0, 1, 0);
			glTranslated(-_size / 2, 0, -_size / 2);
			for (int i = 0; i < 3; i++)
				for (int k = 0; k < 3; k++)
					_details[i][j][k].draw(_size / 3 * i, _size / 3 * j, _size / 3 * k);
		}
		else if (_brink_animation == 4 || _brink_animation == 5)
		{
			int i = (_brink_animation & 1) * 2;
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++)
					check_status[i][j][k] = false;

			glTranslated(0, _size / 2, _size / 2);
			glRotatef(_brink_rotate[_brink_animation], 1, 0, 0);
			glTranslated(0, -_size / 2, -_size / 2);
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++)
					_details[i][j][k].draw(_size / 3 * i, _size / 3 * j, _size / 3 * k);
		}

		glPopMatrix();
	}

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				if (check_status[i][j][k])
					_details[i][j][k].draw(_size / 3 * i, _size / 3 * j, _size / 3 * k);
}