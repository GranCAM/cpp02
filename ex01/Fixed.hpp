/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:53:10 by carbon-m          #+#    #+#             */
/*   Updated: 2025/12/01 16:53:02 by carbon-m         ###   ########.fr       */
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
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float 	toFloat( void ) const;
		int 	toInt( void ) const;
		
	private :
		int					value;
		static const int	bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif