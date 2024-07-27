#include "ClapTrap.hpp"

int	main(void)
{
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
