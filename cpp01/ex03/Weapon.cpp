#include <string>
#include "Weapon.hpp"

Weapon::Weapon()
{
	this->type = "bare hands";
}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon()
{
}

const std::string	&Weapon::getType( void )
{
	return (this->type);
}

void	Weapon::setType( std::string new_type )
{
	this->type = new_type;
}
