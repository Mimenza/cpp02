/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:58:01 by emimenza          #+#    #+#             */
/*   Updated: 2024/06/03 14:32:19 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed 
{
    private:
        int                 fixed_value;
        static const int    frac_bits;

    public:
        Fixed();
        ~Fixed();
        Fixed(Fixed const &copy);
        Fixed	&operator=(Fixed const &copy);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif