#include <iostream>
#include <vector>

#include "CPoint.h"

bool predicateInt(const int& value)
{
	if (value <= 10)
		return true;
	return false;
}

bool predicatePoint(const CPoint& value)
{
	if (value.x() <= 10)
		return true;
	return false;
}

bool compareSortedInt(const int& left, const int& right)
{
	if (left < right)
		return true;
	return false;
}

bool compareSortedPointOX(const CPoint& left, const CPoint& right)
{
	if (left.x() < right.x())
		return true;
	return false;
}

template <class Iterator, class Predicate>
bool none_of(Iterator first, Iterator last, Predicate pred)
{
	while (first != last)
	{
		if (pred(*first))
			return false;
		first++;
	}
	return true;
}

template <class Iterator, class Compare>
bool is_sorted(Iterator first, Iterator last, Compare compare)
{
	if (first != last)
	{
		Iterator next = first;

		while (++next != last)
		{
			if (compare(*next, *first))
				return false;
			first = next;
		}
	}
	return true;
}

template <class Iterator, class T>
Iterator find_backward(Iterator first, Iterator last, const T& value)
{
	Iterator endArray = last;

	last--;
	while (first != last)
	{
		if (*last == value)
			return last;
		last--;
	}

	if (last == first && *last == value)
		return first;
	else
		return endArray;
}

int main() {
	std::vector<int> array;
	int N;

	std::cout << "Input range: ";
	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		int number;

		std::cin >> number;

		array.push_back(number);
	}

	std::cout << "Is sorted: ";
	if (is_sorted(array.begin(), array.end(), compareSortedInt))
		std::cout << "yes" << std::endl;
	else
		std::cout << "no" << std::endl;

	int findNumber;

	std::cout << "Input number: ";
	std::cin >> findNumber;

	std::cout << "Find " << findNumber << ": ";
	
	if (find_backward(array.begin(), array.end(), findNumber) == array.end())
		std::cout << findNumber << " - not exists" << std::endl;
	else
		std::cout << "exists" << std::endl;
	
	std::cout << "All number > 10: ";

	if (none_of(array.begin(), array.end(), predicateInt))
		std::cout << "Yes" << std::endl;
	else
		std::cout << "No" << std::endl;

	std::vector<CPoint> points;

	std::cout << "Input range point: ";
	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		float x, y;

		std::cout << "(x, y): ";
		std::cin >> x >> y;

		points.push_back(CPoint(x, y));
	}

	std::cout << "Is sorted(OX): ";
	if (is_sorted(points.begin(), points.end(), compareSortedPointOX))
		std::cout << "yes" << std::endl;
	else
		std::cout << "no" << std::endl;

	float findX, findY;

	std::cout << "Input point: ";
	std::cin >> findX >> findY;

	CPoint findPoint(findX, findY);

	std::cout << "Find " << findNumber << ": ";

	if (find_backward(points.begin(), points.end(), findPoint) == points.end())
		std::cout << "not exists" << std::endl;
	else
		std::cout << "exists" << std::endl;

	std::cout << "All point.X > 10: ";

	if (none_of(points.begin(), points.end(), predicatePoint))
		std::cout << "Yes" << std::endl;
	else
		std::cout << "No" << std::endl;

	return 0;
}