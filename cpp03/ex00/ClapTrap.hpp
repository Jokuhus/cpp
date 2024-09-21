#ifndef _CLAPTRAP_HPP_
# define _CLAPTRAP_HPP_

# include <string>

class ClapTrap
{
    private:
        std::string		Name;
        unsigned int	HitPoint;
        unsigned int	EnergyPoint;
        unsigned int	AttackDamage;
    public:
		ClapTrap();
		ClapTrap(std::string name);
        ~ClapTrap();
        ClapTrap(const ClapTrap& obj);
        ClapTrap&	operator=(const ClapTrap& obj);
        void		attack(const std::string& target);
        void		takeDamage(unsigned int amount);
        void		beRepaired(unsigned int amount);
};

#endif
