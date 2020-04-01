#include <iostream>
#include <vector>
#include <algorithm>

#include "CircularBuffer.h"

int main()
{
	std::vector<int> hui(5);
	
	hui.push_back(10);
	hui.push_back(11);
	hui.push_back(12);
	hui.push_back(13);
	hui.push_back(14);
	
	hui.resize(3);

	hui.push_back(15);

	hui.push_back(2);

	CircularBuffer<int> check(10);

	check.push_back(10);
	check.push_back(11);
	check.push_back(12);
	check.push_top(9);
	check.push_top(8);
	check.pop_top();
	check.pop_back();
	check.push_top(-1);
	check.pop_back();

	for (int i = 0; i < check.size(); i++)
	{
		std::cout << check[i] << std::endl;
	}

	return 0;
}