#pragma once

#include <exception>
#include <iterator>

template <typename _Ty>
class _CircularBuffer_iterator : public std::iterator<std::random_access_iterator_tag, _Ty>
{
public:
	_CircularBuffer_iterator() {}

	_CircularBuffer_iterator(_Ty* buffer, size_t& capacity, int& start, int& end, int position) : _data(buffer), _capacity(capacity), _start(start), _end(end), _position(position){}

	bool operator!=(_CircularBuffer_iterator const& _other_iterator) const
	{
		return this->_position % _capacity != _other_iterator._position % _capacity;
	}
	bool operator==(_CircularBuffer_iterator const& _other_iterator) const
	{
		return this->_position % _capacity == _other_iterator._position % _capacity;
	}

	_CircularBuffer_iterator operator-(const int& _pos) const
	{
		_CircularBuffer_iterator iterator = *this;

		iterator._position -= _pos;

		return iterator;
	}
	_CircularBuffer_iterator operator-(const _CircularBuffer_iterator& it) const
	{
		_CircularBuffer_iterator iterator = *this;

		iterator._position -= it._position;

		return iterator;
	}

	_CircularBuffer_iterator operator+(const int& _pos) const
	{
		_CircularBuffer_iterator iterator = *this;

		iterator._position += _pos;

		return iterator;
	}
	_Ty operator+(const _CircularBuffer_iterator& it) const
	{
		_CircularBuffer_iterator iterator = *this;

		iterator._position += it._position;

		return *iterator;
	}

	_CircularBuffer_iterator operator++()
	{
		this->_position++;

		return *this;
	}
	_CircularBuffer_iterator operator++(int)
	{
		_CircularBuffer_iterator tmp(*this);

		operator++();

		return tmp;
	}

	_CircularBuffer_iterator operator--()
	{
		this->_position--;

		return *this;
	}
	_CircularBuffer_iterator operator--(int)
	{
		_CircularBuffer_iterator tmp(*this);

		operator--();

		return tmp;
	}

	typename _CircularBuffer_iterator::reference operator*() const
	{
		return _data[_position % _capacity];
	}

private:
	_Ty* _data;
	int _position;
	int _start;
	int _end;
	size_t _capacity;
};

template <typename _Ty>
class CircularBuffer
{
public:
	CircularBuffer(size_t capacity);
	~CircularBuffer();

	size_t size() const;

	_CircularBuffer_iterator<_Ty> begin();
	_CircularBuffer_iterator<_Ty> end();

	void push_back(const _Ty& val);
	void push_top(const _Ty& val);

	void pop_back();
	void pop_top();

	_Ty& operator[](size_t i) const;
private:
	size_t _capacity;
	int _start;
	int _end;
	int _count;
	_Ty* _arrayElement;
};

template <typename T>
CircularBuffer<T>::CircularBuffer(size_t capacity)
{
	_arrayElement = new T[capacity];
	_capacity = capacity;
	_count = 0;
	_start = 0;
	_end = 0;
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
		_start++;
	_arrayElement[_end++ % _capacity] = val;
}

template <typename _Ty>
void CircularBuffer<_Ty>::push_top(const _Ty& val)
{
	_start = (_start + _capacity - 1) % _capacity;
	_arrayElement[_start % _capacity] = val;

}

template <typename _Ty>
_Ty& CircularBuffer<_Ty>::operator[](size_t i) const
{
	return _arrayElement[(_start + i) % _capacity];
}

template <typename T>
void CircularBuffer<T>::pop_back()
{
	if (_start % _capacity != _end % _capacity)
		_end = _end + _capacity - 1;
	else
		throw std::exception("Buffer is empty");
}

template <typename T>
void CircularBuffer<T>::pop_top()
{
	if (_start % _capacity != _end % _capacity)
		_start++;
	else
		throw std::exception("Buffer is empty");
}

template <typename T>
size_t CircularBuffer<T>::size() const
{
	return _count;
}

//_CircularBuffer_iterator(_Ty* buffer, size_t& capacity, size_t& start, size_t& end) : _data(buffer), _capacity(capacity), _start(start), _end(end) {}

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