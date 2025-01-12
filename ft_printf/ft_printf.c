/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:34:56 by vloddo            #+#    #+#             */
/*   Updated: 2025/01/09 15:35:00 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printarg(const char *str, va_list arg)
{
	int	i;

	i = 0;
	if (*str == 'c')
		i += ft_print_char(va_arg(arg, int));
	else if (*str == 's')
		i += ft_print_str(va_arg(arg, char *));
	else if (*str == 'p')
		i += ft_print_pointer(va_arg(arg, unsigned long));
	else if (*str == 'd' || *str == 'i')
		i += ft_print_int(va_arg(arg, int));
	else if (*str == 'u')
		i += ft_print_intunsign(va_arg(arg, unsigned int));
	else if (*str == 'x' || *str == 'X')
		i += ft_print_hexa(*str, va_arg(arg, unsigned int));
	else if (*str == '%')
	{
		write(1, "%", 1);
		i++;
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;

	va_start(arg, str);
	i = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			i += ft_printarg(str, arg);
		}
		else
		{
			write(1, str, 1);
			i++;
		}
		str++;
	}
	va_end(arg);
	return (i);
}

// int	 main()
// {
// 	ft_printf(" NULL %s NULL ", NULL);
// 	printf(" NULL %s NULL ", NULL);
// 	return(0);
// }
