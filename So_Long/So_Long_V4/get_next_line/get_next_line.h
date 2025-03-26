/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:04:13 by vloddo            #+#    #+#             */
/*   Updated: 2025/01/13 13:04:16 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		ft_newline(char *buffer);
char	*ft_substr_get(char *buffer, int lenline, int lenbuffer);
char	*ft_strjoin_get(char *buffer, char *read_buffer);
int		ft_strlen_get(char *str);
void	*ft_calloc_get(size_t num, size_t size);
void	*ft_memset_get(void *s, int c, size_t n);

#endif
