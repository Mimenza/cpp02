/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:26:40 by emimenza          #+#    #+#             */
/*   Updated: 2024/06/05 13:28:41 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fixed.hpp"


int Fixed::ft_roundf(float value) const
{
    return (int)(value + 0.5f);
}
        
Fixed::Fixed() : fixed_value(0)
{
   // std::cout << "Default constructor" << std::endl;
}

Fixed::Fixed(const int value)
{
    //std::cout << "Int constructor called" << std::endl; 
    this->fixed_value = value << frac_bits;
}

Fixed::Fixed(const float value)
{
    //std::cout << "Float constructor called" << std::endl; 
    this->fixed_value = ft_roundf(value * (1 << frac_bits));
}

Fixed::~Fixed()
{
   // std::cout << "Destructor called" << std::endl; 
}

Fixed::Fixed(const Fixed &copy)
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
    //std::cout << "Copy assigment operator called" << std::endl;
    if (this != &copy)
    {
        this->fixed_value = copy.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits() const
{
    return this->fixed_value;
}

void Fixed::setRawBits(int const raw)
{
    this->fixed_value = raw;
}

float Fixed::toFloat() const
{
    return static_cast<float>(this->fixed_value) / (1 << frac_bits);
}

int Fixed::toInt() const
{
    return this->fixed_value >> frac_bits;
}

std::ostream &operator<<(std::ostream &str, Fixed const &fixed_nbr)
{
    str << fixed_nbr.toFloat();
    return str;
}

bool Fixed::operator>(const Fixed &other) const
{
    return this->fixed_value > other.fixed_value;
}

bool Fixed::operator<(const Fixed &other) const
{
    return this->fixed_value < other.fixed_value;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->fixed_value >= other.fixed_value;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->fixed_value <= other.fixed_value;
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->fixed_value == other.fixed_value;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->fixed_value != other.fixed_value;
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    
    result  =  this->toFloat() + other.toFloat();
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    
    result  =  this->toFloat() - other.toFloat();
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;

    result  =  this->toFloat() * other.toFloat();
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;
    
    result  =  this->toFloat() / other.toFloat();
    return result;
}

Fixed &Fixed::operator++()
{
    this->fixed_value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->fixed_value++;
    return temp;
}

Fixed &Fixed::operator--()
{
    this->fixed_value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->fixed_value--;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}
