#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie::Zombie( void )
{
	this->name = "Default";
	std::cout << "class created" << std::endl;
}

Zombie::Zombie( std::string name )
{
	this->name = name;
}

Zombie::~Zombie( void )
{
	std::cout << this->name << ": destroyed" << std::endl;
}

void	Zombie::setName( std::string name )
{
	this->name = name;
}

void	Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
