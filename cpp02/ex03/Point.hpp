#ifndef _POINT_HPP_
# define _POINT_HPP_

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const	X;
		Fixed const	Y;
	public:
		Point();
		Point(const float x, const float y);
		Point&	operator=(const Point& point);
		~Point();
		const Fixed	toGetX(void) const;
		const Fixed	toGetY(void) const;
};

#endif