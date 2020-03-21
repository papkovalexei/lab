#pragma once
class CPoint
{
public:
	CPoint() {}
	CPoint(float x, float y) : x_(x), y_(y) {}

	const float& x() const;

	const float& y() const;

	bool operator==(const CPoint& value) const;
private:
	float x_;
	float y_;
};

