#include <iostream>

#include "RubikCube.h"

/*
center:
	[0][1][1] - pink
	[1][0][1] - blue
	[1][1][0] - yellow
	[2][1][1] - orange
	[1][2][1] - green
	[1][1][2] - white
2 color brik:
*/

/*

*/

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

void RubikCube::pushMove(int brink)
{
	_queueMove.push(brink);
}

RubikCube::RubikCube() {}

int RubikCube::getBrinkAnimation()
{
	return _brink_animation;
}

int* RubikCube::getColorDetails(int i, int j, int k)
{
	return _details[i][j][k].getColorFragment();
}

void RubikCube::operator=(const RubikCube copy_cube)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
			{
				this->_details[i][j][k] = copy_cube._details[i][j][k];
			}

	for (int i = 0; i < 6; i++)
		this->_color[i] = copy_cube._color[i];
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

void RubikCube::rotation(int brink)
{
	if (_brink_animation == -1 || _brink_animation == brink)
	{
		_brink_rotate[brink] += _ANGLE_ROTATE;

		if (static_cast<int>(_brink_rotate[brink]) % 90 != 0)
		{
			_brink_animation = brink;
		}
		else
		{
			if ((_brink_rotate[brink] < 0) ^ (_brink_animation == 2 || _brink_animation == 3))
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

void RubikCube::rotation()
{
	if (!_queueMove.empty())
	{
		int brink = _queueMove.front();
		_queueMove.pop();

		rotation(brink);
	}
}

bool RubikCube::emptyQueue()
{
	return _queueMove.empty();
}

void RubikCube::init(float size, unsigned int* color, unsigned int* position_color)
{
	_brink_animation = -1;

	for (int i = 0; i < 6; i++)
		_brink_rotate[i] = 0;

	for (int i = 0; i < 6; i++)
		_color[i] = color[i];

	_size = size;
	int position = 0;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
			{
				unsigned int buffer_color[6];

				for (int c = 0; c < 6; c++)
				{
					buffer_color[c] = position_color[position];
					position++;
				}

				_details[i][j][k].setColorFragment(buffer_color);
			}

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				_details[i][j][k].setSize((_size / 3.0) * 0.95);
}

void RubikCube::init(float size, unsigned int* color)
{
	_size = size;
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