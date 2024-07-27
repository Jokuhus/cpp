#include <iostream>
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

void	checkIfInside(float ax, float ay, float bx, float by, float cx, float cy, float px, float py)
{
	Point	a(ax,ay);
	Point	b(bx,by);
	Point	c(cx,cy);
	Point	point(px,py);

	std::cout << "\nPoint : " 
			  << "(" << point.toGetX() << ", " << point.toGetY() << ") "
			  << "\nTriangle : " 
			  << "(" << a.toGetX() << ", " << a.toGetY() << ") "
			  << "(" << b.toGetX() << ", " << b.toGetY() << ") "
			  << "(" << c.toGetX() << ", " << c.toGetY() << ") "
			  << "\nResult : ";
	if (bsp(a, b, c, point))
		std::cout << "\033[32minside\033[0m" << std::endl;
	else
		std::cout << "\033[31moutside\033[0m" << std::endl;
}

int	main(void)
{
	checkIfInside(0,0,10,10,20,20,3,3);
	checkIfInside(0,0,-10,-10,-20,-20,-3,-3);
	checkIfInside(12.12f,1.1f,-20.20f,5.5f,7.7f,7.7f,3.3f,4.4f);
	checkIfInside(1,0,10,0,20,0,3,3);
	checkIfInside(-1,-10,10,100,-20,200,-3,33);
	checkIfInside(1,1,10,10,-20,20,3,-33);

	return (0);
}