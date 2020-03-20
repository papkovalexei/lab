#include <iostream>
#include <vector>

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
			if (comp(*next, *first))
				return false;
			first = next;
		}
	}
	return true;
}

template <class Iterator, class T>
Iterator find_backward(Iterator first, Iterator last, const T& value)
{
	while (first != last)
	{
		if (*last == value)
			return last;
		last--;
	}
	return last;
}

int main()
{
	return 0;
}