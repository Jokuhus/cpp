#ifndef _FIXED_HPP_
# define _FIXED_HPP_

# include <iostream>

class Fixed
{
	private:
		int					numberValue;
		static const int	FractionalBit = 8;
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed(const int number);
		Fixed(const float number);
		Fixed& operator=(const Fixed &fixed);
		~Fixed();
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream&	operator<<(std::ostream &ofs, const Fixed &fixed);

#endif