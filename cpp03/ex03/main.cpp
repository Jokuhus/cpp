#include <iostream>
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	D("D");

	D.attack("A");
	D.takeDamage(10);
	D.beRepaired(10);
	D.guardGate();
	D.highFivesGuys();
	D.whoAmI();
	return (0);
}
