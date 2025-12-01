/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:53:10 by carbon-m          #+#    #+#             */
/*   Updated: 2025/12/01 19:17:30 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public :
		Fixed ();
		Fixed (const int ivalue);
		Fixed (const float fvalue);
		Fixed (const Fixed &newFixed);
		Fixed &operator= (const Fixed &otherFixed);
		~Fixed ();
		
		int				getRawBits(void) const;
		void			setRawBits(int const raw);
		float 			toFloat( void ) const;
		int 			toInt( void ) const;
		static			Fixed &min(Fixed &a, Fixed &b);
		static const 	Fixed &min(const Fixed &a, const Fixed &b);
		static			Fixed &max(Fixed &a, Fixed &b);
		static const 	Fixed &max(const Fixed &a, const Fixed &b);
		Fixed			&operator++();
		Fixed			operator++(int);
		Fixed			&operator--();
		Fixed			operator--(int);

	private :
		int					value;
		static const int	bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
bool operator<(const Fixed &a, const Fixed &b);
bool operator>(const Fixed &a, const Fixed &b);
bool operator<=(const Fixed &a, const Fixed &b);
bool operator>=(const Fixed &a, const Fixed &b);
bool operator==(const Fixed &a, const Fixed &b);
bool operator!=(const Fixed &a, const Fixed &b);
Fixed operator+(const Fixed &a, const Fixed &b);
Fixed operator-(const Fixed &a, const Fixed &b);
Fixed operator*(const Fixed &a, const Fixed &b);
Fixed operator/(const Fixed &a, const Fixed &b);

#endif