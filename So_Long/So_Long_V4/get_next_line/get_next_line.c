/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:03:36 by vloddo            #+#    #+#             */
/*   Updated: 2025/01/13 13:03:41 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc_get(size_t num, size_t size)
{
	size_t	total_size;
	void	*ptr;

	total_size = num * size;
	if (num != 0 && total_size / num != size)
		return (NULL);
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_memset_get(ptr, 0, total_size);
	return (ptr);
}

void	*ft_memset_get(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = s;
	while (i < n)
	{
		p[i] = (unsigned char )c;
		i++;
	}
	return (s);
}

static char	*ft_line(char *buffer)
{
	int		i;
	char	*line;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc_get((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_read(int fd, char *buffer)
{
	char		*temp;
	char		*read_buffer;
	ssize_t		byte_read;

	read_buffer = malloc((BUFFER_SIZE + 1));
	if (!read_buffer)
		return (NULL);
	byte_read = read(fd, read_buffer, BUFFER_SIZE);
	if (byte_read < 0)
	{
		free(read_buffer);
		return (NULL);
	}
	if (byte_read == 0)
	{
		free(read_buffer);
		return (buffer);
	}
	read_buffer[byte_read] = '\0';
	temp = buffer;
	buffer = ft_strjoin_get(buffer, read_buffer);
	free(read_buffer);
	free (temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*temp;
	char		*prev_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	prev_buffer = NULL;
	while (!ft_newline(buffer) && prev_buffer != buffer)
	{
		prev_buffer = buffer;
		buffer = ft_read(fd, buffer);
	}
	line = ft_line(buffer);
	temp = buffer;
	buffer = ft_substr_get(buffer, ft_strlen_get(line), \
	ft_strlen_get(buffer) - ft_strlen_get(line));
	free(temp);
	return (line);
}


