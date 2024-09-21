#include <stdlib.h>
#include "ClapTrap.hpp"

void	f(void)
{
	system("leaks open");
}
int	main(void)
{
	atexit(f);

	ClapTrap	A("A");
	ClapTrap	B("B");
	ClapTrap	C("C");

	A.attack("B");
	B.takeDamage(10);
	B.beRepaired(10);
	C.attack("A");
	A.takeDamage(5);
	A.beRepaired(10);
	for (int i = 0; i < 10; i++)
		A.attack("C");
	return (0);
}
