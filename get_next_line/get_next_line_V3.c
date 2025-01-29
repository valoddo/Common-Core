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

char	*ft_substr(char *buffer, int lenline, int lenbuffer)
{
	char *final;
	int	i;

	final = malloc(sizeof(char) * (lenbuffer + 1));
	if (!final)
		return (NULL);
	i = 0;
	while(lenbuffer > 0)
	{
		final[i] = buffer[lenline + i];
		i++;
		lenbuffer--;
	}
	final[i + 1] = '\0';
	return (final);
}

char	*ft_strjoin(char *buffer, char *read_buffer)
{
	char	*final;
	int		i;
	int		j;

	i = ft_strlen(buffer);
	j = ft_strlen(read_buffer);
	final = malloc(sizeof(char) * (i + j + 1));
	if (!final)
		return(NULL);
	final[i + j] = '\0';
	while (j > 0)
	{
		j--;
		final[i + j] = read_buffer[j];
	}
	while (i > 0)
	{
		i--;
		final[i] = buffer[i];
	}
	return	(final);
}


int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
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
	temp = buffer; // Alias: puntatore che punta alla stessa area di memoria di buffer e serve per liberare l'area di memoria di buffer alla fine
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
	buffer = ft_read(fd, buffer); // Legge i dati nel buffer e li aggiunge al buffer letto prima
	// if (!buffer)
	// 	return (NULL);
	temp = buffer; // Aggiorna il buffer con i dati rimanenti
	line = ft_line(buffer); // Estrai la linea dal buffer
	buffer = ft_substr(buffer, ft_strlen(line), ft_strlen(buffer) - ft_strlen(line));
	free(temp);
	return (line);
}
// int main()
// {
// 	char *str;
// 	char *str2;
// 	char *str3;
// 	char *str4;
// 	char *final;
	
// 	str = "ciao";
// 	str2 = "a tutti";
// 	str3 = "ciao\na tutti";
// 	str4 = "ciao a tutti";
// 	final = ft_line(str4);
// 	printf("%s", final);
// 	return(0);
// }


// int	main(void)
// {
// 	int		fd;
// 	char	*text;

// 	fd = open("example.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error");
// 		return (1);
// 	}
// 	text = get_next_line(fd);
// 	while (text)
// 	{
// 		printf("%s", text);
// 		free(text);
// 		text = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }
