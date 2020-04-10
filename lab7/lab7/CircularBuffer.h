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

#include "CircularBuffer.tpp"