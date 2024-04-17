/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:41:39 by aallou-v          #+#    #+#             */
/*   Updated: 2024/04/16 10:53:44 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) {
    rawBits = 0;
}

Fixed::~Fixed(void) {}

Fixed::Fixed(const Fixed &fixed) {
	*this = fixed;
}

Fixed::Fixed(int const &fixed):
	rawBits(fixed << i) {
}

Fixed::Fixed(float const &fixed):
	rawBits(roundf(fixed * (1 << this->i))) {
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	this->rawBits = fixed.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const {
	return (this->rawBits);
}

void Fixed::setRawBits(int const rawBits) {
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

bool Fixed::operator>(const Fixed &fixed) const {
	return (this->rawBits > fixed.getRawBits());
}

bool Fixed::operator<(const Fixed &fixed) const {
	return (this->rawBits < fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed) const {
	return (this->rawBits >= fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed) const {
	return (this->rawBits <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed &fixed) const {
	return (this->rawBits == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixed) const {
	return (this->rawBits != fixed.getRawBits());
}

Fixed Fixed::operator+(const Fixed &fixed) const {
	Fixed tmp;
	tmp.setRawBits(this->getRawBits() + fixed.getRawBits());
	return (tmp);
}

Fixed Fixed::operator-(const Fixed &fixed) const {
	Fixed tmp;
	tmp.setRawBits(this->getRawBits() - fixed.getRawBits());
	return (tmp);
}

Fixed Fixed::operator*(const Fixed &fixed) const {
	Fixed tmp;
	tmp.setRawBits((this->getRawBits() * fixed.getRawBits()) / (1 << i));
	return (tmp);
}

Fixed Fixed::operator/(const Fixed &fixed) const {
	Fixed tmp;
	tmp.setRawBits((this->getRawBits() / fixed.getRawBits()) * (1 << i));
	return (tmp);
}

Fixed &Fixed::operator++(void) {
	this->rawBits++;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed tmp = *this;
	this->rawBits++;
	return (tmp);
}

Fixed &Fixed::operator--(void) {
	this->rawBits--;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed tmp = *this;
	this->rawBits--;
	return (tmp);
}

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2) {
	if (fixed1 < fixed2)
		return (fixed1);
	return (fixed2);
}

const Fixed &Fixed::min(const Fixed &fixed1, const Fixed &fixed2) {
	if (fixed1 < fixed2)
		return (fixed1);
	return (fixed2);
}

Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2) {
	if (fixed1 > fixed2)
		return (fixed1);
	return (fixed2);
}

const Fixed &Fixed::max(const Fixed &fixed1, const Fixed &fixed2) {
	if (fixed1 > fixed2)
		return (fixed1);
	return (fixed2);
}

