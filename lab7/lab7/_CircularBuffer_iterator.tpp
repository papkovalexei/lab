#include "_CircularBuffer_iterator.h"

template <typename _Ty>
_CircularBuffer_iterator<_Ty>::_CircularBuffer_iterator(_Ty* buffer, size_t& capacity, int& start, int& end, int position) : _data(buffer), _capacity(capacity), _start(start), _end(end), _position(position) {}

template <typename _Ty>
bool _CircularBuffer_iterator<_Ty>::operator!=(_CircularBuffer_iterator const& _other_iterator) const
{
	return this->_position % _capacity != _other_iterator._position % _capacity;
}

template <typename _Ty>
bool _CircularBuffer_iterator<_Ty>::operator==(_CircularBuffer_iterator const& _other_iterator) const
{
	return this->_position % _capacity == _other_iterator._position % _capacity;
}

template <typename _Ty>
bool _CircularBuffer_iterator<_Ty>::operator>(const _CircularBuffer_iterator& rhs) const
{
	if (_start > _end)
	{
		if (_position < _capacity && rhs._position < _capacity)
			return _position > rhs._position;
		else if (_position < _capacity)
			return false;
		else if (rhs._position < _capacity)
			return true;
		else
			return _position > rhs._position;
	}
	else
		return _position > rhs._position;
}

template <typename _Ty>
bool _CircularBuffer_iterator<_Ty>::operator<(const _CircularBuffer_iterator& rhs) const
{
	if (_start > _end)
	{
		if (_position < _capacity && rhs._position < _capacity)
			return _position < rhs._position;
		else if (_position < _capacity)
			return true;
		else if (rhs._position < _capacity)
			return false;
		else
			return _position < rhs._position;
	}
	else
		return _position < rhs._position;
}

template <typename _Ty>
bool _CircularBuffer_iterator<_Ty>::operator>=(const _CircularBuffer_iterator& rhs) const
{
	if (_start > _end)
	{
		if (_position < _capacity && rhs._position < _capacity)
			return _position >= rhs._position;
		else if (_position < _capacity)
			return false;
		else if (rhs._position < _capacity)
			return true;
		else
			return _position >= rhs._position;
	}
	else
		return _position >= rhs._position;
}

template <typename _Ty>
bool _CircularBuffer_iterator<_Ty>::operator<=(const _CircularBuffer_iterator& rhs) const
{
	if (_start > _end)
	{
		if (_position < _capacity && rhs._position < _capacity)
			return _position <= rhs._position;
		else if (_position < _capacity)
			return true;
		else if (rhs._position < _capacity)
			return false;
		else
			return _position <= rhs._position;
	}
	else
		return _position <= rhs._position;
}

template <typename _Ty>
typename _CircularBuffer_iterator<_Ty>::difference_type _CircularBuffer_iterator<_Ty>::operator-(const _CircularBuffer_iterator& it) const
{
	_CircularBuffer_iterator iterator = *this;

	iterator._position -= it._position;

	return *iterator;
}

template <typename _Ty>
typename _CircularBuffer_iterator<_Ty>::difference_type _CircularBuffer_iterator<_Ty>::operator+(const _CircularBuffer_iterator& it) const
{
	_CircularBuffer_iterator iterator = *this;

	iterator._position += it._position;

	return *iterator;
}

template <typename _Ty>
typename _CircularBuffer_iterator<_Ty> _CircularBuffer_iterator<_Ty>::operator+(const int& _pos) const
{
	_CircularBuffer_iterator iterator = *this;

	iterator._position = (_position + _pos) % _capacity;

	return iterator;
}

template <typename _Ty>
typename _CircularBuffer_iterator<_Ty> _CircularBuffer_iterator<_Ty>::operator-(const int& _pos) const
{
	_CircularBuffer_iterator iterator = *this;

	iterator._position = (_position + _capacity - _pos) % _capacity;

	return iterator;
}

template <typename _Ty>
typename _CircularBuffer_iterator<_Ty> _CircularBuffer_iterator<_Ty>::operator++()
{
	this->_position++;

	return *this;
}

template <typename _Ty>
typename _CircularBuffer_iterator<_Ty> _CircularBuffer_iterator<_Ty>::operator++(int)
{
	_CircularBuffer_iterator tmp(*this);

	operator++();

	return tmp;
}

template <typename _Ty>
typename _CircularBuffer_iterator<_Ty> _CircularBuffer_iterator<_Ty>::operator--()
{
	this->_position--;

	return *this;
}

template <typename _Ty>
typename _CircularBuffer_iterator<_Ty> _CircularBuffer_iterator<_Ty>::operator--(int)
{
	_CircularBuffer_iterator tmp(*this);

	operator--();

	return tmp;
}