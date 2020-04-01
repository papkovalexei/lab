#pragma once

#include <exception>

template <typename T> 
class CircularBuffer
{
public:
	CircularBuffer(size_t capacity);
	~CircularBuffer();

	size_t size() const;

	void push_back(const T& val);
	void push_top(const T& val);

	void pop_back();
	void pop_top();

	T& operator[](size_t i) const;
private:
	size_t _capacity;
	size_t _start;
	size_t _end;
	size_t _count;
	T* _arrayElement;
};

template <typename T>
CircularBuffer<T>::CircularBuffer(size_t capacity) : _capacity(capacity)
{
	_arrayElement = new T[capacity];
	_count = 0;
	_start = 0;
	_end = 0;
}

template <typename T>
CircularBuffer<T>::~CircularBuffer()
{
	delete[] _arrayElement;
}

template <typename T>
void CircularBuffer<T>::push_back(const T& val)
{
	if (_count < _capacity)
	{
		_count++;

		if (_end + 1 == _capacity)
			_end = 0;
		_arrayElement[_end++ % _capacity] = val;
	}
	else
		throw std::exception("Buffer overflow");
}

template <typename T>
void CircularBuffer<T>::push_top(const T& val)
{
	if (_count < _capacity)
	{
		_count++;

		if ((signed)_start - 1 < 0)
			_start = _capacity - 1;
		else
			_start--;
		_arrayElement[_start % _capacity] = val;
	}
	else
		throw std::exception("Buffer overflow");
}

template <typename T>
T& CircularBuffer<T>::operator[](size_t i) const
{
	return _arrayElement[(_start + i) % _capacity];
}

template <typename T>
void CircularBuffer<T>::pop_back()
{
	if (_count > 0)
	{
		if ((signed)_end - 1 < 0)
		{
			_arrayElement[_capacity - 1] = T();
			_end = _capacity - 1;
		}
		else
		{
			_arrayElement[(_end - 1) % _capacity] = T();
			_end--;
		}
		_count--;
	}
	else
		throw std::exception("Buffer is empty");
}

template <typename T>
void CircularBuffer<T>::pop_top()
{
	if (_count > 0)
	{
		_arrayElement[_start++ % _capacity] = T();
		_count--;
	}
	else
		throw std::exception("Buffer is empty");
}

template <typename T>
size_t CircularBuffer<T>::size() const
{
	return _count;
}