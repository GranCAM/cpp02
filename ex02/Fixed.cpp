/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:51:51 by carbon-m          #+#    #+#             */
/*   Updated: 2025/12/01 19:15:15 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//CONSTRUCTORES Y DESTRUCTOR

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


//METODOS

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

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.value < b.value)
		return (a);
	else
		return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.value < b.value)
		return (a);
	else
		return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.value > b.value)
		return (a);
	else
		return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.value > b.value)
		return (a);
	else
		return (b);
}


//OPERADORES COMPARACION

bool operator<(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return true;
	else
		return false;
}

bool operator>(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return true;
	else
		return false;
}		
		
bool operator<=(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() <= b.getRawBits())
		return true;
	else
		return false;
}

bool operator>=(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() >= b.getRawBits())
		return true;
	else
		return false;
}


bool operator==(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() == b.getRawBits())
		return true;
	else
		return false;
}

bool operator!=(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() != b.getRawBits())
		return true;
	else
		return false;
}


//OPERADORES ARITMETICOS

Fixed operator+(const Fixed &a, const Fixed &b)
{
	Fixed c;
	c.setRawBits(a.getRawBits() + b.getRawBits());
	return c;
}

Fixed operator-(const Fixed &a, const Fixed &b)
{
	Fixed c;
	c.setRawBits(a.getRawBits() - b.getRawBits());
	return c;
}

Fixed operator*(const Fixed &a, const Fixed &b)
{
	Fixed c;
	long temp = (long)a.getRawBits() * b.getRawBits();
	c.setRawBits(temp >> 8);
	return c;
}

Fixed operator/(const Fixed &a, const Fixed &b)
{
	Fixed c;
	long temp = (a.getRawBits() << 8 / b.getRawBits());
	c.setRawBits(temp);
	return c;
}



Fixed &Fixed::operator++()
{
	this->value += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed c(*this);
	this->value += 1;
	return c;
}

Fixed &Fixed::operator--()
{
	this->value -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed c(*this);
	this->value -= 1;
	return c;
}




std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}