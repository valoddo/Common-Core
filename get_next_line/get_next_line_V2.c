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

//#include "get_next_line.h"

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL)
	while(str[i])
		i++;
	return (i);
}

static char	*ft_line(char *buffer)
{
	int		i;
	char	*line;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n') // Conta i caratteri fino a \n o fine del buffer
		i++;
	line = malloc(sizeof(char) * (i + 2)); // Alloca memoria per la linea (+1 per \n e +1 per terminatore \0)
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n') // Copia i caratteri nella nuova linea
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n') 	// Aggiungi il \n se presente
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0'; // Termina la stringa
	return (line);
}


static char	*ft_read(int fd, char *buffer)
{
	char		*temp;
	char		*read_buffer;
	ssize_t		byte_read;

	read_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buffer)
		return (NULL);
	byte_read = read(fd, read_buffer, BUFFER_SIZE);
	if (byte_read < 0)
	{
		free(read_buffer);
		return (NULL);
	}
	read_buffer[byte_read] = '\0'; // Termina la stringa
	temp = buffer; // Concatena il vecchio buffer con il nuovo
	buffer = ft_strjoin(buffer, read_buffer);
	free(temp);
	free(read_buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(fd, buffer); // Legge i dati nel buffer finché non trova un \n
	if (!buffer)
		return (NULL);
	line = ft_line(buffer); // Estrai la linea dal buffer
	temp = buffer; // Aggiorna il buffer con i dati rimanenti
	buffer = ft_substr(buffer, ft_strlen(line), ft_strlen(buffer) - ft_strlen(line));
	free(temp);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*text;

	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		return (1);
	}
	text = get_next_line(fd);
	while (text)
	{
		printf("%s", text);
		free(text);
		text = get_next_line(fd);
	}
	close(fd);
	return (0);
}
