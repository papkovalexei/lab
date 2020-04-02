#include <iostream>
#include <vector>
#include <algorithm>

#include "CircularBuffer.h"

int main()
{
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

	auto it = std::min_element(check.begin(), check.end());

	std::cout << *it << std::endl;

	std::cout << "_________________" << std::endl;

	for (auto it = check.begin(); it != check.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	return 0;
}