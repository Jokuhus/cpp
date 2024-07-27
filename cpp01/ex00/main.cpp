#include <iostream>
#include "Zombie.hpp"

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );

int	main(void)
{
	Zombie	*heap;
	std::string stack("stack");

	std::cout << "------------------------------" << std::endl;
	std::cout << "create a zombie on heap memory" << std::endl;
	heap = newZombie("heap");
	heap->announce();
	delete heap;
	std::cout << "-------------------------------" << std::endl;
	std::cout << "create a zombie on stack memory" << std::endl;
	randomChump(stack);
	std::cout << "END" << std::endl;
	return (0);
}
