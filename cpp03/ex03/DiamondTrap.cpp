#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): Name(ClapTrap::Name)
{
	std::cout << "Default constructor of DiamondTrap called" << std::endl;
	ClapTrap::Name = this->Name + "_clap_name";
	this->EnergyPoint = 50;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), ScavTrap(name), FragTrap(name), Name(ClapTrap::Name)
{
	std::cout << "name parameter constructor of DiamondTrap called" << std::endl;
	ClapTrap::Name = this->Name + "_clap_name";
	this->EnergyPoint = 50;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor of DiamondTrap called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj): ClapTrap(obj), ScavTrap(obj), FragTrap(obj), Name(obj.Name)
{
	std::cout << "Copy constructor of DiamondTrap called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& obj)
{
	std::cout << "Copy assignment operator of DiamondTrap called" << std::endl;
	if (this != &obj)
	{
		this->Name = obj.Name;
		ClapTrap::Name = this->Name + "_clap_name";
		this->HitPoint = obj.HitPoint;
		this->EnergyPoint = obj.EnergyPoint;
		this->AttackDamage = obj.AttackDamage;
	}
	return (*this);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "name: " << this->Name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::Name << std::endl;
}
