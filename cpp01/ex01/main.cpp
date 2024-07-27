#include <iostream>
#include "Zombie.hpp"

Zombie	*zombieHorde( int N, std::string name );

void	f(void)
{
	system("leaks Moar");
}

int	main(void)
{
	Zombie	*zombie_horde = zombieHorde(10, "zombie");

	atexit(f);
	for (int i = 0; i < 10; i++)
		zombie_horde[i].announce();
	delete[] zombie_horde;
	return (0);
}
