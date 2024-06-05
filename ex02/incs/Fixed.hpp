/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:26:38 by emimenza          #+#    #+#             */
/*   Updated: 2024/06/05 13:15:46 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int                 fixed_value; //numbr in the decimal format
		static const int    frac_bits = 8; //how many fractional bits
		int                 ft_roundf(float value) const;

	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &copy);

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat(void) const;
		int toInt(void) const;
		
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;
		
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int); 
		       
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
};
    std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr);

#endif