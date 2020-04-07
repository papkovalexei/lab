#include <iostream>
#include <vector>
#include <algorithm>

#include "CircularBuffer.h"

int main()
{
	std::vector<int> c;
	std::vector<int>::const_iterator;
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
	check.push_back(228);
	check.push_back(2128);
	check.push_back(28);
	check.push_top(-228);

	//std::sort(check.begin(), check.end());
	
	for (int i = 0; i < 7; i++)
		std::cout << check[i] << " ";
	std::cout << std::endl;
	return 0;
}