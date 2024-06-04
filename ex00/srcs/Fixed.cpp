/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:03:10 by emimenza          #+#    #+#             */
/*   Updated: 2024/06/04 13:48:45 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fixed.hpp"

Fixed::Fixed(void): fixed_value(0)
{
    std::cout << "Fixed object created with default constructor" << std::endl;
}

Fixed::~Fixed(void)
{
    std::cout << "Fixed object destroyed" << std::endl; 
}

Fixed::Fixed(Fixed const &copy)
{
    std::cout << "Fixed object copied" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(Fixed const &copy)
{
    std::cout << "Assignment operator called" << std::endl;
	this->fixed_value = copy.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_value);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "settRawBits member function called" << std::endl;
    this->fixed_value = raw;
}