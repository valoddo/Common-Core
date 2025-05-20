/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:23:58 by vloddo            #+#    #+#             */
/*   Updated: 2025/05/15 17:09:16 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>

int			ft_print_char(int c);
int			ft_print_str(char *s);
int			ft_print_pointer(unsigned long p);
int			ft_print_int(int di);
int			ft_print_intunsign(unsigned int u);
int			ft_print_hexa(char str, unsigned int x);
int			ft_printf(const char *str, ...);

#endif
