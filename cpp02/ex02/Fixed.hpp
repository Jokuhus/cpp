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
		~Fixed();
		Fixed&				operator=(const Fixed &fixed);
		bool				operator>(const Fixed &fixed) const;
		bool				operator<(const Fixed &fixed) const;
		bool				operator>=(const Fixed &fixed) const;
		bool				operator<=(const Fixed &fixed) const;
		bool				operator==(const Fixed &fixed) const;
		bool				operator!=(const Fixed &fixed) const;
		Fixed				operator+(const Fixed& fixed) const;
		Fixed				operator-(const Fixed& fixed) const;
		Fixed				operator*(const Fixed& fixed) const;
		Fixed				operator/(const Fixed& fixed) const;
		Fixed&				operator++(void);
		Fixed&				operator--(void);
		Fixed				operator++(int);
		Fixed				operator--(int);
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;
		static Fixed&		min(Fixed& left, Fixed& right);
		static const Fixed&	min(const Fixed& left, const Fixed& right);
		static Fixed&		max(Fixed& left, Fixed& right);
		static const Fixed&	max(const Fixed& left, const Fixed& right);
};

std::ostream&	operator<<(std::ostream &ofs, const Fixed &fixed);

#endif