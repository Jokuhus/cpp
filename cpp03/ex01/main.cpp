#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	S("S");
	ClapTrap	C("C");

	C.attack("B");
	S.attack("B");
	S.guardGate();
	return (0);
}
