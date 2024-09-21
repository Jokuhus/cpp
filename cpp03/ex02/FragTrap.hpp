#ifndef _FRAGTRAP_HPP_
# define _FRAGTRAP_HPP_

# include <string>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		virtual	~FragTrap();
		FragTrap(const FragTrap& obj);
		FragTrap&		operator=(const FragTrap& obj);
		void			highFivesGuys();
};

#endif
