/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:51:51 by carbon-m          #+#    #+#             */
/*   Updated: 2025/12/01 16:52:45 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed (void) : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed (const int ivalue) : value(ivalue << bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed (const float fvalue) : value (roundf(fvalue * (1 << bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed (const Fixed &newFixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = newFixed;
}

Fixed &Fixed::operator= (const Fixed &otherFixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = otherFixed.value;
	return *this;
}

Fixed::~Fixed (void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits (void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

float Fixed::toFloat( void ) const
{
	float f = static_cast<float>(value) / (1 << bits);
	return f;
}

int Fixed::toInt( void ) const
{
	return value >> bits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}