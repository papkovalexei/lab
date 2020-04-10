#pragma once

#include <iterator>

template <typename _Ty>
class _CircularBuffer_iterator : public std::iterator<std::random_access_iterator_tag, _Ty>
{
public:
	using difference_type = typename std::iterator<std::random_access_iterator_tag, _Ty>::difference_type;

	_CircularBuffer_iterator() {}
	_CircularBuffer_iterator(_Ty* buffer, size_t& capacity, int& start, int& end, int position);

	bool operator!=(_CircularBuffer_iterator const& _other_iterator) const;
	bool operator==(_CircularBuffer_iterator const& _other_iterator) const;
	bool operator>(const _CircularBuffer_iterator& rhs) const;
	bool operator<(const _CircularBuffer_iterator& rhs) const;
	bool operator>=(const _CircularBuffer_iterator& rhs) const;
	bool operator<=(const _CircularBuffer_iterator& rhs) const;
	
	difference_type operator-(const _CircularBuffer_iterator& it) const;
	difference_type operator+(const _CircularBuffer_iterator& it) const;
	_CircularBuffer_iterator operator+(const int& _pos) const;
	_CircularBuffer_iterator operator-(const int& _pos) const;

	_CircularBuffer_iterator operator++();
	_CircularBuffer_iterator operator++(int);

	_CircularBuffer_iterator operator--();
	_CircularBuffer_iterator operator--(int);

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

#include "_CircularBuffer_iterator.tpp"