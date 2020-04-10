#pragma once

#include <exception>
#include <iterator>
#include <string>

#include "_CircularBuffer_iterator.h"

template <typename _Ty>
class CircularBuffer
{
public:
	CircularBuffer(size_t capacity);
	~CircularBuffer();

	_CircularBuffer_iterator<_Ty> begin();
	_CircularBuffer_iterator<_Ty> end();

	_CircularBuffer_iterator<_Ty> insert(const _CircularBuffer_iterator<_Ty>& iterator, const _Ty& value);
	_CircularBuffer_iterator<_Ty> erase(const _CircularBuffer_iterator<_Ty>& iterator);

	void push_back(const _Ty& val);
	void push_top(const _Ty& val);

	void pop_back();
	void pop_top();

	void resize(const size_t& capacity);
	size_t size() const;

	_Ty& operator[](const size_t& i) const;
private:
	size_t _capacity;
	size_t _count;
	int _start;
	int _end;
	_Ty* _arrayElement;
};

template <typename T>
CircularBuffer<T>::CircularBuffer(size_t capacity)
{
	_arrayElement = new T[capacity + 1];
	_capacity = capacity + 1;
	_start = 0;
	_end = 0;
	_count = 0;
}

template <typename T>
CircularBuffer<T>::~CircularBuffer()
{
	delete[] _arrayElement;
}

template <typename _Ty>
void CircularBuffer<_Ty>::push_back(const _Ty& val)
{
	if (_start % _capacity - _end % _capacity == 1)
		_start = (_start + 1) % _capacity;
	else
		_count++;
	_arrayElement[_end % _capacity] = val;
	_end = (_end + 1) % _capacity;
}

template <typename _Ty>
void CircularBuffer<_Ty>::push_top(const _Ty& val)
{
	if (_end % _capacity - _start % _capacity == 1 || (_end == _capacity - 1 && _start == 0))
	{
		_end = (_end + _capacity - 1) % _capacity;
	}
	else
		_count++;
	_start = (_start + _capacity - 1) % _capacity;
	_arrayElement[_start % _capacity] = val;
}

template <typename _Ty>
_Ty& CircularBuffer<_Ty>::operator[](const size_t& i) const
{
	return _arrayElement[(_start + i) % _capacity];
}

template <typename T>
void CircularBuffer<T>::pop_back()
{
	if (_start % _capacity != _end % _capacity)
		_end = (_end + _capacity - 1) % _capacity, _count--;
	else
		throw std::exception("Buffer is empty");
}

template <typename T>
void CircularBuffer<T>::pop_top()
{
	if (_start % _capacity != _end % _capacity)
		_start = (_start + 1) % _capacity, _count--;
	else
		throw std::exception("Buffer is empty");
}

template <typename _Ty>
typename _CircularBuffer_iterator<_Ty> CircularBuffer<_Ty>::begin()
{
	_CircularBuffer_iterator<_Ty> iterator(_arrayElement, _capacity, _start, _end, _start);

	return iterator;
}

template <typename _Ty>
typename _CircularBuffer_iterator<_Ty> CircularBuffer<_Ty>::end()
{
	_CircularBuffer_iterator<_Ty> iterator(_arrayElement, _capacity, _start, _end, _end);

	return iterator;
}

template <typename _Ty>
size_t CircularBuffer<_Ty>::size() const
{
	return _count;
}

template <typename _Ty>
void CircularBuffer<_Ty>::resize(const size_t& capacity)
{
	_Ty* buffer = new _Ty[_capacity];
	int max_size = 0;

	for (int i = 0; i < capacity; i++)
	{
		if (i == _count)
			break;

		buffer[i] = operator[](i);
		max_size++;
	}

	delete[] _arrayElement;
	_arrayElement = new _Ty[capacity + 1];

	for (int i = 0; i < max_size; i++)
		_arrayElement[i] = buffer[i];

	_count = max_size;
	_capacity = capacity + 1;
	_start = 0;
	_end = _count;

	delete[] buffer;
}

template <typename _Ty>
typename _CircularBuffer_iterator<_Ty> CircularBuffer<_Ty>::insert(const _CircularBuffer_iterator<_Ty>& iterator, const _Ty& value)
{
	if (iterator == begin())
	{
		push_top(value);
		return begin();
	}
	else if (iterator == end())
	{
		push_back(value);
		return end() - 1;
	}
	else
	{
		_Ty* buffer = new _Ty[_capacity];
		int max_size = 0;
		int position_in_buffer = -1;

		int i = 0;
		for (auto it = begin(); it != end(), i <= _count; it++, i++)
		{
			if (it == iterator)
			{
				position_in_buffer = i;
				buffer[i] = value;
				max_size++;
				i++;
			}

			buffer[i] = *it;
			max_size++;
		}

		delete[] _arrayElement;

		_arrayElement = new _Ty[_capacity];

		for (int i = 0; i <= max_size; i++)
			_arrayElement[i] = buffer[i];

		_start = 0;
		_end = max_size;
		_count = max_size;

		delete[] buffer;

		return begin() + position_in_buffer;
	}
}

template <typename _Ty>
typename _CircularBuffer_iterator<_Ty> CircularBuffer<_Ty>::erase(const _CircularBuffer_iterator<_Ty>& iterator)
{
	if (iterator == begin())
	{
		pop_top();
		return begin();
	}
	else if (iterator == end() - 1)
	{
		pop_back();
		return end() - 1;
	}
	else
	{
		_Ty* buffer = new _Ty[_capacity];
		int max_size = 0;
		int position_in_buffer = -1;

		int i = 0;
		for (auto it = begin(); it != end(); it++, i++)
		{
			if (it == iterator)
			{
				position_in_buffer = i;
				it++;
			}

			buffer[i] = *it;
			max_size = i;
		}

		delete[] _arrayElement;

		_arrayElement = new _Ty[_capacity];

		for (int i = 0; i <= max_size; i++)
			_arrayElement[i] = buffer[i];

		_start = 0;
		_end = max_size + 1;
		_count = max_size + 1;

		delete[] buffer;

		return begin() + position_in_buffer;
	}
}