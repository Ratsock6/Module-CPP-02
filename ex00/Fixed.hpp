/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:41:37 by aallou-v          #+#    #+#             */
/*   Updated: 2024/04/09 13:15:59 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>


class Fixed
{
private:
	int 				rawBits;
	static const int	i = 8;
public:
	Fixed();
	Fixed(const Fixed &fixed);
	~Fixed();
	Fixed & operator = (const Fixed &fixed);
	int getRawBits(void) const;
	void setRawBits(int const i);
};
