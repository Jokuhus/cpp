#include <iostream>
#include <string>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "Default constructor of ScavTrap called" << std::endl;
	this->HitPoint = 100;
	this->EnergyPoint = 50;
	this->AttackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "name parameter constructor of ScavTrap called" << std::endl;
	this->HitPoint = 100;
	this->EnergyPoint = 50;
	this->AttackDamage = 20;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor of ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj): ClapTrap(obj.Name)
{
	std::cout << "Copy constructor of ScavTrap called" << std::endl;
	this->HitPoint = obj.HitPoint;
	this->EnergyPoint = obj.EnergyPoint;
	this->AttackDamage = obj.AttackDamage;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& obj)
{
	std::cout << "Copy assignment operator of ScavTrap called" << std::endl;
	if (this != &obj)
	{
		this->Name = obj.Name;
		this->HitPoint = obj.HitPoint;
		this->EnergyPoint = obj.EnergyPoint;
		this->AttackDamage = obj.AttackDamage;
	}
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->HitPoint > 0 && this->EnergyPoint > 0)
	{
		this->EnergyPoint -= 1;
		std::cout << "ScavTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->Name << " can't do anything" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->Name << " is now in Gate keeper mode" << std::endl;
}
