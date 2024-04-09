/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:41:37 by aallou-v          #+#    #+#             */
/*   Updated: 2024/04/09 13:38:21 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Fixed
{
private:
	int rawBits;
	static const int i = 8;
public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed(const int &fixed);
	Fixed(const float &fixed);
	~Fixed();
	Fixed & operator = (const Fixed &fixed);
	int getRawBits(void) const;
	void setRawBits(int const i);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream & operator << (std::ostream &os, const Fixed &fixed);

