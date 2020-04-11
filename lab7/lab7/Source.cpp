#include <iostream>
#include <vector>
#include <algorithm>

#include "CircularBuffer.h"

int main()
{
	CircularBuffer<int> check(10);

	check.push_back(10);
	check.push_back(11);
	check.push_top(-228);
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
	check.push_back(322);
	check.push_back(323);
	check.push_back(324);
	for (int i = 0; i < 10; i++)
		std::cout << check[i] << " ";
	std::cout << std::endl << "___________________" << std::endl;
	std::sort(check.begin(), check.end());
	std::cout << "Sort" << std::endl;
	for (int i = 0; i < 10; i++)
		std::cout << check[i] << " ";
	std::cout << std::endl << "___________________" << std::endl;

	check.erase(find(check.begin(), check.end(), 9));
	std::cout << "Delete 9" << std::endl;
	check.erase(find(check.begin(), check.end(), 2128));
	std::cout << "Delete 2128" << std::endl;

	for (int i = 0; i < check.size(); i++)
		std::cout << check[i] << " ";
	std::cout << std::endl << "___________________" << std::endl;

	std::cout << "Insert 1111 before 10" << std::endl;
	check.insert(find(check.begin(), check.end(), 10), 1111);

	for (int i = 0; i < check.size(); i++)
		std::cout << check[i] << " ";
	std::cout << std::endl << "___________________" << std::endl;

	std::cout << "Set capacity = 5" << std::endl;
	check.resize(5);

	for (int i = 0; i < check.size(); i++)
		std::cout << check[i] << " ";
	std::cout << std::endl << "___________________" << std::endl;

	std::cout << "Push top 2222" << std::endl;
	check.push_top(2222);
	for (int i = 0; i < check.size(); i++)
		std::cout << check[i] << " ";
	std::cout << std::endl << "___________________" << std::endl;

	std::cout << "Set capacity = 7" << std::endl;
		check.resize(7);
	std::cout << "Push top 3333" << std::endl;
	std::cout << "Push back 4444" << std::endl;
	check.push_top(3333);
	check.push_back(4444);
	
	for (int i = 0; i < check.size(); i++)
		std::cout << check[i] << " ";
	std::cout << std::endl << "___________________" << std::endl;

	std::cout << "Iterator: ";
	for (auto it = check.begin() + 1; it != check.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << "___________________" << std::endl;

	return 0;
}