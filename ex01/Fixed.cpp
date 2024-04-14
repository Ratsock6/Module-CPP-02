/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:41:39 by aallou-v          #+#    #+#             */
/*   Updated: 2024/04/09 13:43:32 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) {
    rawBits = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(int const &fixed):
	rawBits(fixed << i) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const &fixed):
	rawBits(roundf(fixed * (1 << this->i))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->rawBits = fixed.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->rawBits);
}

void Fixed::setRawBits(int const rawBits) {
	std::cout << "setRawBits member function called" << std::endl;
	this->rawBits = rawBits;
}


std::ostream & operator << (std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return (os);
}

float Fixed::toFloat(void) const {
	return ((float) this->rawBits / (1 << i));
}

int Fixed::toInt(void) const {
	return (this->rawBits >> i);
}