#include "Fixed.hpp"
#include "Point.hpp"

float	sign(Point p1, Point p2, Point p3)
{
	return ((p1.toGetX() - p3.toGetX()) * (p2.toGetY() - p3.toGetY()) - (p2.toGetX() - p3.toGetX()) * (p1.toGetY() - p3.toGetY())).toFloat();
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	d1, d2, d3;
	bool	has_neg, has_pos;

	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);

	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return (!(has_neg && has_pos));
}