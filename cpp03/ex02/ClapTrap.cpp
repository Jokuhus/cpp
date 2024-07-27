#include <iostream>
#include <string>
#include <limits>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Name("Default"), HitPoint(10), EnergyPoint(10), AttackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :  Name(name), HitPoint(10), EnergyPoint(10), AttackDamage(0)
{
	std::cout << "name parameter constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	std::cout << "Copy constructor called" << std::endl;
	this->Name = obj.Name;
	this->HitPoint = obj.HitPoint;
	this->EnergyPoint = obj.EnergyPoint;
	this->AttackDamage = obj.AttackDamage;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->Name = obj.Name;
		this->HitPoint = obj.HitPoint;
		this->EnergyPoint = obj.EnergyPoint;
		this->AttackDamage = obj.AttackDamage;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->HitPoint > 0 && this->EnergyPoint > 0)
	{
		this->EnergyPoint -= 1;
		std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->Name << " can't do anything" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->HitPoint > amount)
		this->HitPoint -= amount;
	else
		this->HitPoint = 0;
	std::cout << "ClapTrap " << this->Name << " gets " << amount << " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->HitPoint > 0 && this->EnergyPoint > 0)
	{
		this->EnergyPoint -= 1;
		if (this->HitPoint + amount >= this->HitPoint)
		{
			this->HitPoint += amount;
			std::cout << "ClapTrap " << this->Name << " is repaired by " << amount << " points!" << std::endl;
		}
		else
		{
			std::cout << "ClapTrap " << this->Name << " is repaired by " << (std::numeric_limits<unsigned int>::max() - this->HitPoint) << " points!" << std::endl;
			this->HitPoint = std::numeric_limits<unsigned int>::max();
		}
	}
	else
		std::cout << "ClapTrap " << this->Name << " can't do anything" << std::endl;
}
