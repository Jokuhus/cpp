#ifndef _FIXED_HPP_
# define _FIXED_HPP_

class Fixed
{
	private:
		int					numberValue;
		static const int	FractionalBit = 8;
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed& operator=(const Fixed &fixed);
		~Fixed();
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif