#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "Default constructor of FragTrap called" << std::endl;
	this->HitPoint = 100;
	this->EnergyPoint = 100;
	this->AttackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "name parameter constructor of FrapTrap called" << std::endl;
	this->HitPoint = 100;
	this->EnergyPoint = 100;
	this->AttackDamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor of FragTrap called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& obj): ClapTrap(obj.Name)
{
	std::cout << "Copy constructor of FragTrap called" << std::endl;
	this->HitPoint = obj.HitPoint;
	this->EnergyPoint = obj.EnergyPoint;
	this->AttackDamage = obj.AttackDamage;
}

FragTrap&	FragTrap::operator=(const FragTrap& obj)
{
	std::cout << "Copy assignment operator of FragTrap called" << std::endl;
	if (this != &obj)
	{
		this->Name = obj.Name;
		this->HitPoint = obj.HitPoint;
		this->EnergyPoint = obj.EnergyPoint;
		this->AttackDamage = obj.AttackDamage;
	}
	return (*this);
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->Name << " is asking for a positive high fives" << std::endl;
}
