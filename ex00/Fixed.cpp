/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:42:56 by carbon-m          #+#    #+#             */
/*   Updated: 2025/11/25 23:14:49 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed (void)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed (const Fixed &newFixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = newFixed;
}

Fixed &Fixed::operator = (const Fixed &otherFixed)
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