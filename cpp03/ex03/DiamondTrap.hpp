#ifndef _DIAMONDTRAP_HPP_
# define _DIAMONDTRAP_HPP_

# include <string>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	Name;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		virtual	~DiamondTrap();
		DiamondTrap(const DiamondTrap& obj);
		DiamondTrap&	operator=(const DiamondTrap& obj);
		void			whoAmI();
};

#endif
