/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:24:08 by aallou-v          #+#    #+#             */
/*   Updated: 2024/04/16 10:52:51 by aallou-v         ###   ########.fr       */
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

	Fixed			&operator = (const Fixed &fixed);
	int				getRawBits(void) const;
	void			setRawBits(int const i);
	float			toFloat(void) const;
	int				toInt(void) const;


	bool			operator>(const Fixed &fixed) const;
	bool			operator<(const Fixed &fixed) const;
	bool			operator>=(const Fixed &fixed) const;
	bool			operator<=(const Fixed &fixed) const;
	bool			operator==(const Fixed &fixed) const;
	bool			operator!=(const Fixed &fixed) const;

	Fixed			operator+(const Fixed &fixed) const;
	Fixed			operator-(const Fixed &fixed) const;
	Fixed			operator*(const Fixed &fixed) const;
	Fixed			operator/(const Fixed &fixed) const;

	Fixed			operator++(int);
	Fixed			operator--(int);
	Fixed			&operator++(void);
	Fixed			&operator--(void);

	static			Fixed &min(Fixed &fixed1, Fixed &fixed2);
	static const	Fixed &min(const Fixed &fixed1, const Fixed &fixed2);
	static			Fixed &max(Fixed &fixed1, Fixed &fixed2);
	static const	Fixed &max(const Fixed &fixed1, const Fixed &fixed2);
};

std::ostream & operator << (std::ostream &os, const Fixed &fixed);
