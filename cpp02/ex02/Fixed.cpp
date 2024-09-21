#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(void) : numberValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int number) : numberValue(number << Fixed::FractionalBit)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number) 
: numberValue(static_cast<int>(roundf(number * (1 << Fixed::FractionalBit))))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &fixed)
		return (*this);
	this->numberValue = fixed.getRawBits();

	return (*this);
}

bool	Fixed::operator>(const Fixed &fixed) const
{
	return (this->numberValue > fixed.numberValue);
}

bool	Fixed::operator<(const Fixed &fixed) const
{
	return (this->numberValue < fixed.numberValue);
}

bool	Fixed::operator>=(const Fixed &fixed) const
{
	return (this->numberValue >= fixed.numberValue);
}

bool	Fixed::operator<=(const Fixed &fixed) const
{
	return (this->numberValue <= fixed.numberValue);
}

bool	Fixed::operator==(const Fixed &fixed) const
{
	return (this->numberValue == fixed.numberValue);
}

bool	Fixed::operator!=(const Fixed &fixed) const
{
	return (this->numberValue != fixed.numberValue);
}

Fixed	Fixed::operator+(const Fixed& fixed) const
{
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed	Fixed::operator-(const Fixed& fixed) const
{
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed	Fixed::operator*(const Fixed& fixed) const
{
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed	Fixed::operator/(const Fixed& fixed) const
{
	return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed&	Fixed::operator++(void)
{
	this->numberValue++;
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	this->numberValue--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temporary(this->toFloat());
	this->numberValue++;
	return (temporary);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temporary(this->toFloat());
	this->numberValue--;
	return (temporary);
}

std::ostream&	operator<<(std::ostream &ofs, const Fixed &fixed)
{
	return (ofs << fixed.toFloat());
}

int	Fixed::getRawBits(void) const
{
	return (this->numberValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->numberValue = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->numberValue) / (1 << Fixed::FractionalBit));
}

int	Fixed::toInt(void) const
{
	return (this->numberValue >> Fixed::FractionalBit);
}

Fixed&	Fixed::min(Fixed& left, Fixed& right)
{
	if (left < right)
		return (left);
	else
		return (right);
}

const Fixed&	Fixed::min(const Fixed& left, const Fixed& right)
{
	if (left < right)
		return (left);
	else
		return (right);
}

Fixed&	Fixed::max(Fixed& left, Fixed& right)
{
	if (left > right)
		return (left);
	else
		return (right);
}

const Fixed&	Fixed::max(const Fixed& left, const Fixed& right)
{
	if (left > right)
		return (left);
	else
		return (right);
}