/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:17:38 by bpalchet          #+#    #+#             */
/*   Updated: 2024/12/22 16:17:48 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>

void			*ft_calloc(size_t nmemb, size_t size);
void			*ft_memset(void *str, int value, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strchr(const char *str, int c);
char			*get_next_line(int fd);

#endif
