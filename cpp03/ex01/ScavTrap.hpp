#ifndef _SCAVTRAP_HPP_
# define _SCAVTRAP_HPP_

# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string name);
	virtual ~ScavTrap();
	ScavTrap(const ScavTrap& obj);
	ScavTrap&		operator=(const ScavTrap& obj);
	virtual void	attack(const std::string& target);
	void			guardGate();
};

#endif
