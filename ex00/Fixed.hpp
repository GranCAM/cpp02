/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:42:59 by carbon-m          #+#    #+#             */
/*   Updated: 2025/11/25 22:55:36 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public :
		Fixed (void);
		Fixed (const Fixed &newFixed);
		Fixed &operator = (const Fixed &otherFixed);
		~Fixed (void);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		
	private :
		int					value;
		static const int	bits = 8;
};

#endif