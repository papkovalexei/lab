#include "CPoint.h"

const float& CPoint::x() const
{
	return x_;
}

const float& CPoint::y() const
{
	return y_;
}

bool CPoint::operator==(const CPoint& value) const
{
	if (x() == value.x() && y() == value.y())
		return true;
	return false;
}