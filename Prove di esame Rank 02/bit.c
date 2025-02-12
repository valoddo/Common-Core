/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:17:58 by vloddo            #+#    #+#             */
/*   Updated: 2025/02/12 15:18:00 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void print_bits(unsigned char octet)
{
        int i;
        unsigned char bit;
        
        i = 8;
        while (i--)
        {
                bit = (octet >> i & 1) + 48;
                write(1, &bit, 1);
        } 

}

unsigned char reverse_bits(unsigned char octet)
{
        int i;
        unsigned char bit;
        
        i = 8;
        while (i--)
        {
                bit = (bit << 1) | (octet & 1);
                octet = octet >> 1;
        }
        return(bit);
}

unsigned char swap_bits(unsigned char octet)
{
        return ((octet >> 4) | (octet << 4));
}

#include <stdio.h>
int main()
{
        unsigned char octet;
        octet = 2;
        print_bits(octet);
        write(1, "\n", 1);
        print_bits(reverse_bits(octet));
        write(1, "\n", 1);
        print_bits(swap_bits(octet));
        return(0);
}
