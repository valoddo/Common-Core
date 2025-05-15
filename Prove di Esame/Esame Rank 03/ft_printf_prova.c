/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prova.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:47:54 by vloddo            #+#    #+#             */
/*   Updated: 2025/05/15 11:18:47 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int ft_putstr(char *s)
{
    int i;

    i = 0;
    if (!s)
        return(write(1, "(null)", 6), 6);
    while (s[i])
    {
        write(1, &s[i], 1);
        i++;
    }
    return(i);
}

int ft_putnbr(int d)
{
    int i;
    int j;

    i = 0;
    if (d == -2147483648)
        return(write(1, "-2147483648", 11), 11);
    if (d < 0)
    {
        write(1, "-", 1);
        d = d * -1;
        i++;
    }
    j = 1;
    while (d / j > 9)
        j*= 10;
    while (j > 0)
    {
        write(1, &"0123456789"[d / j], 1);
        d %= j;
        j /= 10;
        i++;
    }
    return(i);
}

int ft_putnbr_hex(unsigned int x)
{
    int i;
    int j;

    i = 0;
    j = 1;
    while (x / j > 15)
        j*= 16;
    while (j > 0)
    {
        write(1, &"0123456789abcdef"[x / j], 1);
        x %= j;
        j /= 16;
        i++;
    }
    return(i);
}

int ft_printf(const char *fmt, ...)
{
           va_list ap;
           int i;
           int d;
           unsigned int x;
           char *s;

           va_start(ap, fmt);
           i = 0;
           while (*fmt)
           {
            if(*fmt == '%')
            {
                fmt++;
                if(*fmt == 's')
                {
                    s = va_arg(ap, char *);
                    i+= ft_putstr(s);
                }
                else if(*fmt == 'd')
                {
                    d = va_arg(ap, int);
                    i+= ft_putnbr(d);  
                }
                else if(*fmt == 'x')
                {
                    x = va_arg(ap, unsigned int);
                    i+= ft_putnbr_hex(x);
                }
            }
            else
            {
                write(1, fmt, 1);
                i++;
            }
            fmt++;
        }
        va_end(ap);
        return(i);
}

int main()
{
    ft_printf("Hello %s\n", "world");
    ft_printf("Number: %d\n", 123);
    ft_printf("Hex: %x\n", 255);
    ft_printf("Null string: %s\n", (char *)0);
    return 0;
}

