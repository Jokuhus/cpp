#include "Point.hpp"

Point::Point(void) : X(0), Y(0)
{
}

Point::Point(const float x, const float y) : X(x), Y(y)
{
}

Point&	Point::operator=(const Point& point)
{
	if (this == &point)
		return (*this);
	return (*this);
}

Point::~Point(void)
{
}

const Fixed	Point::toGetX(void) const
{
	return (this->X);
}

const Fixed	Point::toGetY(void) const
{
	return (this->Y);
}
